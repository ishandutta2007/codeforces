#include<bits/stdc++.h>

using namespace std;
using Graph=vector<vector<int>>;

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

using pi=pair<int,int>;

#define vsize 131072
#define fsize 32

int dist[vsize],nrep[vsize],doubling[vsize][fsize];

void lca_init(){
  for(int i=0;i<vsize;i++){
    dist[i]=1000000007;
    nrep[i]=-1;
    for(int j=0;j<fsize;j++){doubling[i][j]=-1;}
  }
}

void dfs(int t,int l,Graph &g){
  int i;
  if(dist[t]<=l){return;}
  dist[t]=l;
  for(i=0;i<30;i++){
    if((l-(1<<i))<0){break;}
    doubling[t][i]=nrep[(l-(1<<i))];
  }
  nrep[l]=t;
  for(auto &nx : g[t]){
    dfs(nx,l+1,g);
  }
  nrep[l]=-1;
}

int query(int a,int b){
  int ah,bh,dh,i,st,fi,te;
  if(dist[a]<dist[b]){i=a;a=b;b=i;}
  ah=dist[a];
  bh=dist[b];
  dh=ah-bh;
  for(i=29;i>=0;i--){
    if((dh&(1<<i)) != 0){
      a=doubling[a][i];
    }
  }
  while(a!=b){
    st=0;fi=29;
    while(st<=fi){
      te=(st+fi)/2;
      if(doubling[a][te]==doubling[b][te]){fi=te-1;}
      else{st=te+1;}
    }
    if(fi==-1){
      return doubling[a][0];
    }
    a=doubling[a][fi];
    b=doubling[b][fi];
  }
  return a;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m,k;
  cin >> n >> m >> k;
  UnionFind uf(n+1);
  Graph g(n+1);
  vector<pi> eg;

  for(int i=0;i<m;i++){
    int u,v;
    cin >> u >> v;
    if(uf.findSet(u,v)){
      eg.push_back({u,v});
    }
    else{
      uf.unionSet(u,v);
      g[u].push_back(v);
      g[v].push_back(u);
    }
  }

  lca_init();
  dfs(1,0,g);

  if(n-1==m){
    vector<int> b,w;
    for(int i=1;i<=n;i++){
      if(dist[i]%2){b.push_back(i);}
      else{w.push_back(i);}
    }
    if(b.size()<w.size()){swap(b,w);}
    cout << 1 << '\n';
    int vc=(k+1)/2;
    for(int i=0;i<vc;i++){
      if(i){cout << ' ';}
      cout << b[i];
    }cout << '\n';
  }
  else{
    int en=-1,cl=1e9;
    for(int i=0;i<eg.size();i++){
      int a=eg[i].first;
      int b=eg[i].second;
      int w=query(a,b);
      int curl=dist[a]+dist[b]-2*dist[w]+1;
      if(cl>curl){
        cl=curl;
        en=i;
      }
    }

    vector<int> l1,l2;
    int a=eg[en].first;
    int b=eg[en].second;
    int w=query(a,b);
    //cout << a << ' ' << b << ' ' << w << '\n';
    while(a!=w){
      l1.push_back(a);
      a=doubling[a][0];
    }
    l1.push_back(w);
    while(b!=w){
      l2.push_back(b);
      b=doubling[b][0];
    }
    while(!l2.empty()){
      l1.push_back(l2.back());
      l2.pop_back();
    }

    if(l1.size()<=k){
      cout << 2 << '\n';
      cout << l1.size() << '\n';
      for(int i=0;i<l1.size();i++){
        if(i){cout << ' ';}
        cout << l1[i];
      }cout << '\n';
    }
    else{
      cout << 1 << '\n';
      int vc=(k+1)/2;
      for(int i=0;i<vc;i++){
        if(i){cout << ' ';}
        cout << l1[2*i];
      }cout << '\n';
    }
  }

  return 0;
}