#include <bits/stdc++.h>
#include <variant>

#define rep2(i,k,n) for(i64 i=(i64)(k);i<(i64)(n);i++)
#define rep(i,n) rep2(i,0,n)
#define all(x) begin(x),end(x)
#ifdef ENV_LOCAL
#define dump if (1) cerr
#else
#define dump if (0) cerr
#endif

using namespace std;
using namespace std::string_literals;

using i32 = int32_t;
using i64 = int64_t;
using f64 = double;
using f80 = long double;
using vi32 = vector<i32>;
using vi64 = vector<i64>;

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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  i32 t;
  cin>>t;
  while(t--) {
    i32 n,m;
    cin>>n>>m;
    vector<vi32> g(n);
    UnionFind uf(n);
    rep(i,m) {
      i32 u,v;
      cin>>u>>v;
      --u;--v;
      uf.merge(u,v);
      g[u].push_back(v);
      g[v].push_back(u);
    }
    set<i32> s;
    rep(i,n) s.insert(uf.root(i));
    if (size(s) > 1) {
      cout<<"NO\n";
      continue;
    }
    vector<bool> vis(n, false);
    vector<bool> ng(n, false);
    vi32 ans;
    queue<i32> q;
    q.push(0);
    vis[0] = true;
    while (!q.empty()) {
      i32 idx = q.front();
      q.pop();
      if (!ng[idx]) ans.push_back(idx);
      for (auto&& to : g[idx]) {
        if (!ng[idx]) ng[to] = true;
        if (vis[to]) continue;
        vis[to] = true;
        q.push(to);
      }
    }
    cout<<"YES\n";
    i32 k = size(ans);
    cout<<k<<"\n";
    rep(i,k) {
      if (i) cout<<" ";
      cout<<(ans[i]+1);
    }
    cout<<"\n";
  }
  return 0;
}