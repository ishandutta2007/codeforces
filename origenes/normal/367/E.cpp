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

const int maxn = 321;
const int MOD = 1e9 + 7;

int dp[2][maxn][maxn], n, m, x;

inline void upd(int &a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}

int main() {
  scanf("%d%d%d", &n, &m, &x);
  if (n > m) {
    puts("0");
    return 0;
  }
  dp[0][0][0] = 1;
  REP(i, m) {
    int now = i & 1, nxt = 1 - now;
    REP(j, n + 1) REP(k, j + 1) dp[nxt][j][k] = 0;
    REP(j, n + 1) REP(k, j + 1) {
        if (i + 1 != x) {
          upd(dp[nxt][j][k], dp[now][j][k]);
          if (k < j) upd(dp[nxt][j][k + 1], dp[now][j][k]);
        }
        if (j < n) {
          upd(dp[nxt][j + 1][k], dp[now][j][k]);
          upd(dp[nxt][j + 1][k + 1], dp[now][j][k]);
        }
      }
  }
  int ans = dp[m & 1][n][n];
  FOR(i, 1, n) ans = ll(ans) * i % MOD;
  printf("%d", ans);
}