#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int m, k;
		cin >> m >> k;

		vector<int> a(k);
		for (auto &x : a) cin >> x;

		vector<int> ind(k);
		iota(ind.begin(), ind.end(), 0);
		sort(ind.begin(), ind.end(), [&](int i, int j) {
			return a[i] > a[j];
		});

		int n;
		for (n = 1;; n++) {
			int empty = (n / 2) * (n / 2);
			int rows = ((n + 1) / 2) * n;
			if (n * n - empty >= m && rows >= a[ind[0]]) {
				break;
			}
		}

		vector<vector<int>> ans(n, vector<int>(n));

		int cur_i = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n && cur_i < k; j++) {
				if (i % 2 == 0 && j % 2 != 0) {
					ans[i][j] = ind[cur_i] + 1;
					a[ind[cur_i]] -= 1;
					while (cur_i < k && a[ind[cur_i]] == 0) {
						cur_i += 1;
					}
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n && cur_i < k; j++) {
				if (i % 2 == 0 && j % 2 == 0) {
					ans[i][j] = ind[cur_i] + 1;
					a[ind[cur_i]] -= 1;
					while (cur_i < k && a[ind[cur_i]] == 0) {
						cur_i += 1;
					}
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n && cur_i < k; j++) {
				if (i % 2 != 0 && j % 2 == 0) {
					ans[i][j] = ind[cur_i] + 1;
					a[ind[cur_i]] -= 1;
					while (cur_i < k && a[ind[cur_i]] == 0) {
						cur_i += 1;
					}
				}
			}
		}

		cout << n << '\n';
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << ans[i][j] << ' ';
			}
			cout << '\n';
		}
	}
	return 0;
}