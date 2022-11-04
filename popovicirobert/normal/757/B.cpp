#include <bits/stdc++.h>
int vf[200000];
inline int getmin(int a,int b){
   if(a<b) return a;
   return b;
}
int main(){
   FILE*fi,*fout;
   int i,j,n,x,ans,cnt;
  // fi=fopen("A.in" ,"r");
  // fout=fopen("A.out" ,"w");
   fi=stdin;
   fout=stdout;
   fscanf(fi,"%d" ,&n);
   for(i=1;i<=n;i++){
      fscanf(fi,"%d" ,&x);
      vf[x]++;
   }
   ans=1;
   for(i=2;i<=100000;i++){
      j=i;
      cnt=0;
      while(j<=100000){
         cnt+=vf[j];
         j+=i;
      }
      if(cnt>ans)
          ans=cnt;
   }
   fprintf(fout,"%d" ,ans);
  // fclose(fi);
  // fclose(fout);
   return 0;
}