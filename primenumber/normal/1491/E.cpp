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

i32 fibs[31];

i32 dfs(const vector<vi32>& g, vi32& sz, vi32& vp, i32 i, i32 p=-1) { 
  vp[i] = p;
  i32 ans = 1;
  for (auto&& to : g[i]) {
    if (to == p) continue;
    ans += dfs(g, sz, vp, to, i);
  }
  sz[i] = ans;
  return ans;
}

void fill_ct(const vector<vi32>& g, vi32& nt, i32 i, i32 p) {
  nt.push_back(i);
  for (auto&& to : g[i]) {
    if (to == p) continue;
    fill_ct(g, nt, to, i);
  }
}

vector<vi32> split_tree(const vector<vi32>& g, const vi32& t1) {
  i32 s1 = size(t1);
  i32 n = size(g);
  vi32 t1_map(n, -1);
  rep(i,s1) {
    t1_map[t1[i]] = i;
  }
  vector<vi32> g1(s1);
  rep(i,n) {
    if (t1_map[i] < 0) continue;
    i32 idx = t1_map[i];
    g1[idx].reserve(size(g[i]));
    for (auto&& to : g[i]) {
      if (t1_map[to] < 0) continue;
      g1[idx].push_back(t1_map[to]);
    }
  }
  return g1;
}

bool is_fibtree(const vector<vi32>& g) {
  i32 n = size(g);
  if (n <= 3) return true;
  i32 idx = 0;
  while (idx < 30) {
    if (fibs[idx] > n) return false;
    if (fibs[idx] == n) break;
    ++idx;
  }
  i32 leaf = -1;
  rep(i,n) {
    if (g[i].size() == 1) leaf = i;
  }
  vi32 sz(n);
  vi32 vp(n);
  dfs(g, sz, vp, leaf);
  i32 spt = -1;
  rep(i,n) {
    if (sz[i] == fibs[idx-1] || sz[i] == fibs[idx-2]) {
      spt = i;
    }
  }
  if (spt == -1) return false;
  i32 s1 = sz[spt];
  vi32 t1;
  t1.reserve(s1);
  fill_ct(g, t1, spt, vp[spt]);
  vi32 tp(n, 0);
  for(auto&&e:t1) tp[e] = 1;
  t1.clear();
  vi32 t2;
  t2.reserve(n - s1);
  rep(i,n) {
    if (tp[i]) t1.push_back(i);
    else t2.push_back(i);
  }
  return is_fibtree(split_tree(g, t1)) && is_fibtree(split_tree(g, t2));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  fibs[0] = 1;
  fibs[1] = 1;
  rep2(i,2,31) {
    fibs[i] = fibs[i-1] + fibs[i-2];
  }
  i32 n;
  cin>>n;
  vector<vi32> g(n);
  rep(i,n-1) {
    i32 u,v;
    cin>>u>>v;
    --u;--v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  bool ans = is_fibtree(g);
  if (ans) {
    cout<<"YES\n";
  } else {
    cout<<"NO\n";
  }
  return 0;
}