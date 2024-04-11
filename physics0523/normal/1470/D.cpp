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

using Graph=vector<vector<int>>;

vector<int> res;
unordered_map<int,int> mp;
unordered_map<int,int> mem;

void rep(int v,Graph &g){
  if(mp[v]==1){return;}
  mp[v]=1;
  if(mem[v]==0){
    mem[v]=1;
    for(auto &e : g[v]){
      mem[e]=1;
    }
    res.push_back(v);
  }
  for(auto &e : g[v]){
    rep(e,g);
  }
  return;
}

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m;
    cin >> n >> m;
    UnionFind uf(n+1);
    Graph g(n+1);
    for(int i=0;i<m;i++){
      int p,q;
      cin >> p >> q;
      uf.unionSet(p,q);
      g[p].push_back(q);
      g[q].push_back(p);
    }
    if(uf.size(1)!=n){cout << "NO\n";continue;}

    res.clear();
    mp.clear();
    mem.clear();
    
    rep(1,g);
    
    int rs=res.size();
    cout << "YES\n";
    cout << rs << '\n';
    for(int i=0;i<rs;i++){
      if(i){cout << ' ';}
      cout << res[i];
    }cout << '\n';
  }
}