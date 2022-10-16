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

const int maxn = 312345;

int n, clk, ans;
vector<int> G1[maxn], G2[maxn];
int in[maxn], out[maxn];
set<pii> clique;

void dfs2(int u, int par) {
  in[u] = ++clk;
  for (auto v : G2[u]) if (v != par) dfs2(v, u);
  out[u] = clk;
}

struct Seg {
  int l, r;
  int v, pos;
} T[maxn << 2];

void push_up(int o) {
  T[o].v = T[o << 1].v, T[o].pos = T[o << 1].pos;
  if (T[o << 1 | 1].v > T[o << 1].v) {
    T[o].v = T[o << 1 | 1].v;
    T[o].pos = T[o << 1 | 1].pos;
  }
}

void build(int o, int l, int r) {
  T[o].l = l, T[o].r = r;
  if (l == r) {
    T[o].v = 0;
    T[o].pos = l;
  } else {
    int mi = l + r >> 1;
    build(o << 1, l, mi);
    build(o << 1 | 1, mi + 1, r);
    push_up(o);
  }
}

void update(int o, int x, int v) {
  if (T[o].l == T[o].r) {
    T[o].v = v;
    return;
  }
  int mi = T[o].l + T[o].r >> 1;
  if (x <= mi) update(o << 1, x, v);
  else update(o << 1 | 1, x, v);
  push_up(o);
}

pii query(int o, int l, int r) {
  if (l <= T[o].l && T[o].r <= r) return {T[o].v, T[o].pos};
  int mi = T[o].l + T[o].r >> 1;
  pii ret = {-1, -1};
  if (l <= mi) chkmax(ret, query(o << 1, l, r));
  if (r > mi) chkmax(ret, query(o << 1 | 1, l, r));
  return ret;
}

void dfs1(int u, int par) {
  auto it = clique.lower_bound(mp(in[u], out[u]));
  pii del = {-1, -1};
  if (it == clique.end() || it->_1 > out[u]) {
    auto [o, p] = query(1, 1, in[u]);
    if (o >= out[u] && clique.count(mp(p, o))) {
      clique.erase(mp(p, o));
      update(1, p, 0);
      del = {p, o};
    }
    clique.emplace(in[u], out[u]);
    update(1, in[u], out[u]);
  }
  for (auto v : G1[u]) if (v != par) dfs1(v, u);
  if (G1[u].empty()) chkmax(ans, int(clique.size()));
  clique.erase(mp(in[u], out[u]));
  update(1, in[u], 0);
  if (del._1 != -1) {
    clique.emplace(del);
    update(1, del._1, del._2);
  }
}

void solve() {
  cin >> n;
  FOR(i, 1, n) G1[i].clear(), G2[i].clear();
  FOR(i, 2, n) {
    int p; cin >> p;
    G1[p].eb(i);
  }
  FOR(i, 2, n) {
    int p; cin >> p;
    G2[p].eb(i);
  }
  clk = ans = 0;
  clique.clear();
  dfs2(1, 0);
  build(1, 1, clk);
  dfs1(1, 0);
  cout << ans << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int ts; cin >> ts;
  while (ts--) solve();
}