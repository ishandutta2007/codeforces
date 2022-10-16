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
const int maxm = 1123456;

struct Edge {
  int id, w, u, v;

  bool operator < (const Edge &rhs) const {
    return w < rhs.w;
  }
};

vector<pii> G[maxn];
int anc[maxn][18], mx[maxn][18], mn[maxn][18], par[maxn], ans[maxm], dep[maxn];
int n, m;

void dfs(int u, int p, int w) {
  anc[u][0] = p;
  mx[u][0] = w;
  mn[u][0] = 1e9;
  dep[u] = dep[p] + 1;
  FOR(i, 1, 17) {
    anc[u][i] = anc[anc[u][i - 1]][i - 1];
    mx[u][i] = max(mx[anc[u][i - 1]][i - 1], mx[u][i - 1]);
    mn[u][i] = 1e9;
  }
  for (auto _ : G[u]) if (_._1 != p) dfs(_._1, u, _._2);
}

int Find(int x) {
  return par[x] == x ? x : par[x] = Find(par[x]);
}

int main() {
  scanf("%d%d", &n, &m);
  vector<Edge> edges(m);
  REP(i, m) {
    auto &x = edges[i];
    scanf("%d%d%d", &x.u, &x.v, &x.w);
    x.id = i;
  }
  sort(all(edges));
  iota(par + 1, par + n + 1, 1);
  set<int> vis;
  for (auto x : edges) {
    int u = Find(x.u), v = Find(x.v), w = x.w, id = x.id;
    if (u == v) continue;
    par[u] = v;
    G[x.u].eb(x.v, w);
    G[x.v].eb(x.u, w);
    vis.emplace(id);
  }
  dfs(1, 0, 0);
  reset(ans, -1);
  for (auto x : edges) if (!vis.count(x.id)) {
      int u = x.u, v = x.v;
      if (dep[u] > dep[v]) swap(u, v);
      int now = 0;
      ROF(i, 17, 0) if (dep[anc[v][i]] >= dep[u]) {
          chkmax(now, mx[v][i]);
          chkmin(mn[v][i], x.w);
          v = anc[v][i];
        }
      if (v == u) {
        ans[x.id] = now;
        continue;
      }
      ROF(i, 17, 0) if (anc[u][i] != anc[v][i]) {
          chkmax(now, mx[u][i]);
          chkmax(now, mx[v][i]);
          chkmin(mn[u][i], x.w);
          chkmin(mn[v][i], x.w);
          u = anc[u][i], v = anc[v][i];
        }
      chkmax(now, max(mx[u][0], mx[v][0]));
      chkmin(mn[u][0], x.w);
      chkmin(mn[v][0], x.w);
      ans[x.id] = now;
    }
  ROF(j, 17, 1) FOR(i, 1, n) {
    chkmin(mn[i][j - 1], mn[i][j]);
    chkmin(mn[anc[i][j - 1]][j - 1], mn[i][j]);
  }
  sort(all(edges), [&](const Edge &a, const Edge &b) { return a.id < b.id; });
  REP(i, m) {
    if (ans[i] == -1) {
      int u = edges[i].u, v = edges[i].v;
      ans[i] = anc[u][0] == v ? mn[u][0] : mn[v][0];
    }
    printf("%d\n", ans[i]);
  }
}