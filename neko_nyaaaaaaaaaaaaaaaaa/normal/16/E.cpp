#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

      int n; cin >> n;
      vector<vector<double>> a(n, vector<double>(n));
      for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                  cin >> a[i][j];
            }
      }

      vector<double> dp(1000000, 0);
      dp[(1 << n) - 1] = 1;
      for (int i = (1LL << n) - 1; i >= 0; i--) {
            int b = __builtin_popcount(i);
            for (int j = 0; j < n; j++) {
                  if ((1 << j) & i) {
                        for (int k = 0; k < n; k++) {
                              if (k != j && ((1 << k) & i)) {
                                    dp[i - (1 << k)] += dp[i]*a[j][k]*2/b/(b-1);
                              }
                        }
                  }
            }
      }

      for (int i = 0; i < n; i++) {
            cout << fixed << setprecision(12) << dp[(1 << i)] << " ";
      }

	return 0;
}