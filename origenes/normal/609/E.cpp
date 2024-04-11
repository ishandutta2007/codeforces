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

typedef pair<pii, pii> Edge;

vector<pii> G[maxn];
Edge e[maxn];
int n, m, p[maxn], st[maxn][18], dep[maxn], bit[18], mmax[maxn][18];
set<int> ids;
ll mst, ans[maxn];

int Find(int x) {
  return p[x] == x ? x : p[x] = Find(p[x]);
}

void dfs(int u, int par, int w) {
  dep[u] = dep[par] + 1;
  st[u][0] = par;
  mmax[u][0] = w;
  FOR(i, 1, 17) {
    st[u][i] = st[st[u][i - 1]][i - 1];
    mmax[u][i] = max(mmax[u][i - 1], mmax[st[u][i - 1]][i - 1]);
  }
  for (auto _ : G[u]) {
    int v = _._1, ww = _._2;
    if (v == par) continue;
    dfs(v, u, ww);
  }
}

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, m) {
    scanf("%d%d%d", &e[i]._2._1, &e[i]._2._2, &e[i]._1._1);
    e[i]._1._2 = i;
  }
  sort(e + 1, e + m + 1);
  FOR(i, 1, n) p[i] = i;
  FOR(i, 1, m) {
    int u = Find(e[i]._2._1), v = Find(e[i]._2._2);
    if (u == v) continue;
    p[u] = v;
    mst += e[i]._1._1;
    ids.emplace(i);
  }
  for (auto i : ids) {
    int u = e[i]._2._1, v = e[i]._2._2, w = e[i]._1._1;
    G[u].eb(v, w);
    G[v].eb(u, w);
  }
  REP(i, 18) bit[i] = 1 << i;
  dfs(1, 0, 0);
  FOR(i, 1, m) {
    int u = e[i]._2._1, v = e[i]._2._2, w = e[i]._1._1, id = e[i]._1._2;
    if (ids.count(i)) {
      ans[id] = mst;
      continue;
    }
    if (dep[u] > dep[v]) swap(u, v);
    int now = 0;
    ROF(j, 17, 0) if (dep[v] - dep[u] >= bit[j]) {
      chkmax(now, mmax[v][j]);
      v = st[v][j];
    }
    if (u == v) {
      ans[id] = mst - now + w;
      continue;
    }
    ROF(j, 17, 0) if (st[u][j] != st[v][j]) {
      chkmax(now, mmax[u][j]);
      chkmax(now, mmax[v][j]);
      u = st[u][j], v = st[v][j];
    }
    chkmax(now, mmax[u][0]);
    chkmax(now, mmax[v][0]);
    ans[id] = mst - now + w;
  }
  FOR(i, 1, m) printf("%lld\n", ans[i]);
}