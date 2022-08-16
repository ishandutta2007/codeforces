#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 70 + 5;

int n, m, k, a[N][N], mx[N][N];
int dp[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		memset(dp, 0, sizeof(dp));
		for (int j = 0; j < m; j++) {
			for (int jj = m / 2 - 1; jj >= 0; jj--) {
				for (int md = 0; md < k; md++) {
					if (dp[jj][md]) {
						dp[jj + 1][(md + a[i][j]) % k] = max(dp[jj + 1][(md + a[i][j]) % k], dp[jj][md] + a[i][j]);
					}
				}
			}
			if (m / 2 >= 1) {
				dp[1][a[i][j] % k] = max(dp[1][a[i][j] % k], a[i][j]);
			}
		}
		for (int j = 0; j <= m / 2; j++) {
			for (int md = 0; md < k; md++) {
				mx[i][md] = max(mx[i][md], dp[j][md]);
			}
		}
	}

	memset(dp, 0, sizeof(dp));
	memcpy(dp[0], mx[0], sizeof(dp[0]));

	for (int i = 1; i < n; i++) {
		for (int md = 0; md < k; md++) {
			for (int mdd = 0; mdd < k; mdd++) {
				dp[i][mdd] = max(dp[i][mdd], dp[i - 1][mdd]);
				if (mx[i][md] && dp[i - 1][mdd]) {
					dp[i][(mdd + md) % k] = max(dp[i][(mdd + md) % k], mx[i][md] + dp[i - 1][mdd]);
				}
			}
		}
		for (int md = 0; md < k; md++) {
			dp[i][md] = max(dp[i][md], mx[i][md]);
		}
	}
	cout << dp[n - 1][0] << '\n';
	return 0;
}