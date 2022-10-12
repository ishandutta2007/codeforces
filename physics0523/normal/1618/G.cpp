#include<bits/stdc++.h>

using namespace std;
using pl=pair<long long,long long>;

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

  int n,m,q;
  cin >> n >> m >> q;
  vector<long long> a(n),b(m),p;
  for(auto &nx : a){
    cin >> nx;
    p.push_back(nx);
  }
  for(auto &nx : b){
    cin >> nx;
    p.push_back(nx);
  }

  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  p.push_back(0);
  sort(p.begin(),p.end());

  int tt=n+m;
  vector<long long> rw(tt+1,0);
  for(int i=1;i<=tt;i++){
    rw[i]=rw[i-1];
    rw[i]+=p[i];
  }

  vector<long long> cnt(tt+1,0);
  vector<long long> mx(tt+1);
  for(int i=0;i<=tt;i++){mx[i]=i;}
  int pt=n-1;
  long long res=0;
  for(int i=tt;(i>=1 && pt>=0);i--){
    if(a[pt]==p[i]){
      //cerr << pt << ' ' << i << '\n';
      res+=a[pt];
      cnt[i]=1;
      pt--;
    }
  }

  vector<pl> qv(q),mv;
  for(int i=0;i<q;i++){
    cin >> qv[i].first;
    qv[i].second=i;
  }
  sort(qv.begin(),qv.end());
  for(int i=2;i<=tt;i++){
    mv.push_back({p[i]-p[i-1],i});
  }
  sort(mv.begin(),mv.end());

  UnionFind uf(tt+1);
  vector<long long> resv(q);
  int tg=0;

  //cerr << res << '\n';
  for(int i=0;i<q;i++){
    int ck=qv[i].first;
    int cid=qv[i].second;
    //cerr << ck << '\n';
    while(tg<mv.size() && mv[tg].first<=ck){
      int u=mv[tg].second-1,v=mv[tg].second;
      //cerr << u << ' ' << v << '\n';
      u=uf.root(u);
      v=uf.root(v);
      if(u==v){tg++;continue;}

      res-=(rw[mx[u]]-rw[mx[u]-cnt[u]]);
      res-=(rw[mx[v]]-rw[mx[v]-cnt[v]]);
      uf.unionSet(u,v);
      int nr=uf.root(u);

      int nmx=max(mx[u],mx[v]);
      mx[u]=0;mx[v]=0;
      mx[nr]=nmx;

      int ncnt=cnt[u]+cnt[v];
      cnt[u]=0;cnt[v]=0;
      cnt[nr]=ncnt;

      res+=(rw[mx[nr]]-rw[mx[nr]-cnt[nr]]);
      tg++;
    }
    resv[cid]=res;
  }

  for(int i=0;i<q;i++){
    cout << resv[i] << '\n';
  }
  return 0;
}