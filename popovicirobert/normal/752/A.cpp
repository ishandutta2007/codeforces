#include <cstdio>

int main(){
   FILE*fi,*fout;
   int n,m,k,c;
   //fi=fopen("A.in" ,"r");
   //fout=fopen("A.out" ,"w");
   fi=stdin;
   fout=stdout;
   fscanf(fi,"%d%d%d" ,&m,&n,&k);
   c=1;
   while(k>2*n){
     k-=2*n;
     c++;
   }
   fprintf(fout,"%d %d " ,c,(k+1)/2);
   if(k%2==1)
     fprintf(fout,"L");
   else
     fprintf(fout,"R");
  // fclose(fi);
  // fclose(fout);
   return 0;
}