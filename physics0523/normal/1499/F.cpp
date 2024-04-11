#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
#define mod 998244353

using namespace std;
using Graph=vector<vector<int>>;

void rep(int v,int pv,vector<int> &res,Graph &g){
  for(auto &nx : g[v]){
    if(nx==pv){continue;}
    rep(nx,v,res,g);
  }
  res.push_back(v);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,k;
  cin >> n >> k;
  Graph g(n);
  for(int i=0;i<(n-1);i++){
    int u,v;
    cin >> u >> v;
    u--;v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<int> mem(n,-1);
  vector<int> arr;
  Graph dp(n);
  rep(0,-1,arr,g);
  for(auto &v : arr){
    mem[v]=1;
    dp[v]={1};
    for(auto &nv : g[v]){
      if(mem[nv]==-1){continue;}
      vector<int> ndp(max(dp[v].size(),dp[nv].size()+1));
      for(int i=0;i<dp[v].size();i++){
        long long cd=dp[v][i];
        long long ss=0;
        for(int j=0;j<dp[nv].size();j++){
          ss+=dp[nv][j];ss%=mod;
          if((i+j+1)>k){continue;}
          ndp[max(i,j+1)]+=(cd*dp[nv][j])%mod;
          ndp[max(i,j+1)]%=mod;
        }
        ndp[i]+=(cd*ss)%mod;
        ndp[i]%=mod;
      }
      while(ndp[ndp.size()-1]==0){ndp.pop_back();}
      dp[v].swap(ndp);
      mem[v]+=mem[nv];
    }
  }

  long long res=0;
  for(auto &nx : dp[0]){res+=nx;}
  cout << res%mod << '\n';
  return 0;
}