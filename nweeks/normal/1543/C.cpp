#include <bits/stdc++.h>
#include <iomanip>
#define int long long
using namespace std;
const double eps = 1e-9;

double solve2(double probLose, double probOther, double vol) {
  if (probLose == 1)
    return 1;
  return 1 + (1 - probLose) *
                 (probOther > vol ? solve2(probLose + vol, probOther - vol, vol)
                                  : 1);
}

const int MAX = 1000;
void solve() {
  double c, m, p, v;
  cin >> c >> m >> p >> v;

  vector<vector<double>> dp(MAX, vector<double>(MAX));
  dp[0][0] = 1;
  double ret = 0;
  for (int takeC = 0; takeC < MAX; ++takeC)
    for (int takeM = 0; takeM < MAX; ++takeM) {
      if (!dp[takeC][takeM])
        continue;
      double prob1 = c - takeC * v + takeM * v / 2.;
      double prob2 = m - takeM * v + takeC * v / 2.;
      double probLose = p + (takeC + takeM) * v / 2.;
      assert(probLose <= 1);

      ret += (1 + takeC + takeM) * dp[takeC][takeM] * probLose;
      if (prob1 > v + eps and takeC + 1 < MAX) {
        dp[takeC + 1][takeM] += dp[takeC][takeM] * prob1;
      }
      if (prob1 <= v + eps) {
        ret += prob1 *
               (takeM + takeC + 1 +
                solve2(probLose + prob1 / 2, prob2 + prob1 / 2, v)) *
               dp[takeC][takeM];
      }
      if (prob2 > v + eps and takeM + 1 < MAX) {
        dp[takeC][takeM + 1] += dp[takeC][takeM] * prob2;
      }
      if (prob2 <= v + eps)
        ret += prob2 *
               (takeM + takeC + 1 +
                solve2(probLose + prob2 / 2, prob1 + prob2 / 2, v)) *
               dp[takeC][takeM];
    }
  cout << setprecision(12) << fixed << ret << '\n';
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}