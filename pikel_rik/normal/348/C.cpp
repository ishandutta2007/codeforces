#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	constexpr int N = 100000;

	int n, m, q;
	cin >> n >> m >> q;

	vector<long long> a(n);
	for (auto &x : a) cin >> x;

	vector<int> sz(m);
	vector<vector<int>> s(m);
	for (int i = 0; i < m; i++) {
		cin >> sz[i];
		s[i].resize(sz[i]);
		for (auto &x : s[i]) {
			cin >> x, --x;
		}
	}

	vector<vector<pair<int, int>>> v(m);
	vector<bool> mark(n);

	for (int i = 0; i < m; i++) {
		if ((long long)sz[i] * sz[i] <= N)
			continue;
		for (int x : s[i])
			mark[x] = true;
		for (int j = 0; j < m; j++) {
			int inter = 0;
			for (int x : s[j])
				inter += mark[x];
			v[j].emplace_back(i, inter);
		}
		for (int x : s[i])
			mark[x] = false;
	}

	vector<long long> sum(m), update(m);
	for (int i = 0; i < m; i++) {
		for (auto &x : s[i]) {
			sum[i] += a[x];
		}
	}

	while (q--) {
		char c;
		cin >> c;

		if (c == '?') {
			int k;
			cin >> k, --k;
			long long ans = 0;
			if ((long long)sz[k] * sz[k] <= N) {
				for (int i : s[k]) {
					ans += a[i];
				}
				for (auto &[j, c] : v[k]) {
					ans += update[j] * c;
				}
			} else {
				ans = sum[k];
			}
			cout << ans << '\n';
		} else {
			int k, x;
			cin >> k >> x, --k;
			update[k] += x;
			if ((long long)sz[k] * sz[k] <= N) {
				for (int i : s[k]) {
					a[i] += x;
				}
			}
			for (auto &[j, c] : v[k]) {
				sum[j] += (long long)x * c;
			}
		}
	}
	return 0;
}