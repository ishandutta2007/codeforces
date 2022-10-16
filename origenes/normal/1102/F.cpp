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

const int maxn = 16;
const int maxm = 11234;
const int inf = 0x3f3f3f3f;

int n, m, a[maxn][maxm], ans;
int dp[1 << maxn][maxn][maxn], G[maxn][maxn], adj[maxn][maxn];

void dfs(int mask, int st, int en) {
  if (dp[mask][st][en] != -1) return;
  int &ret = dp[mask][st][en];
  if (mask == (1 << n) - 1) {
    ret = adj[st][en];
    return;
  }
  REP(i, n) if (!(mask & (1 << i))) {
      dfs(mask | (1 << i), st, i);
      chkmax(ret, min(dp[mask | (1 << i)][st][i], G[en][i]));
    }
}

int main() {
  scanf("%d%d", &n, &m);
  REP(i, n) FOR(j, 1, m) scanf("%d", &a[i][j]);
  if (n == 1) {
    ans = inf;
    FOR(i, 2, m) chkmin(ans, abs(a[0][i] - a[0][i - 1]));
    printf("%d", ans);
    return 0;
  }
  REP(i, n) FOR(j, i + 1, n - 1) {
      int val = inf;
      FOR(k, 1, m) chkmin(val, abs(a[i][k] - a[j][k]));
      G[i][j] = G[j][i] = val;
    }
  REP(i, n) REP(j, n) if (i != j) {
        adj[i][j] = inf;
        FOR(k, 2, m) chkmin(adj[i][j], abs(a[i][k] - a[j][k - 1]));
      }
  reset(dp, -1);
  REP(i, n) dfs(1 << i, i, i);
  REP(i, n) REP(j, n) chkmax(ans, dp[1 << i][i][j]);
  printf("%d", ans);
}