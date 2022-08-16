#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> a(n, vector<int>(m));
	for (auto &v : a) for (auto &x : v) cin >> x;

	vector<vector<int>> b(n, vector<int>(m));
	for (auto &v : b) for (auto &x : v) cin >> x;

	if (a == b) {
		return cout << 0 << '\n', 0;
	}

	vector<int> deg(m);
	for (int i = 0; i + 1 < n; i++) {
		for (int j = 0; j < m; j++) {
			deg[j] += b[i][j] > b[i + 1][j];
		}
	}

	vector<int> ans;
	for (int j = 0; j < m; j++) {
		if (deg[j] == 0) {
			ans.push_back(j);
		}
	}

	vector<bool> used(n);
	for (int qi = 0; qi < (int) ans.size(); qi++) {
		int j = ans[qi];
		for (int i = 0; i + 1 < n; i++) {
			if (!used[i] && b[i][j] < b[i + 1][j]) {
				used[i] = true;
				for (int jj = 0; jj < m; jj++) {
					if (b[i][jj] > b[i + 1][jj]) {
						deg[jj] -= 1;
						if (deg[jj] == 0) {
							ans.push_back(jj);
						}
					}
				}
			}
		}
	}

	vector<int> ind(n);
	iota(ind.begin(), ind.end(), 0);

	reverse(ans.begin(), ans.end());
	for (int j : ans) {
		stable_sort(ind.begin(), ind.end(), [&](int ii, int jj) {
			return a[ii][j] < a[jj][j];
		});
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[ind[i]][j] != b[i][j]) {
				return cout << "-1\n", 0;
			}
		}
	}

	cout << ans.size() << '\n';
	for (int j : ans) {
		cout << j + 1 << ' ';
	}
	cout << '\n';
	return 0;
}