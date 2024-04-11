#include<bits/stdc++.h>
#define llinf 4154118101919364364

using namespace std;
using pi=pair<int,int>;
using pli=pair<long long,int>;
using Graph=vector<vector<pli>>;

struct UnionFind {
  vector<int> data;
  UnionFind(int size) : data(size, -1) { }
  bool unionSet(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool findSet(int x, int y) {
    return root(x) == root(y);
  }
  int root(int x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  int size(int x) {
    return -data[root(x)];
  }
};

vector<int> merge(unordered_set<int> &a,unordered_set<int> &b){
  if(a.size()<b.size()){swap(a,b);}
  vector<int> res;
  for(auto &nx : b){
    if(a.find(nx)!=a.end()){
      a.erase(nx);
      res.push_back(nx);
    }
    else{a.insert(nx);}
  }
  b.clear();
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m,k,q;
  cin >> n >> m >> k >> q;
  Graph g(n);
  for(int i=0;i<m;i++){
    int u,v;
    long long w;
    cin >> u >> v >> w;
    u--;v--;
    g[u].push_back({w,v});
    g[v].push_back({w,u});
  }
  priority_queue<pli,vector<pli>,greater<pli>> pq;
  vector<long long> dist(n,llinf);
  for(int i=0;i<k;i++){
    pq.push({0,i});
    dist[i]=0;
  }
  while(!pq.empty()){
    pli od=pq.top();pq.pop();
    if(dist[od.second]<od.first){continue;}
    for(auto &nx : g[od.second]){
      long long nd=od.first+nx.first;
      if(dist[nx.second]>nd){
        dist[nx.second]=nd;
        pq.push({nd,nx.second});
      }
    }
  }
  vector<pair<long long,pi>> ev;
  for(int i=0;i<n;i++){
    for(auto &nx : g[i]){
      int j=nx.second;
      if(i>j){continue;}
      long long len=dist[i]+dist[j]+nx.first;
      ev.push_back({len,{i,j}});
    }
  }
  sort(ev.begin(),ev.end());
  vector<long long> res(q);
  vector<unordered_set<int>> vus(n);
  for(int i=0;i<q;i++){
    int u,v;
    cin >> u >> v;
    u--;v--;
    vus[u].insert(i);
    vus[v].insert(i);
  }
  UnionFind uf(n);
  for(auto &nx : ev){
    int u=nx.second.first;
    int v=nx.second.second;
    //cout << nx.first << ' ' << u << ' ' << v << '\n';
    u=uf.root(u);
    v=uf.root(v);
    if(!uf.findSet(u,v)){
      uf.unionSet(u,v);
      vector<int> cres;
      if(uf.root(u)==u){
        cres=merge(vus[u],vus[v]);
      }
      else{
        cres=merge(vus[v],vus[u]);
      }
      for(auto &ny : cres){
        res[ny]=nx.first;
      }
    }
  }
  for(int i=0;i<q;i++){
    cout << res[i] << '\n';
  }
  return 0;
}