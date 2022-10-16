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

const int maxn = 14;

int dp[1 << maxn], n, m, ver[maxn][maxn][1 << maxn];  // prev_end
pair<pii, int> pre[1 << maxn];  // in out mask
bool valid[maxn][maxn][1 << maxn];
vector<int> G[maxn];

int main() {
  scanf("%d%d", &n, &m);
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    G[u].eb(v);
    G[v].eb(u);
  }
  REP(u, n) for (int v : G[u]) valid[u][v][0] = true;
  REP(mask, 1 << n) REP(i, n) REP(j, n) {
    if (!valid[i][j][mask]) continue;
    for (int k : G[i]) if (!(mask & (1 << k)) && !valid[k][j][mask | (1 << i)] && (mask || k != j)) {
      ver[k][j][mask | (1 << i)] = i;
      valid[k][j][mask | (1 << i)] = true;
    }
  }
  reset(dp, 0x3f);
  FOR(mask, 1, (1 << n) - 1) {
    int cnt = __builtin_popcount(mask);
    if (cnt == 1) {
      dp[mask] = 0;
      pre[mask] = {{-1, -1}, 0};
      continue;
    }
    for (int sub = mask & (mask - 1); sub; sub = mask & (sub - 1)) {
      int rem = mask ^ sub, inc = __builtin_popcount(rem) + 1;
      REP(i, n) if (sub & (1 << i)) {
        REP(j, n) if (sub & (1 << j)) {
          if (valid[i][j][rem] && dp[sub] + inc < dp[mask]) {
            dp[mask] = dp[sub] + inc;
            pre[mask] = {{i, j}, rem};
          }
        }
      }
    }
  }
  printf("%d\n", dp[(1 << n) - 1]);
  for (int mask = (1 << n) - 1; __builtin_popcount(mask) > 1; ) {
    int u = pre[mask]._1._1, v = pre[mask]._1._2, rem = pre[mask]._2;
    for (int sub = rem; sub; ) {
      int nxt = ver[u][v][sub];
      printf("%d %d\n", u + 1, nxt + 1);
      sub ^= 1 << nxt;
      u = nxt;
    }
    printf("%d %d\n", u + 1, v + 1);
    mask = mask ^ rem;
  }
}