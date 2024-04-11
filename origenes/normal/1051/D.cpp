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

const int maxn = 1123;
const int MOD = 998244353;

int dp[maxn][2 * maxn][4];
int n, k;

void upd(int &a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}

int main() {
  scanf("%d%d", &n, &k);
  dp[1][1][0] = dp[1][1][3] = 1;
  dp[1][2][1] = dp[1][2][2] = 1;
  FOR(i, 2, n) FOR(j, 1, k) REP(mask, 4) {
    dp[i][j][mask] = dp[i - 1][j][mask];
    if (!mask || mask == 3) {
      upd(dp[i][j][mask], dp[i - 1][j][1]);
      upd(dp[i][j][mask], dp[i - 1][j][2]);
      upd(dp[i][j][mask], dp[i - 1][j - 1][mask ^ 3]);
    } else {
      upd(dp[i][j][mask], dp[i - 1][j - 1][0]);
      upd(dp[i][j][mask], dp[i - 1][j - 1][3]);
      if (j > 2) upd(dp[i][j][mask], dp[i - 1][j - 2][mask ^ 3]);
    }
  }
  int ans = 0;
  REP(mask, 4) upd(ans, dp[n][k][mask]);
  printf("%d", ans);
}