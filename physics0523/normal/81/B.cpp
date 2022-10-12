#include<stdio.h>
#include<string.h>

int main(){
  char s[1024];
  char t[1024];
  gets(s);
  int l=strlen(s);
  //printf("%d\n",l);

  int sp=-1;
  int tp=0;
  for(int i=0;i<l;i++){
    if(s[i]==','){
      sp=0;
      if(i==l-1){
        t[tp]=',';tp++;
      }
      else{
        t[tp]=',';tp++;
        t[tp]=' ';tp++;
      }
    }
    else if(s[i]=='.'){
      sp=0;
      if(i==0){
        t[tp]='.';tp++;
        t[tp]='.';tp++;
        t[tp]='.';tp++;
      }
      else{
        t[tp]=' ';tp++;
        t[tp]='.';tp++;
        t[tp]='.';tp++;
        t[tp]='.';tp++;
      }
      i+=2;
    }
    else if(s[i]==' '){
      if(sp==-1){sp=1;}
    }
    else{
      if(sp==1){t[tp]=' ';tp++;}
      sp=-1;
      t[tp]=s[i];tp++;
    }
  }
  t[tp]=0;
  for(int i=0;i<tp;i++){
    if(t[i]==' ' && t[i+1]==' '){continue;}
    printf("%c",t[i]);
  }
  return 0;
}