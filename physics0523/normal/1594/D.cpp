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
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m;
    cin >> n >> m;
    UnionFind uf(2*n);
    for(int i=0;i<m;i++){
      int p,q;
      string s;
      cin >> p >> q >> s;
      p--;q--;
      if(s[0]=='i'){
        uf.unionSet(p,n+q);
        uf.unionSet(n+p,q);
      }
      else{
        uf.unionSet(p,q);
        uf.unionSet(n+p,n+q);
      }
    }
    bool iserr=false;
    for(int i=0;i<n;i++){
      iserr|=uf.findSet(i,n+i);
    }
    if(iserr){cout << "-1\n";continue;}
    vector<int> cnt(2*n,0);
    for(int i=0;i<n;i++){cnt[uf.root(i)]++;}
    int res=0;
    for(int i=0;i<2*n;i++){
      if(uf.root(i)==i){res+=max(cnt[i],uf.size(i)-cnt[i]);}
    }
    cout << res/2 << '\n';
  }
  return 0;
}