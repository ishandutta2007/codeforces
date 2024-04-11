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
  string s,t;
  UnionFind uf(26);
  cin >> n >> s >> t;
  for(int i=0;i<n;i++){uf.unionSet(s[i]-'a',t[i]-'a');}
  int res=26;
  for(int i=0;i<26;i++){
    if(i==uf.root(i)){res--;}
  }
  cout << res << '\n';
  for(int i=0;i<26;i++){
    if(i!=uf.root(i)){
      cout << (char)('a'+i) << ' ' << (char)('a'+uf.root(i)) << '\n';
    }
  }
  return 0;
}