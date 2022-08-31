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

		vector<vector<int>> a(n, vector<int>(m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
			}
		}

		vector<pair<int, int>> ind(n * m);
		for (int i = 0; i < n * m; i++) {
			ind[i].first = i / m, ind[i].second = i % m;
		}

		sort(ind.begin(), ind.end(), [&](const auto &p1, const auto &p2) {
			return a[p1.first][p1.second] < a[p2.first][p2.second];
		});

		vector<vector<int>> ans(n, vector<int>(m, -1));

		for (int i = 0; i < m; i++) {
			ans[ind[i].first][i] = a[ind[i].first][ind[i].second];
		}

		for (int i = m; i < n * m; i++) {
			for (int r = 0; r < m; r++) {
				if (ans[ind[i].first][r] == -1) {
					ans[ind[i].first][r] = a[ind[i].first][ind[i].second];
					break;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << ans[i][j] << ' ';
			}
			cout << '\n';
		}
	}
	return 0;
}