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

const int maxn = 9 * 840;

ll dp[9][11234], cnt[9], w;

int main() {
  scanf("%lld", &w);
  FOR(i, 1, 8) scanf("%lld", cnt + i);
  reset(dp, -1);
  dp[0][0] = 0;
  REP(i, 8) REP(j, maxn) if (dp[i][j] != -1) {
        int need = 840 / (i + 1);
        if (cnt[i + 1] < need) need = cnt[i + 1];
        REP(k, need + 1) chkmax(dp[i + 1][j + k * (i + 1)], dp[i][j] + (cnt[i + 1] - k) / (840 / (i + 1)));
      }
  ll ans = 0;
  REP(i, maxn) if (i <= w && dp[8][i] != -1)
      chkmax(ans, i + 840 * min(dp[8][i], (w - i) / 840));
  printf("%lld", ans);
}