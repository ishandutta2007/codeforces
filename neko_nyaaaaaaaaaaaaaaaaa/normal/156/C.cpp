#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll M = 1e9+7;
ll dp[200][10000];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	for (int i = 1; i <= 26; i++) {
            dp[1][i] = 1;
	}
	for (int i = 2; i <= 100; i++) {
            for (int j = i; j <= 26*i; j++) {
                  for (int k = 1; k <= 26; k++) {
                        if (j - k <= 0) break;
                        dp[i][j] = (dp[i][j] + dp[i-1][j-k]) % M;
                  }
            }
	}

      int t; cin >> t;
      while (t--) {
            string s; cin >> s;
            int sum = 0;
            int n = s.size();
            for (int i = 0; i < n; i++) {
                  sum += s[i] - 'a' + 1;
            }
            ll ans = dp[n][sum] - 1;
            if (ans < 0) ans += M;
            cout << ans << '\n';
      }

	return 0;
}