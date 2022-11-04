#include <bits/stdc++.h>
#define MAXN 300000
char A[MAXN+1],B[MAXN+1];
char sol[MAXN+1];
int main(){
   FILE*fi,*fout;
   int i,n,b1,b2,e1,e2,poz1,poz2;
   //fi=fopen("C.in" ,"r");
   //fout=fopen("C.out" ,"w");
   fi=stdin;
   fout=stdout;
   fscanf(fi,"%s %s " ,&A,&B);
   n=strlen(A);
   std::sort(A,A+n);
   std::sort(B,B+n);
   b1=0;
   b2=n;
   for(i=1;i<=n;i++)
     if(i%2==0)
       b2--;
   e1=(n-1)/2;
   e2=n-1;
   poz1=0;
   poz2=n-1;
   for(i=1;i<=n;i++){
      if(i%2==1){
         if(A[b1]<B[e2]){
           sol[poz1++]=A[b1];
           b1++;
         }
         else{
           sol[poz2--]=A[e1];
           e1--;
         }
      }
      else{
         if(B[e2]>A[b1]){
           sol[poz1++]=B[e2];
           e2--;
         }
         else{
           sol[poz2--]=B[b2];
           b2++;
         }
      }
   }
   for(i=0;i<n;i++)
     fprintf(fout,"%c" ,sol[i]);
   //fclose(fi);
   //fclose(fout);
   return 0;
}