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

const int maxn = 1123456;

char s[maxn], t[maxn];
int dp[maxn][8];
ll ans;

int main() {
  scanf("%s%s", s, t);
  int n = strlen(s), m = strlen(t);
  REP(i, n) s[i] %= 3;
  REP(i, m) t[i] %= 3;
  FOR(i, 1, n - 1) {
    REP(j, 8) dp[i][j] = dp[i - 1][j];
    if (s[i - 1] != s[i]) dp[i][(s[i - 1] > s[i]) * 4 + s[i - 1] + s[i]]++;
  }
  REP(i, 8) dp[n][i] = dp[n - 1][i];
  int lo = 0, hi = 0;
  REP(i, m) {
    if (i && t[i - 1] != t[i]) {
      int j = (t[i - 1] < t[i]) * 4 + t[i - 1] + t[i];
      ans += dp[lo][j] - dp[hi][j];
    }
    while (hi < n && s[hi] != t[i]) hi++;
    ans += hi - lo + 1 - (hi == n);
    if (hi < n) hi++;
    if (lo < hi && s[lo] == t[i]) lo++;
  }
  printf("%lld", ans);
}