#include <bits/stdc++.h>

int main(){
   FILE*fi,*fout;
   int i,n;
  // fi=fopen("A.in" ,"r");
  // fout=fopen("A.out" ,"w");
   fi=stdin;
   fout=stdout;
   fscanf(fi,"%d" ,&n);
   if(n%2==1){
       fprintf(fout,"%d\n" ,n/2);
       for(i=1;i<n/2;i++)
          fprintf(fout,"2 ");
       fprintf(fout,"3");
   }
   else{
       fprintf(fout,"%d\n" ,n/2);
       for(i=1;i<=n/2;i++)
          fprintf(fout,"2 ");
   }
  // fclose(fi);
  // fclose(fout);
   return 0;
}