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

const int MOD = 1e9 + 7;
const int maxn = 1123;

int n, dp[maxn * 2][maxn][2];

inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

int main() {
  scanf("%d", &n);
  dp[2 * n - 1][1][1] = 1;
  ROF(i, 2 * n - 2, 1) {
    int upp = min(i, 2 * n - i);
    REP(j, upp + 1) {
      if ((i ^ j) & 1) continue;
      if (!j) {
        dp[i][0][0] = dp[i + 1][1][1];
        dp[i][0][1] = add(dp[i + 1][1][0], 1);
      } else if (j == upp && j == min(2 * n - i, n)) {
        dp[i][j][0] = dp[i + 1][j - 1][1];
        dp[i][j][1] = add(dp[i + 1][j - 1][0], 1);
      } else {
        dp[i][j][0] = add(dp[i + 1][j - 1][1], dp[i + 1][j + 1][1]);
        int t1 = dp[i + 1][j - 1][0], t2 = -1;
        if (j + 1 <= 2 * n - i - 1) t2 = dp[i + 1][j + 1][0];
        if (t2 != -1) {
          if (t1 == dp[i + 1][j - 1][1]) dp[i][j][1] = add(t1, dp[i + 1][j + 1][1]);
          else dp[i][j][1] = add(t2, dp[i + 1][j - 1][1]);
        } else dp[i][j][1] = t1;
        dp[i][j][1] = add(dp[i][j][1], 1);
      }
    }
  }
  int ans = 0;
  if (dp[1][1][0] == dp[1][1][1]) ans = add(dp[1][1][0], 1);
  else ans = dp[1][1][1];
  printf("%d", ans);
}