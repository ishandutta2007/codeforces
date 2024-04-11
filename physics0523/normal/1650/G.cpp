#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;
using pi=pair<int,int>;
using Graph=vector<vector<int>>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while(tc>0){
    tc--;
    int n,m,s,t;
    cin >> n >> m >> s >> t;
    s--;t--;
    Graph g(n);
    for(int i=0;i<m;i++){
      int u,v;
      cin >> u >> v;
      u--;v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    vector<int> d(n,1e9);
    queue<int> q;
    d[s]=0;q.push(s);
    while(!q.empty()){
      int od=q.front();q.pop();
      for(auto &nx : g[od]){
        if(d[nx]>5e8){
          d[nx]=d[od]+1;
          q.push(nx);
        }
      }
    }
    vector<map<int,int>> dp(n);
    dp[s][0]=1;
    vector<pi> pv;
    for(int i=0;i<n;i++){
      pv.push_back({d[i],i});
      pv.push_back({d[i]+1,i});
    }
    sort(pv.begin(),pv.end());
    for(auto &nx : pv){
      int cv=nx.second,cd=nx.first;
      for(auto &nx : g[cv]){
        dp[nx][cd+1]+=dp[cv][cd];
        dp[nx][cd+1]%=mod;
      }
    }
    cout << (dp[t][d[t]]+dp[t][d[t]+1])%mod << '\n';
  }
  return 0;
}