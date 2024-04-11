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
  int n;
  cin >> n;
  UnionFind uf(n+26);
  for(int i=0;i<n;i++){
    string s;
    cin >> s;
    for(auto &nx : s){
      uf.unionSet(i,n+(nx-'a'));
    }
  }
  set<int> st;
  for(int i=0;i<n;i++){st.insert(uf.root(i));}
  cout << st.size() << '\n';
  return 0;
}