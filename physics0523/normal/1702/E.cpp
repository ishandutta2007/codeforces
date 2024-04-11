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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<pi> dom(n);
    vector<int> bk(n,0);
    bool ng=false;
    for(auto &nx : dom){
      cin >> nx.first >> nx.second;
      nx.first--;nx.second--;
      bk[nx.first]++;
      bk[nx.second]++;
      if(nx.first==nx.second){ng=true;}
    }
    UnionFind uf(2*n);
    for(auto &nx : dom){
      uf.unionSet(2*nx.first,2*nx.second+1);
      uf.unionSet(2*nx.first+1,2*nx.second);
    }
    for(int i=0;i<n;i++){
      if(bk[i]>=3){ng=true;}
      if(uf.findSet(2*i,2*i+1)){ng=true;}
    }
    if(ng){cout << "NO\n";continue;}
    else{cout << "YES\n";}
  }
  return 0;
}