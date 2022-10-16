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

const int maxn = 55;
const int inf = 0x3f3f3f3f;

int n, m, g1, g2, s1, s2;
int dis[maxn][maxn], fast[maxn], slow[maxn];
ll dp[maxn][maxn][maxn];
bool vis[3][maxn];

ll consider(int g, int b, int su, int sd) {
  reset(vis, 0);
  reset(dp, 0);
  FOR(i, 1, n) FOR(j, 1, n) if (i != j) {
        if (dis[i][j] <= g) vis[0][i] = true;
        if (dis[i][j] >= b) vis[2][i] = true;
        if (dis[i][j] > su && dis[i][j] < sd) vis[1][i] = true;
      }
  dp[0][0][0] = 1;
  FOR(i, 1, n) REP(j, i + 1) REP(k, i - j + 1) {
        if (vis[0][i] && j >= 1) dp[i][j][k] += dp[i - 1][j - 1][k];
        if (vis[1][i] && k >= 1) dp[i][j][k] += dp[i - 1][j][k - 1];
        if (vis[2][i]) dp[i][j][k] += dp[i - 1][j][k];
      }
  ll ret = 0;
  FOR(i, g1, g2) FOR(j, s1, s2) ret += dp[n][i][j];
  return ret;
}

int main() {
  scanf("%d%d", &n, &m);
  reset(dis, 0x3f);
  FOR(i, 1, n) dis[i][i] = 0;
  REP(i, m) {
    int u, v, c;
    scanf("%d%d%d", &u, &v, &c);
    dis[u][v] = dis[v][u] = c;
  }
  FOR(k, 1, n) FOR(i, 1, n) FOR(j, 1, n) chkmin(dis[i][j], dis[i][k] + dis[k][j]);
  FOR(i, 1, n) FOR(j, 1, n) if (dis[i][j] != inf) dis[i][j] = dis[i][j] * n + i;
  scanf("%d%d%d%d", &g1, &g2, &s1, &s2);
  FOR(i, 1, n) {
    int mmax = -inf, mmin = inf;
    FOR(j, 1, n) if (i != j) {
        chkmax(mmax, dis[i][j]);
        chkmin(mmin, dis[i][j]);
      }
    fast[i] = mmin, slow[i] = mmax;
  }
  ll ans = 0;
  FOR(i, 1, n) FOR(j, 1, n) {
      ans += consider(fast[i], slow[j], fast[i], slow[j]) - consider(fast[i] - 1, slow[j], fast[i], slow[j]);
      ans -= consider(fast[i], slow[j] + 1, fast[i], slow[j]) - consider(fast[i] - 1, slow[j] + 1, fast[i], slow[j]);
    }
  printf("%lld", ans);
}