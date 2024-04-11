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

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  UnionFind uf(m+1);
  vector<pair<int,int>> vs;
  for(int i=0;i<n;i++){
    int k,p,q;
    cin >> k;
    if(k==1){
      cin >> p;
      vs.push_back(make_pair(p,-1));
      uf.unionSet(p,0);
    }
    else{
      cin >> p >> q;
      vs.push_back(make_pair(p,q));
      uf.unionSet(p,q);
    }
  }
  long long res=power(2,(long long)(uf.size(0)-1));
  for(int i=1;i<=m;i++){
    if(uf.findSet(0,i)){continue;}
    if(uf.root(i)==i){
      res*=power(2,(long long)(uf.size(i)-1));
      res%=mod;
    }
  }
  cout << res << ' ';
  vector<int> rs;
  UnionFind nuf(m+1);
  for(int i=0;i<n;i++){
    if(vs[i].second==-1){ // k==1
      if(nuf.findSet(0,vs[i].first)){continue;}
      rs.push_back(i);
      nuf.unionSet(0,vs[i].first);
    }
    else{ // k==2
      if(nuf.findSet(vs[i].first,vs[i].second)){continue;}
      rs.push_back(i);
      nuf.unionSet(vs[i].first,vs[i].second);
    }
  }

  int rc=rs.size();
  cout << rc << '\n';
  for(int i=0;i<rc;i++){
    if(i){cout << ' ';}
    cout << (rs[i]+1);
  }
  cout << '\n';
  return 0;
}