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

const int maxn = 312345;
const int inf = 0x3f3f3f3f;

int dp[maxn][2], x[maxn], y[maxn];
int n, k;

int go(int ok0, int ok1, int have0, int have1) {
  int ret = inf;
  if (ok0 <= k) {
    int tot = ok0 + have0, sec = (tot + k - 1) / k - 1;
    if (have1 == sec) chkmin(ret, tot - sec * k);
    else if (have1 > sec && have1 <= ll(have0) * k) chkmin(ret, 1);
  }
  if (ok1 <= k) {
    int sec = (have0 + k - 1) / k - 1;
    if (have1 == sec) chkmin(ret, have0 - sec * k);
    else if (have1 > sec && have1 <= ll(have0 - 1) * k + (k - ok1)) chkmin(ret, 1);
  }
  return ret;
}

int main() {
  scanf("%d%d", &n, &k);
  FOR(i, 1, n) scanf("%d", x + i);
  FOR(i, 1, n) scanf("%d", y + i);
  FOR(i, 1, n) {
    dp[i][0] = go(dp[i - 1][0], dp[i - 1][1], x[i], y[i]);
    dp[i][1] = go(dp[i - 1][1], dp[i - 1][0], y[i], x[i]);
  }
  puts(dp[n][0] <= k || dp[n][1] <= k ? "YES" : "NO");
}