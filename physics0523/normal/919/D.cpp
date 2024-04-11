#include<bits/stdc++.h>

using namespace std;
using Graph=vector<vector<int>>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  string s;
  cin >> s;
  Graph g(n);
  vector<int> bk(n);
  for(int i=0;i<m;i++){
    int u,v;
    cin >> u >> v;
    u--;v--;
    g[u].push_back(v);
    bk[v]++;
  }

  vector<vector<int>> dp(n,vector<int>(26,0));
  queue<int> q;
  for(int i=0;i<n;i++){
    if(bk[i]==0){q.push(i);}
  }

  int cnt=0;
  while(!q.empty()){
    int od=q.front();q.pop();
    cnt++;
    dp[od][s[od]-'a']++;
    for(auto &nx : g[od]){
      for(int i=0;i<26;i++){
        dp[nx][i]=max(dp[nx][i],dp[od][i]);
      }
      bk[nx]--;
      if(bk[nx]==0){q.push(nx);}
    }
  }
  if(cnt!=n){cout << "-1\n";return 0;}
  int res=0;
  for(auto &nx : dp){
    for(auto &ny : nx){
      res=max(res,ny);
    }
  }
  cout << res << '\n';
  return 0;
}