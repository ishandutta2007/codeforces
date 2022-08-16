#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;

	vector<int> c(n);
	for (auto &x : c) cin >> x;

	vector<vector<int>> p(n, vector<int>(m + 1));
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> p[i][j];
		}
	}

	constexpr long long inf = 1e15;
	vector<vector<long long>> dp(k + 1, vector<long long>(m + 1, inf));

	if (c[n - 1] > 0) {
		dp[1][c[n - 1]] = 0;
	} else {
		for (int j = 1; j <= m; j++) {
			dp[1][j] = p[n - 1][j];
		}
	}

	for (int i = n - 2; i >= 0; i--) {
		vector<vector<long long>> new_dp(k + 1, vector<long long>(m + 1, inf));
		if (c[i] > 0) {
			for (int ii = 0; ii <= k; ii++) {
				for (int jj = 0; jj <= m; jj++) {
					bool f = c[i] != jj;
					if (ii + f <= k) {
						new_dp[ii + f][c[i]] = min(new_dp[ii + f][c[i]], dp[ii][jj]);
					}
				}
			}
		} else {
			for (int col = 1; col <= m; col++) {
				for (int ii = 0; ii <= k; ii++) {
					for (int jj = 0; jj <= m; jj++) {
						bool f = col != jj;
						if (ii + f <= k) {
							new_dp[ii + f][col] = min(new_dp[ii + f][col], p[i][col] + dp[ii][jj]);
						}
					}
				}
			}
		}
		dp.swap(new_dp);
	}

	long long ans = inf;
	for (int j = 1; j <= m; j++) {
		ans = min(ans, dp[k][j]);
	}

	cout << (ans == inf ? -1 : ans) << '\n';
	return 0;
}