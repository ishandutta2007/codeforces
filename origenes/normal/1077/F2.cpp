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

const int maxn = 5123;

ll dp[maxn][maxn], ans = -1;
int a[maxn], n, k, x;

int main() {
  scanf("%d%d%d", &n, &k, &x);
  FOR(i, 1, n) scanf("%d", a + i);
  reset(dp, 0xc0);
  dp[0][0] = 0;
  FOR(i, 1, x) {
    deque<int> q;
    FOR(j, 1, n) {
      while (!q.empty() && q.front() < j - k) q.pop_front();
      while (!q.empty() && dp[j - 1][i - 1] > dp[q.back()][i - 1]) q.pop_back();
      q.eb(j - 1);
      dp[j][i] = dp[q.front()][i - 1] + a[j];
    }
  }
  FOR(i, n - k + 1, n) chkmax(ans, dp[i][x]);
  printf("%lld", ans);
}