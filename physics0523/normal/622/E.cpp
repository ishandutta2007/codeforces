#include<bits/stdc++.h>

using namespace std;
using Graph=vector<vector<int>>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  Graph g(n);
  for(int i=1;i<n;i++){
    int u,v;
    cin >> u >> v;
    u--;v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int res=0;
  vector<int> d(n,1e9);
  d[0]=0;
  queue<int> q;
  for(auto &nx : g[0]){
    map<int,int> mp;
    q.push(nx);
    d[nx]=1;
    while(!q.empty()){
      int od=q.front();q.pop();
      if(g[od].size()==1){mp[-d[od]]++;}
      for(auto &nx : g[od]){
        if(d[nx]>5e8){
          d[nx]=d[od]+1;
          q.push(nx);
        }
      }
    }
    int c=0,wa=0;
    for(auto &nx : mp){
      //cout << nx.first << ' ' << nx.second << '\n';
      wa+=nx.second;
      c=max(c,wa-nx.first-1);
    }
    res=max(res,c);
  }
  cout << res << '\n';
  return 0;
}