#include <bits/stdc++.h>

int main(){
   FILE*fi,*fout;
   int n,i,k,con;
   char a;
  // fi=fopen("A.in" ,"r");
  // fout=fopen("A.out" ,"w");
   fi=stdin;
   fout=stdout;
   fscanf(fi,"%d%d" ,&n,&k);
   con=0;
   i=1;
   while(con<=240-k){
     con+=5*i;
     i++;
   }
   i-=2;
   if(i>n)
     i=n;
   fprintf(fout,"%d" ,i);
   //fclose(fi);
   //fclose(fout);
   return 0;
}