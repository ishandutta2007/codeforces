#include <bits/stdc++.h>
#define MAXN 100000
#define INF 1000000
int v[MAXN+1];
int main(){
   FILE*fi,*fout;
   int i,n,sum,min,max;
  // fi=fopen("A.in" ,"r");
  // fout=fopen("A.out" ,"w");
   fi=stdin;
   fout=stdout;
   fscanf(fi,"%d" ,&n);
   sum=0;
   min=INF;
   max=-INF;
   for(i=1;i<=n;i++){
     fscanf(fi,"%d" ,&v[i]);
     if(v[i]>0){
       sum+=v[i];
       if(v[i]%2!=0)
         min=std::min(min,v[i]);
     }
     else
       if(v[i]%2!=0)
        max=std::max(max,v[i]);
   }
   if(sum%2==0)
     sum=std::max(sum-min,std::max(sum+max,max));
   fprintf(fout,"%d" ,sum);
 //  fclose(fi);
 //  fclose(fout);
   return 0;
}