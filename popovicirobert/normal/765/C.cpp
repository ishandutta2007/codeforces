#include <bits/stdc++.h>

int main(){
   FILE*fi,*fout;
   int a,b,k;
  // fi=fopen("A.in" ,"r");
  // fout=fopen("A.out" ,"w");
   fi=stdin;
   fout=stdout;
   fscanf(fi,"%d%d%d" ,&k,&a,&b);
   if((a/k==0&&b%k>0)||(b/k==0&&a%k>0))
     fprintf(fout,"-1");
   else
     fprintf(fout,"%d" ,a/k+b/k);
  // fclose(fi);
  // fclose(fout);
   return 0;
}