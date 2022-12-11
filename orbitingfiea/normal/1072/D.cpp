#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include<bits/stdc++.h>
using namespace std;

int n, k, f[2020][2020], mx, g[2020][2020];
char s[2020][2020];

void dfs(int i,int j){
  putchar(s[i][j]);
  if (i==n&&j==n) return;
  if (g[i+1][j]<g[i][j+1]) dfs(i+1,j);
  else dfs(i,j+1);
}

int main(){
  cin>>n>>k;
  for (int i=1;i<=n;++i){
    scanf("%s",s[i]+1);
  }
  memset(f,33,sizeof f);
  f[0][0]=f[0][1]=f[1][0]=0;
  f[1][1]= s[1][1]!='a';
  for (int i=1;i<=n;++i)
    for (int j=1;j<=n;++j){
      if (i==1&&j==1) continue;
      f[i][j]=min(f[i-1][j],f[i][j-1])+(s[i][j]!='a');
    }
  mx=1;
  for (int i=1;i<=n;++i)
    for (int j=1;j<=n;++j)
      if (f[i][j]<=k)
        mx=max(mx,i+j);

  memset(g,33,sizeof g);
  g[n][n]=0;
  
  for (int sum=n*2-1;sum>=2;--sum){
    vector<int>ls;
    for (int i=1;i<=n;++i){
      int j=sum-i;
      if (!(j>=1&&j<=n)) continue;
      g[i][j]=s[i][j]*10000+min(g[i+1][j],g[i][j+1]);
      ls.push_back(g[i][j]);
    }
    sort(ls.begin(),ls.end());
    ls.resize(unique(ls.begin(),ls.end())-ls.begin());
    for (int i=1;i<=n;++i){
      int j=sum-i;
      if (!(j>=1&&j<=n)) continue;
      g[i][j]=lower_bound(ls.begin(),ls.end(),g[i][j])-ls.begin();
    }
  }
  for (int i=2;i<=mx;++i) putchar('a');

  if (mx!=n*2){
    int ans=1e9;
    for (int i=1;i<=n;++i){
      int j=mx+1-i;
      if (!(j>=1&&j<=n)) continue;
      if (f[i-1][j]>k&&f[i][j-1]>k) continue;
      ans=min(ans,g[i][j]);
    }
    for (int i=1;i<=n;++i){
      int j=mx+1-i;
      if (!(j>=1&&j<=n)) continue;
      if (f[i-1][j]>k&&f[i][j-1]>k) continue;
      if (ans==g[i][j]){
        dfs(i,j); return 0;
      }
    }
  }
}