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

using off=pair<long long,pair<int,int>>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  UnionFind uf(n);
  vector<long long> a(n);
  for(auto &nx : a){cin >> nx;}
  vector<off> cd(m);
  for(auto &nx : cd){
    cin >> nx.second.first >> nx.second.second >> nx.first;
    nx.second.first--;nx.second.second--;
  }
  int tg=0;
  for(int i=0;i<n;i++){
    if(a[i]<a[tg]){tg=i;}
  }
  for(int i=0;i<n;i++){
    if(i==tg){continue;}
    cd.push_back({a[i]+a[tg],{i,tg}});
  }
  sort(cd.begin(),cd.end());
  long long res=0;
  for(auto &nx : cd){
    if(uf.findSet(nx.second.first,nx.second.second)){continue;}
    res+=nx.first;
    uf.unionSet(nx.second.first,nx.second.second);
  }
  cout << res << '\n';
  return 0;
}