#include <bits/stdc++.h>
inline long long cauta(long long x,int n,int k){
   long long ans=x;
   if(k<=x)
      ans=ans+x*(x-1)/2-(x-k)*(x-k+1)/2;
   else
      ans=ans+x*(x-1)/2+k-x;
   if(n-k+1<=x)
      ans=ans+x*(x-1)/2-(x-(n-k+1))*(x-(n-k+1)+1)/2;
   else
      ans=ans+x*(x-1)/2+(n-k+1)-x;
   return ans;
}
int main(){
   FILE*fi,*fout;
   int n,m,k,rez,pas;
  // fi=fopen("A.in" ,"r");
 //  fout=fopen("A.out" ,"w");
   fi=stdin;
   fout=stdout;
   fscanf(fi,"%d%d%d" ,&n,&m,&k);
   rez=0;
   for(pas=1<<29;pas;pas>>=1)
     if(cauta(rez+pas,n,k)<=m)
         rez+=pas;
   fprintf(fout,"%d" ,rez);
  // fclose(fi);
 //  fclose(fout);
   return 0;
}