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

const int maxn = 112345;

vector<int> G[maxn];
vector<pii> query[maxn];
int c[maxn], n, m, ans[maxn], f[maxn], heavy[maxn], fen[maxn], g[maxn];

inline int lowbit(int x) {
  return x & -x;
}

void add(int x, int d) {
  if (x == 0) return;
  while (x <= n) {
    fen[x] += d;
    x += lowbit(x);
  }
}

int sum(int x) {
  int ret = 0;
  while (x > 0) {
    ret += fen[x];
    x -= lowbit(x);
  }
  return ret;
}

void dfs1(int u, int par) {
  for (auto v : G[u]) if (v != par) {
    dfs1(v, u);
    f[u] += f[v];
    if (f[v] > f[heavy[u]]) heavy[u] = v;
  }
  f[u]++;
}

void update(int x, int d) {
  add(g[x], -1);
  g[x] += d;
  add(g[x], 1);
}

void redo(int u, int par) {
  update(c[u], -1);
  for (auto v : G[u]) if (v != par) redo(v, u);
}

void Merge(int u, int par) {
  update(c[u], 1);
  for (auto v : G[u]) if (v != par) Merge(v, u);
}

void dfs2(int u, int par) {
  for (auto v : G[u]) if (v != par && v != heavy[u]) {
    dfs2(v, u);
    redo(v, u);
  }
  if (heavy[u]) dfs2(heavy[u], u);
  for (auto v : G[u]) if (v != par && v != heavy[u]) Merge(v, u);
  update(c[u], 1);
  for (auto q : query[u]) {
    int k = q._1, id = q._2;
    if (k <= f[u]) ans[id] = sum(f[u]) - sum(k - 1);
  }
}

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) scanf("%d", c + i);
  REP(i, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].eb(v); G[v].eb(u);
  }
  FOR(i, 1, m) {
    int v, k;
    scanf("%d%d", &v, &k);
    query[v].eb(k, i);
  }
  dfs1(1, 0);
  dfs2(1, 0);
  FOR(i, 1, m) printf("%d\n", ans[i]);
}