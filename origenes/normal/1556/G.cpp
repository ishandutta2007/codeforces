#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 5123456;
const int maxm = 51234;

int n, m, tot = 1;
int par[maxn], tag[maxn], lson[maxn], rson[maxn];
vector<int> idx[maxm], G[maxn];

bool leaf(int u) {
  return !lson[u] && !rson[u];
}

int loc(int o, ll l, ll r, ll x) {
  if (leaf(o)) return o;
  ll mi = l + r >> 1;
  if (x <= mi) return loc(lson[o], l, mi, x);
  else return loc(rson[o], mi + 1, r, x);
}

void push_down(int o) {
  if (!lson[o]) lson[o] = ++tot;
  if (!rson[o]) rson[o] = ++tot;
  if (tag[o]) {
    tag[lson[o]] = tag[rson[o]] = tag[o];
    tag[o] = 0;
  }
}

void update(int o, ll l, ll r, ll L, ll R, int clk) {
  if (L <= l && r <= R) {
    tag[o] = clk;
    return;
  }
  push_down(o);
  ll mi = l + r >> 1;
  if (L <= mi) update(lson[o], l, mi, L, R, clk);
  if (R > mi) update(rson[o], mi + 1, r, L, R, clk);
}

void dfs(int o, ll l, ll r) {
  if (leaf(o)) {
    idx[tag[o]].eb(o);
    return;
  }
  push_down(o);
  ll mi = l + r >> 1;
  dfs(lson[o], l, mi);
  dfs(rson[o], mi + 1, r);
}

void build(int u, int v) {
  if (leaf(u) && leaf(v)) {
    tag[u] < tag[v] ? G[u].eb(v) : G[v].eb(u);
    return;
  }
  if (leaf(u)) {
    build(u, lson[v]);
    build(u, rson[v]);
  } else if (leaf(v)) {
    build(v, lson[u]);
    build(v, rson[u]);
  } else {
    build(lson[u], lson[v]);
    build(rson[u], rson[v]);
  }
}

int Find(int x) {
  return par[x] == x ? x : par[x] = Find(par[x]);
}

void Union(int u, int v) {
  u = Find(u), v = Find(v);
  if (u != v) par[u] = v;
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> m;
  vector<tuple<string, ll, ll>> ops;
  FOR(i, 1, m) {
    string op;
    ll l, r;
    cin >> op >> l >> r;
    ops.eb(op, l, r);
  }
  tag[1] = m + 1;
  ROF(i, m - 1, 0) {
    auto [s, l, r] = ops[i];
    if (s == "block") update(1, 0, (1LL << n) - 1, l, r, i + 1);
  }
  dfs(1, 0, (1LL << n) - 1);
  FOR(i, 1, tot) if (!leaf(i)) build(lson[i], rson[i]);
  iota(par + 1, par + tot + 1, 1);
  for (auto u : idx[m + 1]) for (auto v : G[u]) Union(u, v);
  vector<int> ans;
  ROF(i, m - 1, 0) {
    auto [s, l, r] = ops[i];
    if (s == "block") for (auto u : idx[i + 1]) for (auto v : G[u]) Union(u, v);
    else {
      l = loc(1, 0, (1LL << n) - 1, l), r = loc(1, 0, (1LL << n) - 1, r);
      ans.eb(Find(l) == Find(r));
    }
  }
  reverse(all(ans));
  for (auto x : ans) cout << x << '\n';
}