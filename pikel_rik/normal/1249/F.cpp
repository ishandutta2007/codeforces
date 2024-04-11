#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	if (k >= n - 1) {
		cout << *max_element(a.begin(), a.end()) << '\n';
		return 0;
	}

	vector<vector<int>> g(n);
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<vector<int>> dp(n, vector<int>(n));
	vector<vector<int>> suf(n, vector<int>(n));

	++k;

	auto dfs = [&](int x, int p, const auto &dfs) -> void {
		dp[x][0] = a[x];
		for (int i : g[x]) {
			if (i == p) continue;
			dfs(i, x, dfs);
			dp[x][0] += suf[i][k - 1];
		}

		for (int j = 1; j < n; j++) {
			int val = 0;
			for (int i : g[x]) {
				if (i == p) continue;
				val += suf[i][max(j - 1, k - j - 1)];
			}

			for (int i : g[x]) {
				if (i == p) continue;
				dp[x][j] = max(dp[x][j], dp[i][j - 1] + val - suf[i][max(j - 1, k - j - 1)]);
			}
		}

		suf[x][n - 1] = dp[x][n - 1];
		for (int j = n - 2; j >= 0; j--) {
			suf[x][j] = max(dp[x][j], suf[x][j + 1]);
		}
	};

	dfs(0, -1, dfs);

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, suf[i][0]);
	}
	cout << ans << '\n';
	return 0;
}