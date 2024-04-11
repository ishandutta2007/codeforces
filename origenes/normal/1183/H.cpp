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

const int maxn = 112;

ll dp[maxn][maxn][26], dp2[maxn][maxn], k, ans;
int n;
char s[maxn];

int main() {
  scanf("%d%lld", &n, &k);
  scanf("%s", s + 1);
  FOR(i, 1, n) {
    dp[i][1][s[i] - 'a'] = 1;
    FOR(j, 1, i) {
      REP(ch, 26) {
        if (ch == s[i] - 'a') dp[i][j][ch] += dp2[i - 1][j - 1];
        else dp[i][j][ch] += dp[i - 1][j][ch];
        chkmin(dp[i][j][ch], k);
        dp2[i][j] += dp[i][j][ch];
      }
      chkmin(dp2[i][j], k);
    }
  }
  dp2[n][0] = 1;
  ROF(i, n, 0) {
    if (dp2[n][i] > k) {
      ans += k * (n - i);
      k = 0;
      break;
    }
    ans += dp2[n][i] * (n - i);
    k -= dp2[n][i];
  }
  if (k) puts("-1");
  else printf("%lld", ans);
}