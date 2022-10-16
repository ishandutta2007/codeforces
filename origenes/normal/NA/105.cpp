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
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 212345;
const ll inf = 0x3f3f3f3f3f3f3f3f;

struct Edge {
  int u, v, w;
} e[maxn];

struct Seg {
  int l, r;
  ll val;
} T[maxn << 2];

int n, m, q, sz;
vector<int> G[maxn];
int pre[maxn], idx[maxn], lo[maxn], hi[maxn];
bool vis[maxn];
ll dis[maxn][2];

void build(int o, int l, int r) {
  T[o].l = l, T[o].r = r;
  T[o].val = inf;
  if (l < r) {
    int mi = l + r >> 1;
    build(o << 1, l, mi);
    build(o << 1 | 1, mi + 1, r);
  }
}

void upd(int o, int l, int r, ll val) {
  if (r < l) return;
  if (l <= T[o].l && T[o].r <= r) {
    chkmin(T[o].val, val);
    return;
  }
  int mi = T[o].l + T[o].r >> 1;
  if (l <= mi) upd(o << 1, l, r, val);
  if (r > mi) upd(o << 1 | 1, l, r, val);
}

ll query(int o, int x) {
  if (T[o].l == T[o].r) return T[o].val;
  int mi = T[o].l + T[o].r >> 1;
  return min(T[o].val, query(o << 1 | (x > mi), x));
}

int main() {
  scanf("%d%d%d", &n, &m, &q);
  FOR(i, 1, m) {
    scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
    G[e[i].u].eb(i);
    G[e[i].v].eb(i);
  }
  FOR(i, 1, n - 1) dis[i][0] = inf;
  set<pair<ll, int>> que;
  que.emplace(0, n);
  while (!que.empty()) {
    auto now = *que.begin(); que.erase(now);
    int u = now._2;
    ll d = now._1;
    if (dis[u][0] < d) continue;
    for (auto i : G[u]) {
      int v = e[i].u == u ? e[i].v : e[i].u, w = e[i].w;
      if (dis[v][0] > d + w) {
        dis[v][0] = d + w;
        pre[v] = i;
        que.emplace(dis[v][0], v);
      }
    }
  }
  for (int u = 1; u; ) {
    vis[u] = true;
    const Edge &now = e[pre[u]];
    lo[u] = sz;
    if (now.w) idx[pre[u]] = ++sz;
    hi[u] = sz;
    u = now.u == u ? now.v : now.u;
  }
  hi[n]++;
  reset(dis, 0x3f);
  que.emplace(0, 1);
  dis[1][0] = 0;
  while (!que.empty()) {
    auto now = *que.begin(); que.erase(now);
    int u = now._2;
    ll d = now._1;
    if (dis[u][0] < d) continue;
    for (auto i : G[u]) {
      int v = e[i].u == u ? e[i].v : e[i].u, w = e[i].w;
      if (dis[v][0] > d + w) {
        dis[v][0] = d + w;
        pre[v] = i;
        if (!vis[v]) lo[v] = lo[u];
        que.emplace(dis[v][0], v);
      }
    }
  }
  dis[n][1] = 0;
  que.emplace(0, n);
  while (!que.empty()) {
    auto now = *que.begin(); que.erase(now);
    int u = now._2;
    ll d = now._1;
    if (dis[u][1] < d) continue;
    for (auto i : G[u]) {
      int v = e[i].u == u ? e[i].v : e[i].u, w = e[i].w;
      if (dis[v][1] > d + w) {
        dis[v][1] = d + w;
        pre[v] = i;
        if (!vis[v]) hi[v] = hi[u];
        que.emplace(dis[v][1], v);
      }
    }
  }
  build(1, 1, sz);
  FOR(i, 1, m) if (!idx[i]) {
    upd(1, lo[e[i].u] + 1, hi[e[i].v] - 1, dis[e[i].u][0] + dis[e[i].v][1] + e[i].w);
    upd(1, lo[e[i].v] + 1, hi[e[i].u] - 1, dis[e[i].v][0] + dis[e[i].u][1] + e[i].w);
  }
  while (q--) {
    int t, x;
    scanf("%d%d", &t, &x);
    ll ans = inf;
    if (idx[t]) {
      chkmin(ans, dis[n][0] - e[t].w + x);
      if (x > e[t].w) chkmin(ans, query(1, idx[t]));
    } else {
      ans = dis[n][0];
      chkmin(ans, dis[e[t].u][0] + dis[e[t].v][1] + x);
      chkmin(ans, dis[e[t].v][0] + dis[e[t].u][1] + x);
    }
    printf("%lld\n", ans);
  }
}