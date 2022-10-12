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
  UnionFind uf(2*n);
  vector<int> u(m),v(m);
  for(int i=0;i<m;i++){
    cin >> u[i] >> v[i];
    u[i]--;v[i]--;
    uf.unionSet(2*u[i],2*v[i]+1);
    uf.unionSet(2*u[i]+1,2*v[i]);
  }

  for(int i=0;i<n;i++){
    if(uf.findSet(2*i,2*i+1)){cout << "-1\n";return 0;}
  }

  set<int> tr;
  for(int i=0;i<n;i++){
    if(tr.find(uf.root(2*i))!=tr.end()){continue;}
    if(tr.find(uf.root(2*i+1))!=tr.end()){continue;}
    tr.insert(uf.root(2*i));
  }

  vector<int> s1,s2;
  for(int i=0;i<n;i++){
    if(tr.find(uf.root(2*i))!=tr.end()){s1.push_back(i+1);}
    else{s2.push_back(i+1);}
  }

  cout << s1.size() << '\n';
  for(int i=0;i<s1.size();i++){
    if(i){cout << ' ';}
    cout << s1[i];
  }cout << '\n';
  cout << s2.size() << '\n';
  for(int i=0;i<s2.size();i++){
    if(i){cout << ' ';}
    cout << s2[i];
  }cout << '\n';
  return 0;
}