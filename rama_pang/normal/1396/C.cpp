#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  long long n, r1, r2, r3, d;
  cin >> n >> r1 >> r2 >> r3 >> d;

  const long long inf = 1e18;
  vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(2, vector<long long>(2, inf)));
  dp[0][0][0] = 0;
  dp[0][0][1] = 0;
  dp[0][1][0] = 0;
  dp[0][1][1] = 0;

  for (int pos = 0; pos < n; pos++) {
    long long x;
    cin >> x;
    long long c0 = x * r1 + r3;
    long long c1 = min(c0, min(r2 + r1, x * r1 + r1 + r1));
    auto ckmin = [](long long &a, long long b) { a = min(a, b); };
    
    if (pos + 1 < n) {
      ckmin(dp[pos + 1][0][0], dp[pos][0][0] + c0);
      ckmin(dp[pos + 1][0][0], dp[pos][0][0] + c1 + 2 * d);
      ckmin(dp[pos + 1][0][1], dp[pos][0][0] + c1);

      ckmin(dp[pos + 1][1][0], dp[pos][0][1] + c0);
      ckmin(dp[pos + 1][1][0], dp[pos][0][1] + c1 + 2 * d);
      ckmin(dp[pos + 1][1][1], dp[pos][0][1] + c1);
      ckmin(dp[pos + 1][0][0], dp[pos][0][1] + c0 + 2 * d);
      ckmin(dp[pos + 1][0][0], dp[pos][0][1] + c1 + 2 * d);
      
      ckmin(dp[pos + 1][0][0], dp[pos][1][0] + c0 + 4 * d);
      ckmin(dp[pos + 1][0][0], dp[pos][1][0] + c1 + 4 * d);
      ckmin(dp[pos + 1][0][1], dp[pos][1][0] + c1 + 4 * d);

      ckmin(dp[pos + 1][0][0], dp[pos][1][1] + c0 + 4 * d);
      ckmin(dp[pos + 1][0][0], dp[pos][1][1] + c1 + 4 * d);
      
      ckmin(dp[pos + 1][0][1], dp[pos + 1][0][0]);
      ckmin(dp[pos + 1][1][0], dp[pos + 1][0][0]);
      ckmin(dp[pos + 1][1][1], dp[pos + 1][0][0]);
      ckmin(dp[pos + 1][1][1], dp[pos + 1][0][1]);
      ckmin(dp[pos + 1][1][1], dp[pos + 1][1][0]);

      dp[pos + 1][0][0] += d;
      dp[pos + 1][0][1] += d;
      dp[pos + 1][1][0] += d;
      dp[pos + 1][1][1] += d;
    } else {
      ckmin(dp[pos + 1][0][0], dp[pos][0][0] + c0);
      ckmin(dp[pos + 1][0][0], dp[pos][0][0] + c1 + 2 * d);
      ckmin(dp[pos + 1][0][1], dp[pos][0][0] + c1);

      ckmin(dp[pos + 1][1][0], dp[pos][0][1] + c0);
      ckmin(dp[pos + 1][1][0], dp[pos][0][1] + c1 + 2 * d);
      ckmin(dp[pos + 1][1][1], dp[pos][0][1] + c1);
      ckmin(dp[pos + 1][0][0], dp[pos][0][1] + c0 + 1 * d);
      ckmin(dp[pos + 1][0][0], dp[pos][0][1] + c1 + 2 * d);
      
      ckmin(dp[pos + 1][0][0], dp[pos][1][0] + c0 + 2 * d);
      ckmin(dp[pos + 1][0][0], dp[pos][1][0] + c1 + 4 * d);
      ckmin(dp[pos + 1][0][1], dp[pos][1][0] + c1 + 4 * d);

      ckmin(dp[pos + 1][0][0], dp[pos][1][1] + c0 + 2 * d);
      ckmin(dp[pos + 1][0][0], dp[pos][1][1] + c1 + 4 * d);
      
      ckmin(dp[pos + 1][0][1], dp[pos + 1][0][0]);
      ckmin(dp[pos + 1][1][0], dp[pos + 1][0][0]);
      ckmin(dp[pos + 1][1][1], dp[pos + 1][0][0]);
      ckmin(dp[pos + 1][1][1], dp[pos + 1][0][1]);
      ckmin(dp[pos + 1][1][1], dp[pos + 1][1][0]);
    }
  }

  cout << dp[n][0][0] << "\n";
  return 0;
}