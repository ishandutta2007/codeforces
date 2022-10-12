#include<bits/stdc++.h>

using namespace std;

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

using pi=pair<int,int>;
using Graph=vector<vector<pi>>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for(auto &nx : a){cin >> nx;}
  int m;
  cin >> m;
  UnionFind uf(n);
  vector<int> res(m,0);
  Graph g(n);
  vector<int> bk(n,0);
  for(int i=0;i<m;i++){
    int u,v;
    cin >> u >> v;
    u--;v--;
    if(uf.findSet(u,v)){continue;}
    uf.unionSet(u,v);
    g[u].push_back({v,i});
    g[v].push_back({u,m+i});
    bk[u]++;bk[v]++;
  }
  map<int,int> mp;
  for(int i=0;i<n;i++){mp[uf.root(i)]+=a[i];}
  for(auto &nx : mp){
    if(nx.second!=0){
      cout << "Impossible\n";
      return 0;
    }
  }
  cout << "Possible\n";
  queue<int> q;
  for(int i=0;i<n;i++){
    if(bk[i]==1){q.push(i);}
  }
  while(!q.empty()){
    int od=q.front();q.pop();
    for(auto &nx : g[od]){
      if(bk[nx.first]>=1){
        int del=a[od];
        a[od]-=del;a[nx.first]+=del;
        if(nx.second<m){res[nx.second]-=del;}
        else{res[nx.second-m]+=del;}
        bk[nx.first]--;
        bk[od]--;
        if(bk[nx.first]==1){q.push(nx.first);}
      }
    }
  }
  for(int i=0;i<m;i++){cout << res[i] << '\n';}
  return 0;
}