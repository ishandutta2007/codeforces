#include<bits/stdc++.h>

using namespace std;
using Graph=vector<vector<int>>;

int n;
vector<long long> h;
Graph g;
long long res=0;
long long rep(int v,int pv){
  int sz;
  priority_queue<long long,vector<long long>,greater<long long>> pq;
  if(pv==-1){
    sz=2;
    pq.push(0);
    pq.push(0);
  }
  else{
    sz=1;
    pq.push(0);
  }
  for(auto &nx : g[v]){
    if(nx==pv){continue;}
    pq.push(rep(nx,v));
    pq.pop();
  }
  long long cm=0;
  while(!pq.empty()){
    long long od=pq.top();pq.pop();
    cm=max(cm,od);
    if(od<h[v]){res+=(h[v]-od);}
  }
  return max(h[v],cm);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  h.resize(n);
  for(auto &nx : h){cin >> nx;}
  g.resize(n);
  for(int i=1;i<n;i++){
    int u,v;
    cin >> u >> v;
    u--;v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int root=0;
  for(int i=1;i<n;i++){
    if(h[root]<h[i]){root=i;}
  }
  rep(root,-1);
  cout << res << '\n';
  return 0;
}