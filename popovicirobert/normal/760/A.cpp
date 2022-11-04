#include <bits/stdc++.h>
inline int calc(int n,int d){
   return 1+(n-(7-d+1))/7+((n-(7-d+1))%7>0);
}
int main(){
   FILE*fi,*fout;
   int n,d;
  // fi=fopen("A.in" ,"r");
  // fout=fopen("A.out" ,"w");
   fi=stdin;
   fout=stdout;
   fscanf(fi,"%d%d" ,&n,&d);
   if(n==1||n==3||n==5||n==8||n==10||n==12||n==7)
      fprintf(fout,"%d" ,calc(31,d));
   else
   if(n==2)
      fprintf(fout,"%d" ,calc(28,d));
   else
      fprintf(fout,"%d" ,calc(30,d));
// fclose(fi);
  // fclose(fout);
   return 0;
}