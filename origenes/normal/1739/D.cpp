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

const int maxn = 212345;

struct Seg {
  int l, r;
  bool v;
} T[maxn << 2];

vector<int> G[maxn];
int in[maxn], out[maxn], anc[maxn][18], dep[maxn], ids[maxn];
int n, k, clk;

void dfs(int u, int par) {
  if (u != 1) dep[u] = dep[par] + 1;
  anc[u][0] = par;
  FOR(i, 1, 17) anc[u][i] = anc[anc[u][i - 1]][i - 1];
  in[u] = ++clk;
  for (auto v : G[u]) dfs(v, u);
  out[u] = clk;
}

void build(int o, int l, int r) {
  T[o].l = l, T[o].r = r;
  T[o].v = false;
  if (l < r) {
    int mi = l + r >> 1;
    build(o << 1, l, mi);
    build(o << 1 | 1, mi + 1, r);
  }
}

bool query(int o, int x) {
  if (T[o].v) return true;
  if (T[o].l == T[o].r) return false;
  int mi = T[o].l + T[o].r >> 1;
  return x <= mi ? query(o << 1, x) : query(o << 1 | 1, x);
}

void update(int o, int l, int r) {
  if (T[o].v) return;
  if (l <= T[o].l && T[o].r <= r) {
    T[o].v = true;
    return;
  }
  int mi = T[o].l + T[o].r >> 1;
  if (l <= mi) update(o << 1, l, r);
  if (r > mi) update(o << 1 | 1, l, r);
}

bool check(int h) {
  build(1, 1, n);
  int have = k;
  auto jump = [](int u, int x) {
    ROF(i, 17, 0) if (x & (1 << i)) u = anc[u][i];
    return u;
  };
  FOR(i, 1, n) {
    int u = ids[i];
    if (dep[u] <= h) return true;
    if (query(1, in[u])) continue;
    if (have == 0) return false;
    int v = jump(u, h - 1);
    have--;
    update(1, in[v], out[v]);
  }
  assert(0);
}

void solve() {
  cin >> n >> k;
  FOR(i, 1, n) G[i].clear();
  clk = 0;
  FOR(i, 2, n) {
    int p; cin >> p;
    G[p].eb(i);
  }
  dfs(1, 0);
  iota(ids + 1, ids + n + 1, 1);
  sort(ids + 1, ids + n + 1, [](int x, int y) { return dep[x] > dep[y]; });
  int lo = 1, hi = *max_element(dep + 1, dep + n + 1);
  while (lo < hi) {
    int mi = lo + hi >> 1;
    if (check(mi)) hi = mi;
    else lo = mi + 1;
  }
  cout << lo << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int tc; cin >> tc;
  while (tc--) solve();
}