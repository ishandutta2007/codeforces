#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  map<int,vector<pi>> eg;
  for(int i=0;i<m;i++){
    int u,v,w;
    cin >> u >> v >> w;
    u--;v--;
    eg[w].push_back({u,v});
  }

  vector<int> dp(n,0);
  for(auto &nx : eg){
    vector<pi> qu;
    for(auto &ny : nx.second){
      qu.push_back({ny.second,dp[ny.first]+1});
    }
    for(auto &ny : qu){
      dp[ny.first]=max(dp[ny.first],ny.second);
    }
  }
  int res=0;
  for(auto &nx : dp){res=max(res,nx);}
  cout << res << '\n';
  return 0;
}