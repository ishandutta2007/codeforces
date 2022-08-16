#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<string> a(n);
	for (auto &s : a) {
		cin >> s;
		auto it = remove_if(s.begin(), s.end(), [&](char c) {
			return c == '{' || c == '}';
		});
		s.erase(it, s.end());
	}

	vector<vector<int>> g(n * m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == '<') {
				g[i * m + j - 1].push_back(i * m + j);
			} else if (a[i][j] == '>') {
				g[i * m + j + 1].push_back(i * m + j);
			} else if (a[i][j] == '^') {
				g[(i - 1) * m + j].push_back(i * m + j);
			} else if (a[i][j] == 'v') {
				g[(i + 1) * m + j].push_back(i * m + j);
			}
		}
	}

	bool cycle = false;
	vector<int> dp(n * m, -1), cnt(n * m);
	vector<bool> active(n * m);

	auto dfs = [&](int x, const auto &self) -> void {
		dp[x] = 0, cnt[x] = 1;
		active[x] = true;
		for (int i : g[x]) {
			cycle |= active[i];
			if (dp[i] == -1) {
				self(i, self);
			}
			if (1 + dp[i] > dp[x]) {
				dp[x] = 1 + dp[i], cnt[x] = 1;
			} else if (1 + dp[i] == dp[x]) {
				cnt[x] += 1;
			}
		}
		active[x] = false;
	};

	for (int i = 0; i < n * m; i++) {
		if (dp[i] == -1) {
			dfs(i, dfs);
		}
	}

	if (cycle) {
		cout << "-1\n";
		return 0;
	}

	int mx = *max_element(dp.begin(), dp.end());
	int c = 0;

	for (int i = 0; i < n * m; i++) {
		if (dp[i] == mx) {
			c += cnt[i];
		}
	}

	if (mx == 0) {
		cout << 0 << '\n';
	} else {
		cout << (c > 1 ? 2 * mx : 2 * mx - 1) << '\n';
	}
	return 0;
}