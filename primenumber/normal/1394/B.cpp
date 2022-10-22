#include <bits/stdc++.h>
#include <variant>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x) begin(x),end(x)

using namespace std;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;

struct Edge {
  ll s, d, w;
};

bool operator<(const Edge& l, const Edge& r) {
  return l.w < r.w;
}

using Edges = vector<Edge>;
using Graph = vector<Edges>;

int solve(const vector<bitset<81>>& mat, int k, int idx, bitset<81> bits) {
  if (idx == k) return 1;
  int sum = 0;
  REP(i,idx+1) {
    int x = idx*9 + i;
    if ((mat[x] & bits).any()) {
      continue;
    }
    if (mat[x].test(x)) continue;
    auto nx = bits;
    nx.set(x);
    sum += solve(mat, k, idx+1, nx);
  }
  return sum;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,m,k;
  cin>>n>>m>>k;
  Graph g(n);
  REP(i,m) {
    ll u,v,w;
    cin>>u>>v>>w;
    --u;--v;
    g[u].push_back({u,v,w});
  }
  vector<vector<tuple<int,int>>> gt(n);
  REP(i,n) {
    sort(ALL(g[i]));
    int sz = size(g[i]);
    REP(j,sz) {
      gt[g[i][j].d].emplace_back(sz-1, j);
    }
  }
  vector<bitset<81>> mat(81);
  REP(i,n) {
    sort(ALL(gt[i]));
    int sz1 = size(gt[i]);
    REP(j,sz1-1) {
      if (gt[i][j] != gt[i][j+1]) continue;
      auto[px,qx] = gt[i][j];
      mat[px*9+qx][px*9+qx] = true;
    }
    gt[i].erase(unique(ALL(gt[i])), end(gt[i]));
    int sz = size(gt[i]);
    REP(x,sz)REP(y,sz) {
      if (x == y) continue;
      auto[px,qx] = gt[i][x];
      auto[py,qy] = gt[i][y];
      mat[px*9+qx][py*9+qy] = true;
    }
  }
  int ans = solve(mat, k, 0, bitset<81>());
  cout<<ans<<endl;
  return 0;
}