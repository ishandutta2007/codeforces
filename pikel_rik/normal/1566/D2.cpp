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

		vector<int> a(n * m);
		for (auto &x : a) cin >> x;

		map<int, vector<int>> mp;
		for (int i = 0; i < n * m; i++) {
			mp[a[i]].push_back(i);
		}

		vector<int> pos(n * m);

		int r = 0, c = 0;
		for (auto &[x, v] : mp) {
			int sz = (int) v.size();
			for (int k = 0; k < sz;) {
				int left_over = sz - k;
				if (c + left_over < m) {
					for (int j = c + left_over - 1; j >= c; j--) {
						pos[v[k++]] = r * m + j;
					}
					c += left_over;
				} else {
					for (int j = m - 1; j >= c; j--) {
						pos[v[k++]] = r * m + j;
					}
					r += 1, c = 0;
				}
			}
		}

		vector<vector<int>> pref(n, vector<int>(m));

		long long ans = 0;
		for (int i = 0; i < n * m; i++) {
			int row = pos[i] / m, col = pos[i] % m;
			ans += pref[row][col];
			for (int j = col; j < m; j++) {
				pref[row][j] += 1;
			}
		}

		cout << ans << '\n';
	}
	return 0;
}