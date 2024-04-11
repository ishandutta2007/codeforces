#include <bits/stdc++.h>
#define DIST 20000
int main(){
   FILE*fi,*fout;
   int n,i,val,x,y;
   bool flag;
   char a;
 //  fi=fopen("A.in" ,"r");
 //  fout=fopen("A.out" ,"w");
   fi=stdin;
   fout=stdout;
   fscanf(fi,"%d" ,&n);
   i=1;
   x=0;
   y=0;
   flag=1;
   while(flag==1&&i<=n){
      fscanf(fi,"%d" ,&val);
      fgetc(fi);
      a=fgetc(fi);
      if((y==0&&a!='S')||(y==DIST&&a!='N'))
        flag=0;
      if(a=='S')
          y+=val;
      if(a=='N')
         y-=val;
      if(a=='E')
         x+=val;
      if(a=='W')
         x-=val;
      if(y>DIST||y<0)
        flag=0;
      while(isalpha(a))
         a=fgetc(fi);
      i++;
   }
   if(flag==1&&y==0)
     fprintf(fout,"YES");
   else
     fprintf(fout,"NO");
  // fclose(fi);
 //  fclose(fout);
   return 0;
}