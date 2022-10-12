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

typedef struct{
  int u,v,w;
}edge;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m;
    cin >> n >> m;
    vector<edge> eg(m);
    for(auto &nx : eg){
      cin >> nx.u >> nx.v >> nx.w;
      nx.u--;nx.v--;
    }
    int res=0;
    for(int i=30;i>=0;i--){
      vector<edge> neg;
      UnionFind uf(n);
      for(auto &nx : eg){
        if(nx.w&(1<<i)){continue;}
        neg.push_back(nx);
        uf.unionSet(nx.u,nx.v);
      }
      if(uf.size(0)==n){eg.swap(neg);}
      else{res|=(1<<i);}
    }
    cout << res << '\n';
  }
  return 0;
}