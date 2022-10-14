#include <bits/stdc++.h>
using namespace std;
using lint = long long;

void Main() {
  int K;
  cin >> K;
  vector<lint> F(6);
  for (int i = 0; i < 6; i++) {
    cin >> F[i];
  }

  const int M = 1e6 + 5;
  vector<lint> dp(M, -1e18);

  dp[0] = 0;
  for (int f = 0, t = 1; f < 6; f++, t *= 10) {
    lint can = (K - 1) * 3;
    lint g = 1;
    while (can > 0) {
      g = min(g, can);
      can -= g;
      for (int i = M - 1; i >= 3ll * t * g; i--) {
        dp[i] = max(dp[i], dp[i - 3 * t * g] + 1ll * g * F[f]);
      }
      g *= 2;
    }
  }

  for (int f = 0, t = 1; f < 6; f++, t *= 10) {
    for (int i = M - 1; i >= 0; i--) {
      for (int d = 0; d < 10; d++) {
        if (i >= d * t) {
          dp[i] = max(dp[i], dp[i - d * t] + (d % 3 == 0 ? ((d / 3) * F[f]) : 0));
        }
      }
    }
  }

  int Q;
  cin >> Q;
  while (Q--) {
    int N;
    cin >> N;
    cout << dp[N] << "\n";
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  // cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}