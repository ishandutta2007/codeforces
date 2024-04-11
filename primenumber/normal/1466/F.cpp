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
  constexpr i64 mod = 1'000'000'007;
  i32 n,m;
  cin>>n>>m;
  vi32 basis;
  UnionFind uf(m);
  vector<bool> cycle(m, false);
  rep(i,n) {
    i32 k;
    cin>>k;
    vi32 vp(k);
    rep(j,k) {
      cin>>vp[j];
      --vp[j];
    }
    if (k == 1) {
      i32 r = uf.root(vp[0]);
      if (!cycle[r]) {
        cycle[r] = true;
        basis.push_back(i);
      }
    } else {
      i32 r1 = uf.root(vp[0]);
      i32 r2 = uf.root(vp[1]);
      if (r1 != r2) {
        bool c = cycle[r1] || cycle[r2];
        bool eff = !(cycle[r1] && cycle[r2]);
        uf.merge(r1, r2);
        cycle[uf.root(r1)] = c;
        if (eff) basis.push_back(i);
      }
    }
  }
  i64 ans = 1;
  rep(i,size(basis)) {
    ans *= 2;
    ans %= mod;
  }
  cout<<ans<<" "<<size(basis)<<"\n";
  rep(i,size(basis)) {
    if (i) cout<<" ";
    cout<<(basis[i]+1);
  }
  cout<<"\n";
  return 0;
}