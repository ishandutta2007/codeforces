#include<bits/stdc++.h>

using namespace std;
using pl=pair<long long,long long>;
using Graph=vector<vector<pl>>;

vector<long long> a;
Graph g;
int res;
void rep(int v,int pv,long long d){
  if(d>a[v]){return;}
  res--;
  for(auto &nx : g[v]){
    if(nx.first==pv){continue;}
    rep(nx.first,v,max(0ll,d)+nx.second);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  a.resize(n);
  g.resize(n);
  for(auto &nx : a){cin >> nx;}
  for(int i=1;i<n;i++){
    long long p,w;
    cin >> p >> w;
    p--;
    g[p].push_back({i,w});
    g[i].push_back({p,w});
  }
  res=n;
  rep(0,-1,0);
  cout << res << '\n';
  return 0;
}