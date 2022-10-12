#include<bits/stdc++.h>
#define mod 1000000007

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
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    long long res=1;
    vector<int> a(n),b(n),c(n);
    for(auto &nx : a){cin >> nx;}
    for(auto &nx : b){cin >> nx;}
    for(auto &nx : c){cin >> nx;}
    UnionFind uf(n);
    for(int i=0;i<n;i++){uf.unionSet(a[i]-1,b[i]-1);}
    vector<int> bk(n,0);
    for(int i=0;i<n;i++){
      if(c[i]>0){
        bk[uf.root(c[i]-1)]=1;
      }
    }
    for(int i=0;i<n;i++){
      if(uf.root(i)==i){
        if(bk[i]){continue;}
        if(uf.size(i)<=1){continue;}
        res*=2;res%=mod;
      }
    }
    cout << res << '\n';
  }
  return 0;
}