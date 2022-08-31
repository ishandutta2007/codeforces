#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed << setprecision(12);

	int n, d;
	cin >> n >> d;

	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];

	vector<vector<double>> dp(n + 1, vector<double>(10, -1));
	vector<vector<pair<int, int>>> par(n + 1, vector<pair<int, int>>(10));

	for (int i = 1; i <= n; i++) {
		int cur = a[i] % 10;
		double lg = log(a[i]);
		for (int j = 0; j < 10; j++) {
			dp[i][j] = dp[i - 1][j];
			par[i][j] = {i - 1, j};
		}
		if (dp[i][cur] < lg) {
			dp[i][cur] = lg;
			par[i][cur] = {0, 1};
		}
		for (int j = 0; j < 10; j++) {
			if (dp[i - 1][j] != -1 && dp[i][cur * j % 10] < lg + dp[i - 1][j]) {
				dp[i][cur * j % 10] = lg + dp[i - 1][j];
				par[i][cur * j % 10] = {i - 1, j};
			}
		}
	}

	if (dp[n][d] == -1) {
		return cout << "-1\n", 0;
	}

	auto equal = [&](double x, double y) -> bool {
		return abs(x - y) < 1e-9;
	};

	vector<int> ans;
	for (int i = n, j = d; i != 0;) {
		double par_value = max(0.0, dp[par[i][j].first][par[i][j].second]);
		if (equal(dp[i][j], log(a[i]) + par_value)) {
			ans.push_back(a[i]);
		}
		tie(i, j) = par[i][j];
	}

	cout << ans.size() << '\n';
	for (auto &x : ans) cout << x << ' '; cout << '\n';
	return 0;
}