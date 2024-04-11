#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n = 2, m;
		cin >> m;

		vector<vector<int>> a(n, vector<int>(m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
			}
		}

		vector<vector<int>> pref(n, vector<int>(m));
		for (int i = 0; i < n; i++) {
			partial_sum(a[i].begin(), a[i].end(), pref[i].begin());
		}

		int ans = INT_MAX;
		for (int down = 0; down < m; down++) {
			int upper = (down + 1 == m ? 0 : pref[0][m - 1] - pref[0][down]);
			int lower = (down == 0 ? 0 : pref[1][down - 1]);
			ans = min(ans, max(upper, lower));
		}
		cout << ans << '\n';
	}
	return 0;
}