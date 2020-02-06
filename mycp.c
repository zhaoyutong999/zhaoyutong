
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>
int main(int argc,char* argv[])
{ int fd1,fd2;
  char buf[1024];
  int rr;
  fd1=open(argv[1],O_RDONLY);
  if(fd1<0)
  {
   perror("open argv1 error");
   exit(1);
  }
  fd2=open(argv[2],O_RDWR | O_TRUNC | O_CREAT, 0644);
  if(fd2<0)
  {
   perror("open argv2 error");
   exit(1);
  }
 while((rr=read(fd1,buf,1))!=0)
 {
  write(fd2,buf,rr);
 } 
  return 0;
}

