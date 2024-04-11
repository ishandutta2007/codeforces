#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<long long> c(n);
		for (auto &x : c) cin >> x;

		vector<vector<int>> g(n);
		for (int i = 0, u, v; i < m; i++) {
			cin >> u >> v, --u, --v;
			g[v].push_back(u);
		}

		map<vector<int>, long long> mp;
		for (int i = 0; i < n; i++) {
			if (!g[i].empty()) {
				sort(g[i].begin(), g[i].end());
				mp[g[i]] += c[i];
			}
		}

		long long ans = 0;
		for (auto &[v, sum] : mp) {
			ans = __gcd(ans, sum);
		}
		cout << ans << '\n';
	}
	return 0;
}