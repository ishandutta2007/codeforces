#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

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

int dist(pi a,pi b){
  return abs(a.first-b.first)+abs(a.second-b.second);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<pi> x(n);
  for(int i=0;i<n;i++){cin >> x[i].first >> x[i].second;}
  vector<long long> c(n),k(n);
  for(int i=0;i<n;i++){cin >> c[i];}
  for(int i=0;i<n;i++){cin >> k[i];}
  vector<pair<long long,pi>> vp;
  for(int i=0;i<n;i++){
    vp.push_back(make_pair(c[i],make_pair(i,n)));
    for(int j=i+1;j<n;j++){
      vp.push_back(make_pair(((long long)(k[i]+k[j])) * ((long long)dist(x[i],x[j])) , make_pair(i,j)));
    }
  }
  sort(vp.begin(),vp.end());
  UnionFind uf(n+1);
  long long res=0;
  vector<int> build;
  vector<pi> edge;
  for(auto &nx : vp){
    if(uf.findSet(nx.second.first,nx.second.second)){continue;}
    uf.unionSet(nx.second.first,nx.second.second);
    res+=nx.first;
    if(nx.second.second==n){build.push_back(nx.second.first);}
    else{edge.push_back(nx.second);}
  }
  cout << res << '\n';
  cout << build.size() << '\n';
  for(int i=0;i<build.size();i++){
    if(i){cout << ' ';}
    cout << build[i]+1;
  }cout << '\n';
  cout << edge.size() << '\n';
  for(auto &nx : edge){
    cout << nx.first+1 << ' ' << nx.second+1 << '\n';
  }
  return 0;
}