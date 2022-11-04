#include <bits/stdc++.h>
#define MAXN 1000
std::vector <int> G[MAXN+1];
int v[MAXN+1];
int vf[MAXN+1][MAXN+1];
bool viz[MAXN+1];
int dp[MAXN+1];
int ans;
void DFS(int nod){
    viz[nod]=1;
    for(auto x:G[nod])
     if(viz[x]==0){
        DFS(x);
        dp[nod]=std::max(dp[nod],dp[x]);
     }
     else
       dp[nod]=std::max(dp[nod],dp[x]);
    dp[nod]++;
    ans=std::max(ans,dp[nod]);
}
int main(){
   FILE*fi,*fout;
   int i,j,n,k,p;
  // fi=fopen("D.in" ,"r");
  // fout=fopen("D.out" ,"w");
   fi=stdin;
   fout=stdout;
   fscanf(fi,"%d%d" ,&n,&k);
   for(i=1;i<=k;i++){
      for(j=1;j<=n;j++)
        fscanf(fi,"%d" ,&v[j]);
      for(j=1;j<n;j++)
       for(p=j+1;p<=n;p++)
         vf[v[j]][v[p]]++;
   }
   for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
     if(i!=j&&vf[i][j]==k)
        G[i].push_back(j);
   for(i=1;i<=n;i++)
     if(viz[i]==0)
      DFS(i);
   fprintf(fout,"%d" ,ans);
 //  fclose(fi);
 //  fclose(fout);
   return 0;
}