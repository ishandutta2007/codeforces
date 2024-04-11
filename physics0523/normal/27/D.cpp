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
  vector<int> x(m),y(m);
  for(int i=0;i<m;i++){
    cin >> x[i] >> y[i];
    if(x[i]>y[i]){swap(x[i],y[i]);}
  }

  UnionFind uf(2*m);
  for(int i=0;i<m;i++){
    for(int j=0;j<m;j++){
      if(x[i]<x[j] && x[j]<y[i] && y[i]<y[j]){
        uf.unionSet(2*i,2*j+1);
        uf.unionSet(2*i+1,2*j);
      }
      if(x[j]<x[i] && x[i]<y[j] && y[j]<y[i]){
        uf.unionSet(2*i,2*j+1);
        uf.unionSet(2*i+1,2*j);
      }
    }
  }

  set<int> st;
  for(int i=0;i<m;i++){
    if(uf.findSet(2*i,2*i+1)){cout << "Impossible\n";return 0;}
    if(st.find(uf.root(2*i))!=st.end()){continue;}
    if(st.find(uf.root(2*i+1))!=st.end()){continue;}
    st.insert(uf.root(2*i));
  }
  for(int i=0;i<m;i++){
    if(st.find(uf.root(2*i))!=st.end()){cout << "i";}
    else{cout << "o";}
  }
  cout << "\n";
  return 0;
}