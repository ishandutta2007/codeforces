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

using Graph=vector<vector<int>>;
vector<int> cp,rp;
void fr(int v,int pv,int tg,Graph &g){
  if(!rp.empty()){return;}
  cp.push_back(v);
  if(v==tg){
    rp=cp;
    return;
  }
  for(auto &nx : g[v]){
    if(nx==pv){continue;}
    fr(nx,v,tg,g);
  }
  cp.pop_back();
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  UnionFind uf(n+1);
  Graph g(n+1);
  for(int i=0;i<m;i++){
    int p,q;
    cin >> p >> q;
    if(uf.findSet(p,q)){continue;}
    uf.unionSet(p,q);
    g[p].push_back(q);
    g[q].push_back(p);
  }
  int c;
  cin >> c;
  vector<int> bk(n+1,0);
  vector<int> a(c),b(c);
  for(int i=0;i<c;i++){
    cin >> a[i] >> b[i];
    bk[a[i]]++;bk[b[i]]++;
  }
  int res=0;
  for(int i=1;i<=n;i++){
    if(bk[i]%2){res++;}
  }
  if(res==0){
    cout << "YES\n";
    for(int i=0;i<c;i++){
      cp.clear();rp.clear();
      fr(a[i],-1,b[i],g);
      cout << rp.size() << '\n';
      for(int j=0;j<rp.size();j++){
        if(j){cout << ' ';}
        cout << rp[j];
      }cout << '\n';
    }
  }
  else{
    cout << "NO\n";
    cout << res/2 << '\n';
  }
  return 0;
}