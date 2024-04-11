#include <bits/stdc++.h>
#include <variant>
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

void dfs(const vector<vecint>& g, vecint& idx, int i, int p = -1) {
  idx.push_back(i);
  for (auto&& to : g[i]) {
    if (to == p) continue;
    dfs(g, idx, to, i);
    idx.push_back(i);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n,m,k;
  cin>>n>>m>>k;
  UnionFind uf(n);
  vector<vecint> g(n);
  REP(i,m) {
    int x,y;
    cin>>x>>y;
    --x;--y;
    if (uf.root(x) == uf.root(y)) continue;
    g[x].push_back(y);
    g[y].push_back(x);
    uf.merge(x,y);
  }
  if (n == 1) {
    cout<<"1 1\n";
    return 0;
  }
  vecint idx;
  dfs(g, idx, 0);
  idx.pop_back();
  ll x = (n-1) * 2;
  REP(i,k) {
    ll start = i * x / k;
    ll end = (i+1) * x / k;
    cout << (end - start);
    REP(j,end-start) {
      cout<<" "<<idx[(start + j) % x]+1;
    }
    cout<<"\n";
  }
  return 0;
}