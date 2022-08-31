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

		vector<int> sz(m), ans(m, -1), cnt(n);
		vector<vector<int>> f(m), occur(n);
		for (int i = 0; i < m; i++) {
			cin >> sz[i], f[i].resize(sz[i]);
			for (int j = 0; j < sz[i]; j++) {
				cin >> f[i][j], --f[i][j];
			}
			sort(f[i].begin(), f[i].end());
			ans[i] = f[i][0];
			cnt[ans[i]] += 1;
		}

		int mx = max_element(cnt.begin(), cnt.end()) - cnt.begin();

		for (int i = 0; i < m; i++) {
			if (cnt[mx] > (m + 1) / 2 && ans[i] == mx && sz[i] > 1) {
				ans[i] = f[i][1];
				cnt[mx] -= 1;
			}
		}

		if (cnt[mx] > (m + 1) / 2) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
			for (int i : ans) cout << i + 1 << ' ';
			cout << '\n';
		}
	}
	return 0;
}