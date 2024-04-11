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

const int maxn = 501;
const int inf = 1e9 + 1;

int n, x, cnt;
int dis[maxn][maxn];
bool c[maxn];
vector<pii> G[maxn];
short f[maxn][maxn], g[maxn][maxn][maxn], sz[maxn];

void dfs(int u, int par) {
  for (auto _ : G[u]) if (_._1 != par) dfs(_._1, u);
  REP(i, n) if (dis[u][i] <= x) {
    sz[u] = 1;
    g[u][i][1] = 1 - c[i];
    for (auto _ : G[u]) if (_._1 != par) {
      int v = _._1;
      ROF(j, min(sz[u] + sz[v], cnt), 0) {
        short now = n + 1, st = max(j - sz[u], 0);
        FOR(k, st, min(j, 1 * sz[v])) chkmin(now, short(min(g[u][i][j - k] + f[v][k], k == st ? n + 1 : g[u][i][j - k + 1] + g[v][i][k] - 1 + c[i])));
        g[u][i][j] = now;
      }
      sz[u] += sz[v];
    }
  }
  FOR(i, 1, min(short(cnt), sz[u])) REP(j, n) chkmin(f[u][i], g[u][j][i]);
}

int main() {
  scanf("%d%d", &n, &x);
  reset(dis, 0x3f); reset(f, 0x3f); reset(g, 0x3f);
  REP(i, n) {
    int ch; scanf("%d", &ch);
    c[i] = ch;
    cnt += c[i];
  }
  REP(i, n - 1) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    u--, v--;
    G[u].eb(v, w); G[v].eb(u, w);
    dis[u][v] = dis[v][u] = w;
  }
  REP(i, n) dis[i][i] = 0;
  REP(k, n) REP(i, n) REP(j, n) {
    chkmin(dis[i][j], dis[i][k] + dis[k][j]);
    if (dis[i][j] > x) dis[i][j] = inf;
  }
  dfs(0, -1);
  printf("%d", f[0][cnt] > n ? -1 : f[0][cnt]);
}