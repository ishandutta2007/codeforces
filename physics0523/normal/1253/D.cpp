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

int main(){
  int n,m;
  cin >> n >> m;
  UnionFind uf(n+1);
  for(int i=0;i<m;i++){
    int u,v;
    cin >> u >> v;
    uf.unionSet(u,v);
  }
  vector<int> cm(n+1,-1);
  vector<int> um(n+1,-1);
  for(int i=1;i<=n;i++){cm[uf.root(i)]=i;}
  for(int i=1;i<=n;i++){
    um[i]=cm[uf.root(i)];
  }
  int clim=-1,res=0;
  for(int i=1;i<=n;i++){
    clim=max(clim,um[i]);
    if(i<clim){
      if(!uf.findSet(i,i+1)){
        res++;
        uf.unionSet(i,i+1);
      }
    }
  }
  cout << res << '\n';
  return 0;
}