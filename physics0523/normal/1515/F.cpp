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

using pi=pair<int,int>;
using Graph=vector<queue<pi>>;
using pli=pair<long long,int>;

void ms(queue<pi> &mt,queue<pi> &mf){
  if(mt.size()<mf.size()){swap(mt,mf);}
  while(!mf.empty()){mt.push(mf.front());mf.pop();}
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  long long x;
  cin >> x;

  UnionFind uf(n);
  vector<long long> a(n);
  for(int i=0;i<n;i++){cin >> a[i];}
  Graph g(n);
  vector<int> res;

  for(int i=0;i<m;i++){
    int u,v;
    cin >> u >> v;
    u--;v--;
    g[u].push({v,i+1});
    g[v].push({u,i+1});
  }

  priority_queue<pli> pq;
  for(int i=0;i<n;i++){
    if(uf.root(i)==i && a[i]!=0){pq.push({a[i],i});}
  }
  while(!pq.empty() && res.size()<(n-1)){
    pli od=pq.top();pq.pop();
    if(a[od.second]!=od.first){continue;}
    int cv=od.second;
    bool fl=false;
    while(!g[cv].empty()){
      int od=g[cv].front().first;
      int oid=g[cv].front().second;
      g[cv].pop();
      if(uf.findSet(cv,od)){continue;}
      int ru=uf.root(cv);
      int rv=uf.root(od);
      if(a[ru]+a[rv]>=x){
        res.push_back(oid);
        uf.unionSet(ru,rv);
        if(uf.root(ru)==ru){
          ms(g[ru],g[rv]);
          a[ru]+=a[rv];
          a[ru]-=x;
          a[rv]=0;
        }
        else{
          ms(g[rv],g[ru]);
          a[rv]+=a[ru];
          a[rv]-=x;
          a[ru]=0;
        }
        fl=true;
        break;
      }
    }
    if(fl){
      int ru=uf.root(cv);
      if(a[ru]>0){pq.push({a[ru],ru});}
    }
  }
  if(res.size()==n-1){
    cout << "YES\n";
    for(auto &nx : res){cout << nx << '\n';}
  }
  else{cout << "NO\n";}
  return 0;
}