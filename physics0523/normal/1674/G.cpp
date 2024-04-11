#include<bits/stdc++.h>

using namespace std;
using Graph=vector<vector<int>>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  Graph g(n);
  vector<int> ind(n,0),oud(n,0);
  for(int i=0;i<m;i++){
    int u,v;
    cin >> u >> v;
    u--;v--;
    g[u].push_back(v);
    oud[u]++;ind[v]++;
  }
  vector<int> bk=ind;
  vector<int> dp(n,1);
  queue<int> q;
  for(int i=0;i<n;i++){
    if(bk[i]==0){q.push(i);}
  }
  while(!q.empty()){
    int od=q.front();q.pop();
    for(auto &nx : g[od]){
      if(oud[od]>=2 && ind[nx]>=2){
        dp[nx]=max(dp[nx],dp[od]+1);
      }
      bk[nx]--;
      if(bk[nx]==0){q.push(nx);}
    }
  }

  int res=0;
  for(auto &nx : dp){res=max(res,nx);}
  cout << res << '\n';
  return 0;
}