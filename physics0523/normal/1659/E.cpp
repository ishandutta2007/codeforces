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
  vector<int> u(m),v(m),w(m);
  vector<UnionFind> uf(30,UnionFind(n));
  for(int i=0;i<m;i++){
    cin >> u[i] >> v[i] >> w[i];
    u[i]--;v[i]--;
    for(int j=0;j<30;j++){
      if(w[i]&(1<<j)){
        uf[j].unionSet(u[i],v[i]);
      }
    }
  }
  vector<vector<int>> lk(30,vector<int>(n,0));
  for(int i=0;i<m;i++){
    if(w[i]&1){continue;}
    for(int j=1;j<30;j++){
      lk[j][uf[j].root(u[i])]=1;
      lk[j][uf[j].root(v[i])]=1;
    }
  }
  int q;
  cin >> q;
  while(q>0){
    q--;
    int a,b;
    cin >> a >> b;
    a--;b--;
    bool isok=false;
    for(int i=0;i<30;i++){
      if(uf[i].findSet(a,b)){
        isok=true;break;
      }
    }
    if(isok){cout << "0\n";continue;}
    for(int i=0;i<30;i++){
      int rt=uf[i].root(a);
      if(lk[i][rt]){isok=true;break;}
    }
    if(isok){cout << "1\n";continue;}
    cout << "2\n";
  }
  return 0;
}