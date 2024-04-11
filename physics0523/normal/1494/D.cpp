#include<bits/stdc++.h>

using namespace std;
using Graph=vector<vector<int>>;

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

int ic;
int n;
vector<vector<int>> arr;
vector<int> c;
vector<pair<int,int>> edge;

int rep(vector<int> v){
  if(v.size()==1){return v[0];}
  int cid=n;
  n++;
  int mx=-1;
  for(auto &i : v){
    for(auto &j : v){
      mx=max(arr[i][j],mx);
    }
  }
  c.push_back(mx);

  UnionFind uf(ic);
  for(auto &i : v){
    for(auto &j : v){
      if(arr[i][j]!=mx){uf.unionSet(i,j);}
    }
  }

  Graph g(ic);

  for(auto &i : v){g[uf.root(i)].push_back(i);}
  for(auto &i : v){
    if(g[i].size()!=0){
      int dw=rep(g[i]);
      edge.push_back(make_pair(dw,cid));
    }
  }

  return cid;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  ic=n;
  arr.resize(n);
  c.resize(n);
  vector<int> init;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      int v;
      cin >> v;
      arr[i].push_back(v);
      if(i==j){c[i]=v;}
    }
    init.push_back(i);
  }

  int root=rep(init);

  cout << n << '\n';
  for(int i=0;i<n;i++){
    if(i){cout << ' ';}
    cout << c[i];
  }cout << '\n';
  cout << root+1 << '\n';
  for(auto &nx : edge){cout << nx.first+1 << ' ' << nx.second+1 << '\n';}
  return 0;
}