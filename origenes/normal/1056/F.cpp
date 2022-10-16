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

const int maxn = 112;
const double inf = 1e12;

double C, T;
int n, tc;
pii task[maxn];
double dp[maxn][maxn][10 * maxn], pw[maxn];

int main() {
  scanf("%d", &tc);
  pw[0] = 1;
  FOR(i, 1, 100) pw[i] = 0.9 * pw[i - 1];
  while (tc--) {
    scanf("%d%lf%lf", &n, &C, &T);
    FOR(i, 1, n) scanf("%d%d", &task[i]._1, &task[i]._2);
    sort(task + 1, task + n + 1, [](pii a, pii b) { return a._1 > b._1; } );
    REP(i, n + 1) REP(j, n + 1) REP(k, 10 * n + 1) dp[i][j][k] = inf;
    REP(i, n + 1) dp[i][0][0] = 0;
    FOR(i, 1, n) FOR(j, 1, i) FOR(k, 1, 10 * j) {
      dp[i][j][k] = dp[i - 1][j][k];
      if (k >= task[i]._2) chkmin(dp[i][j][k], dp[i - 1][j - 1][k - task[i]._2] + task[i]._1 / pw[j]);
    }
    ROF(j, 10 * n, 1) FOR(i, 1, n) if (dp[n][i][j] < 5e11) {
      double t = (sqrt(dp[n][i][j] * C) - 1) / C;
      if (t > T) continue;
      if (t < 0) t = 0;
      double cost = 10 * i + dp[n][i][j] / (1 + C * t) + t;
      if (cost <= T + 1e-5) {
        printf("%d\n", j);
        goto label;
      }
    }
    puts("0");
    label:;
  }
}