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

		vector<vector<int>> col(n, vector<int>(n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				char c;
				cin >> c;
				if (c == 'a') {
					col[i][j] = 0;
				} else if (c == 'b') {
					col[i][j] = 1;
				} else {
					col[i][j] = -1;
				}
			}
		}

		bool found = false;
		for (int i = 0; i < n && !found; i++) {
			for (int j = 0; j < n && !found; j++) {
				if (i != j && col[i][j] == col[j][i]) {
					found = true;
					cout << "YES\n";
					for (int ii = 0; ii < m + 1; ii++) {
						if (ii % 2 == 0) cout << i + 1 << ' ';
						else cout << j + 1 << ' ';
					}
					cout << '\n';
				}
			}
		}

		if (found) {
			continue;
		}

		if (m % 2 != 0) {
			cout << "YES\n";
			for (int i = 0; i < m + 1; i++) {
				cout << i % 2 + 1 << ' ';
			}
			cout << '\n';
			continue;
		}

		vector<int> top_order, cycle, p(n, -1);
		vector<bool> active(n);

		auto dfs = [&](int x, const auto &self) -> void {
			active[x] = true;
			for (int i = 0; i < n; i++) {
				if (col[x][i] != 0) continue;
				if (p[i] == -1) {
					p[i] = x;
					self(i, self);
				} else if (active[i] && cycle.empty()) {
					for (int j = x; j != p[i]; j = p[j]) {
						cycle.push_back(j);
					}
					reverse(cycle.begin(), cycle.end());
				}
			}
			active[x] = false;
			top_order.push_back(x);
		};

		for (int i = 0; i < n; i++) {
			if (p[i] == -1) {
				p[i] = -2;
				dfs(i, dfs);
			}
		}

		if (!cycle.empty()) {
			cout << "YES\n";
			for (int i = 0, j = 0; i < m + 1; i++) {
				cout << cycle[j] + 1 << ' ';
				j = (j + 1) % int(cycle.size());
			}
			cout << '\n';
			continue;
		}

		if (n == 2) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
			if ((m / 2) % 2 == 0) {
				for (int i = 0; i <= m / 2; i++) {
					cout << top_order[i % 2 + 1] + 1 << ' ';
				}
				for (int i = m / 2 + 1; i <= m; i++) {
					cout << top_order[(i + 1) % 2] + 1 << ' ';
				}
			} else {
				for (int i = 0; i <= m / 2; i++) {
					cout << top_order[i % 2] + 1 << ' ';
				}
				for (int i = m / 2 + 1; i <= m; i++) {
					cout << top_order[(i + 1) % 2 + 1] + 1 << ' ';
				}
			}
		}
	}
	return 0;
}