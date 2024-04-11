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
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,m;
  cin >> n >> m;
  vector<set<int>> st(n);
  for(int i=0;i<m;i++){
    int u,v;
    cin >> u >> v;
    u--;v--;
    st[u].insert(v);
    st[v].insert(u);
  }
  UnionFind uf(n+1);
  for(int i=0;i<n;i++){
    int deg=n-st[i].size();
    if(2*deg>n){uf.unionSet(i,n);}
    else{
      vector<int> rem(n,1);
      for(auto &nx : st[i]){rem[nx]=0;}
      for(int j=0;j<n;j++){
        if(rem[j]){uf.unionSet(i,j);}
      }
    }
  }
  int lg=uf.root(n);
  vector<int> res;
  set<int> rs;
  for(int i=0;i<n;i++){
    if(rs.find(uf.root(i))==rs.end()){
      rs.insert(uf.root(i));
      int del=0;
      if(lg==uf.root(i)){del=1;}
      res.push_back(uf.size(i)-del);
    }
  }
  
  sort(res.begin(),res.end());
  cout << res.size() << "\n";
  for(int i=0;i<res.size();i++){
    if(i){cout << " ";}
    cout << res[i];
  }cout << "\n";
  return 0;
}