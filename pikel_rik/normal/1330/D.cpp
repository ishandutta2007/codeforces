#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int d;
		cin >> d >> mod;

		int msb = 32 - __builtin_clz(d) - 1;
		vector<vector<int>> dp(msb + 1, vector<int>(msb + 1));

		for (int j = 0; j <= msb; j++) {
			if ((1 << j) <= d) {
				if (j == msb) {
					dp[0][j] = (d + 1 - (1 << j)) % mod;
				} else {
					dp[0][j] = (1 << j) % mod;
				}
			}
		}
		for (int i = 1; i <= msb; i++) {
			for (int j = 0; j <= msb; j++) {
				for (int k = 0; k < j; k++) {
					dp[i][j] = (dp[i][j] + (ll)dp[0][j] * dp[i - 1][k]) % mod;
				}
			}
		}

		int ans = 0;
		for (int i = 0; i <= msb; i++) {
			for (int j = 0; j <= msb; j++) {
				ans = (ans + dp[i][j]) % mod;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}