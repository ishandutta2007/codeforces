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

	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<vector<int>> a(n, vector<int>(m));
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < m; j++) {
				a[i][j] = s[j] == '1';
			}
		}

		vector<vector<int>> ans;
		for (int i = 0; i < n - 2; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j]) {
					if (j + 1 < m) {
						ans.push_back({i, j, i + 1, j, i + 1, j + 1});
					} else {
						ans.push_back({i, j, i + 1, j, i + 1, j - 1});
					}
					for (int k = 0; k < 6; k += 2) {
						a[ans.back()[k]][ans.back()[k + 1]] = 1 - a[ans.back()[k]][ans.back()[k + 1]];
					}
				}
			}
		}

		for (int j = 0; j < m - 2; j++) {
			if (a[n - 2][j] && a[n - 1][j]) {
				ans.push_back({n - 2, j, n - 1, j, n - 1, j + 1});
				for (int k = 0; k < 6; k += 2) {
					a[ans.back()[k]][ans.back()[k + 1]] = 1 - a[ans.back()[k]][ans.back()[k + 1]];
				}
			} else if (a[n - 2][j]) {
				ans.push_back({n - 2, j, n - 2, j + 1, n - 1, j + 1});
				for (int k = 0; k < 6; k += 2) {
					a[ans.back()[k]][ans.back()[k + 1]] = 1 - a[ans.back()[k]][ans.back()[k + 1]];
				}
			} else if (a[n - 1][j]) {
				ans.push_back({n - 1, j, n - 2, j + 1, n - 1, j + 1});
				for (int k = 0; k < 6; k += 2) {
					a[ans.back()[k]][ans.back()[k + 1]] = 1 - a[ans.back()[k]][ans.back()[k + 1]];
				}
			}
		}

		for (int rep = 0; rep < 4; rep++) {
			int now = a[n - 2][m - 2] + a[n - 1][m - 2] + a[n - 2][m - 1] + a[n - 1][m - 1];
			if (now == 4) {
				ans.push_back({n - 2, m - 2, n - 1, m - 2, n - 2, m - 1});
				for (int k = 0; k < 6; k += 2) {
					a[ans.back()[k]][ans.back()[k + 1]] = 1 - a[ans.back()[k]][ans.back()[k + 1]];
				}
			} else if (now == 1 || now == 3) {
				int used = 0;
				ans.emplace_back();
				for (int i = n - 2; i < n; i++) {
					for (int j = m - 2; j < m; j++) {
						if (a[i][j]) {
							ans.back().push_back(i);
							ans.back().push_back(j);
						} else if (used < 3 - now) {
							ans.back().push_back(i);
							ans.back().push_back(j);
							used++;
						}
					}
				}
				for (int k = 0; k < 6; k += 2) {
					a[ans.back()[k]][ans.back()[k + 1]] = 1 - a[ans.back()[k]][ans.back()[k + 1]];
				}
			} else if (now == 2) {
				int used = 0;
				ans.emplace_back();
				for (int i = n - 2; i < n; i++) {
					for (int j = m - 2; j < m; j++) {
						if (!a[i][j]) {
							ans.back().push_back(i);
							ans.back().push_back(j);
						} else if (used < 3 - now) {
							ans.back().push_back(i);
							ans.back().push_back(j);
							used++;
						}
					}
				}
				for (int k = 0; k < 6; k += 2) {
					a[ans.back()[k]][ans.back()[k + 1]] = 1 - a[ans.back()[k]][ans.back()[k + 1]];
				}
			} else {
				break;
			}
		}

		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += accumulate(a[i].begin(), a[i].end(), 0);
		}
		assert(!sum);

		cout << ans.size() << '\n';
		for (auto& arr : ans) {
			for (int x : arr) cout << x + 1 << ' ';
			cout << '\n';
		}
	}
	return 0;
}