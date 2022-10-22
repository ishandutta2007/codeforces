#include <bits/stdc++.h>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x) begin(x),end(x)

using namespace std;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;

struct UnionFind {
  vector<int> parent;
  UnionFind (int n) : parent(n, -1) {}
  int root(int x) { return parent[x] < 0 ? x : parent[x] = root(parent[x]); }
  bool merge(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return false;
    if (parent[y] < parent[x]) swap(x, y);
    if (parent[x] == parent[y]) --parent[x];
    parent[y] = x;
    return true;
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,m,t;
  cin>>n>>m>>t;
  vector<string> mat(n);
  REP(i,n)cin>>mat[i];
  UnionFind uf(n*m);
  int di[] = {1,0,-1,0};
  int dj[] = {0,1,0,-1};
  auto id = [&] (int i, int j) {
    return i * m + j;
  };
  vector<vector<tuple<int,int>>> g(n*m);
  REP(i,n)REP(j,m) {
    REP(k,4) {
      int ni=i+di[k];
      int nj=j+dj[k];
      if (ni<0||ni>=n||nj<0||nj>=m) continue;
      if (mat[i][j] == mat[ni][nj]) {
        uf.merge(id(i,j), id(ni,nj));
        g[id(i,j)].emplace_back(id(ni,nj), 0);
        g[id(ni,nj)].emplace_back(id(i,j), 0);
      } else {
        g[id(i,j)].emplace_back(id(ni,nj), 1);
        g[id(ni,nj)].emplace_back(id(i,j), 1);
      }
    }
  }
  map<int,int> sz;
  REP(i,n)REP(j,m) {
    ++sz[uf.root(id(i,j))];
  }
  ll INF = 3e18;
  vecll dist(n*m, INF);
  deque<int> dq;
  REP(i,n)REP(j,m) {
    if (sz[uf.root(id(i,j))] > 1) {
      dist[id(i,j)] = 0;
      dq.push_back(id(i,j));
    }
  }
  while (!dq.empty()) {
    int id = dq.front();
    dq.pop_front();
    for (auto&&[to, cost]:g[id]) {
      if (dist[to] > dist[id] + cost) {
        dist[to] = dist[id] + cost;
        if (cost == 0) {
          dq.push_front(to);
        } else {
          dq.push_back(to);
        }
      }
    }
  }
  REP(qry,t) {
    ll i,j,p;
    cin>>i>>j>>p;
    --i;--j;
    if (p <= dist[id(i,j)]) {
      cout<<mat[i][j]<<"\n";
    } else {
      if ((p - dist[id(i,j)]) % 2 == 1) {
        cout<<char(mat[i][j]^1)<<"\n";
      } else {
        cout<<mat[i][j]<<"\n";
      }
    }
  }
  return 0;
}