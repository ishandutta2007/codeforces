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

	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	vector<vector<int>> g(n);
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<int> dp(n), ans(n);
	auto dfs = [&](int x, int p, const auto &self) -> void {
		dp[x] = a[x] ? 1 : -1;
		for (int i : g[x]) {
			if (i == p) continue;
			self(i, x, self);
			dp[x] += max(0, dp[i]);
		}
	};

	auto reroot = [&](int x, int p, const auto &self) -> void {
		for (int i : g[x]) {
			if (i == p) continue;
			ans[i] = dp[i] + max(0, ans[x] - max(0, dp[i]));
			self(i, x, self);
		}
	};

	dfs(0, -1, dfs);
	ans[0] = dp[0];
	reroot(0, -1, reroot);

	for (int i = 0; i < n; i++) {
		cout << ans[i] << " \n"[i + 1 == n];
	}
	return 0;
}