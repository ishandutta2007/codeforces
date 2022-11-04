#include <bits/stdc++.h>

int main(){
   FILE*fi,*fout;
   int n,d,a,b;
  // fi=fopen("A.in" ,"r");
  // fout=fopen("A.out" ,"w");
   fi=stdin;
   fout=stdout;
   fscanf(fi,"%d" ,&n);
   d=1;
   while(d*d<=n){
      if(n%d==0){
        a=d;
        b=n/d;
      }
      d++;
   }
   fprintf(fout,"%d %d " ,a,b);
  // fclose(fi);
  // fclose(fout);
   return 0;
}