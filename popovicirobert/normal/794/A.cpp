#include <bits/stdc++.h>
#define MAXN 100000
int v[MAXN+1];
int main(){
   FILE*fi,*fout;
   int i,n,ans,a,b,c;
   //fi=fopen("A.in" ,"r");
   //fout=fopen("A.out" ,"w");
   fi=stdin;
   fout=stdout;
   fscanf(fi,"%d%d%d" ,&a,&b,&c);
   fscanf(fi,"%d" ,&n);
   for(i=1;i<=n;i++)
     fscanf(fi,"%d" ,&v[i]);
   std::sort(v+1,v+n+1);
   ans=0;
   for(i=1;i<=n;i++)
    if(b<v[i]&&v[i]<c)
      ans++;
   fprintf(fout,"%d" ,ans);
   //fclose(fi);
   //fclose(fout);
   return 0;
}