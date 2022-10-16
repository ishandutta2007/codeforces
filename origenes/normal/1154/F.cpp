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

const int maxn = 212345;
const int maxk = 2123;
const ll inf = 1e15;

int a[maxn], elim[maxk];
ll s[maxk], dp[maxk], ans;
int n, m, k;

int main() {
  scanf("%d%d%d", &n, &m, &k);
  FOR(i, 1, n) scanf("%d", a + i);
  sort(a + 1, a + n + 1);
  FOR(i, 1, k) s[i] = s[i - 1] + a[i];
  while (m--) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x > k) continue;
    chkmax(elim[x], y);
  }
  FOR(i, 1, k) {
    if (!elim[i]) dp[i] = inf;
    else dp[i] = s[k] - s[k - i + elim[i]];
    FOR(j, 1, i - 1)
      if (elim[i - j]) chkmin(dp[i], dp[j] + s[k - j] - s[k - i + elim[i - j]]);
  }
  ans = s[k];
  FOR(i, 1, k) if (dp[i] < inf) chkmin(ans, dp[i] + s[k - i]);
  printf("%lld", ans);
}