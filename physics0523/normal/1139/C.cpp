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

long long power(long long a,long long b){
  long long x=1,y=a;
  while(b>0){
    if(b&1ll){
      x=(x*y)%mod;
    }
    y=(y*y)%mod;
    b>>=1;
  }
  return x%mod;
}

long long modular_inverse(long long n){
  return power(n,mod-2);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n,k;
  cin >> n >> k;
  UnionFind uf(n);
  for(int i=1;i<n;i++){
    int u,v,w;
    cin >> u >> v >> w;
    u--;v--;
    if(w==0){
      uf.unionSet(u,v);
    }
  }
  long long res=power(n,k);
  for(int i=0;i<n;i++){
    if(uf.root(i)==i){
      long long cnt=uf.size(i);
      res+=mod;
      res-=power(cnt,k);
      res%=mod;
    }
  }
  cout << res << '\n';
  return 0;
}