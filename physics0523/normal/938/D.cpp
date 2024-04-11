#include<bits/stdc++.h>

using namespace std;
using pl=pair<long long,long long>;
using Graph=vector<vector<pl>>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  Graph g(n);
  for(int i=0;i<m;i++){
    long long u,v,w;
    cin >> u >> v >> w;
    u--;v--;
    w*=2;
    g[u].push_back({v,w});
    g[v].push_back({u,w});
  }
  vector<long long> d(n,8e18);
  priority_queue<pl,vector<pl>,greater<pl>> pq;
  for(int i=0;i<n;i++){
    long long v;
    cin >> v;
    pq.push({v,i});
    d[i]=v;
  }
  while(!pq.empty()){
    pl od=pq.top();pq.pop();
    if(d[od.second]!=od.first){continue;}
    for(auto &nx : g[od.second]){
      long long nv=nx.first;
      long long nd=od.first+nx.second;
      if(d[nv]>nd){
        d[nv]=nd;
        pq.push({nd,nv});
      }
    }
  }
  for(int i=0;i<n;i++){
    if(i){cout << ' ';}
    cout << d[i];
  }cout << '\n';
  return 0;
}