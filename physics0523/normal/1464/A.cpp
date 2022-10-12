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
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m;
    cin >> n >> m;
    vector<int> x(m),y(m);
    UnionFind uf(n+1);
    for(int i=0;i<m;i++){
      cin >> x[i] >> y[i];
      uf.unionSet(x[i],y[i]);
    }
    vector<int> ec(n+1);
    for(int i=0;i<m;i++){
      ec[uf.root(x[i])]++;
    }
    int res=0;
    for(int i=1;i<=n;i++){
      if(uf.size(i)==1){continue;}
      if(uf.root(i)!=i){continue;}
      if(uf.size(i)==ec[i]){res+=(ec[i]+1);}
      else{res+=ec[i];}
    }
    cout << res << '\n';
  }
}