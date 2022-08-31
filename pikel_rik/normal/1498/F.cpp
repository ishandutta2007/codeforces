#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	vector<vector<int>> g(n);
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v, --u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<int> a(n);
	for (auto &x : a) cin >> x;

	vector<vector<int>> dp(n, vector<int>(2 * k));
	auto dfs = [&](int x, int p, const auto &self) -> void {
		dp[x][0] = a[x];
		for (int i : g[x]) {
			if (i == p)
				continue;
			self(i, x, self);
			for (int j = 1; j < 2 * k; j++) {
				dp[x][j] ^= dp[i][j - 1];
			}
			dp[x][0] ^= dp[i].back();
		}
	};

	dfs(0, -1, dfs);

	vector<int> ans(n);
	auto reroot = [&](int x, int p, const vector<int> &v, const auto &self) -> void {
		vector<int> new_v(2 * k);
		for (int j = 1; j < 2 * k; j++) {
			new_v[j] = v[j - 1];
		}
		new_v[0] = a[x] ^ v.back();

		for (int i : g[x]) {
			if (i == p)
				continue;
			for (int j = 1; j < 2 * k; j++) {
				new_v[j] ^= dp[i][j - 1];
			}
			new_v[0] ^= dp[i].back();
		}

		for (int j = k; j < 2 * k; j++) {
			ans[x] ^= new_v[j];
		}

		for (int i : g[x]) {
			if (i == p)
				continue;
			for (int j = 1; j < 2 * k; j++) {
				new_v[j] ^= dp[i][j - 1];
			}
			new_v[0] ^= dp[i].back();
			self(i, x, new_v, self);
			for (int j = 1; j < 2 * k; j++) {
				new_v[j] ^= dp[i][j - 1];
			}
			new_v[0] ^= dp[i].back();
		}
	};

	reroot(0, -1, vector<int>(2 * k), reroot);
	for (int i = 0; i < n; i++) {
		cout << !!ans[i] << " \n"[i + 1 == n];
	}
	return 0;
}