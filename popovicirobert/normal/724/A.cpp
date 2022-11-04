#include <cstdio>
int v[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char a;
inline int cauta(){
   int nr1;
   a=fgetc(stdin);
   if(a=='m')
      nr1=0;
   if(a=='t'){
      a=fgetc(stdin);
      if(a=='u')
         nr1=1;
      else
         nr1=3;
   }
   if(a=='w')
      nr1=2;
   if(a=='f')
      nr1=4;
   if(a=='s'){
      a=fgetc(stdin);
      if(a=='a')
          nr1=5;
      else
          nr1=6;
   }
   while(a!='\n')
      a=fgetc(stdin);
   return nr1;
}
int main(){
   int nr1,nr2,flag,i;
   nr1=cauta();
   nr2=cauta();
   flag=0;
   for(i=0;i<11;i++)
    if((nr1+v[i])%7==nr2)
      flag=1;
   if(flag==1)
      printf("YES");
   else
      printf("NO");
   return 0;
}