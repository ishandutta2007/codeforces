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

		vector<vector<int>> rows(n, vector<int>(m)), cols(m, vector<int>(n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> rows[i][j];
			}
		}

		for (int j = 0; j < m; j++) {
			for (int i = 0; i < n; i++) {
				cin >> cols[j][i];
			}
		}

		int ii = 0, jj = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (rows[i][j] < rows[ii][jj]) {
					ii = i;
					jj = j;
				}
			}
		}

		int k1 = jj;

		ii = 0, jj = 0;
		for (int j = 0; j < m; j++) {
			for (int i = 0; i < n; i++) {
				if (cols[j][i] < cols[jj][ii]) {
					jj = j;
					ii = i;
				}
			}
		}

		int k2 = jj;

		vector<int> order(n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (cols[k2][i] == rows[j][k1]) {
					order[i] = j;
				}
			}
		}

		for (int i : order) {
			for (int j : rows[i]) cout << j << ' '; cout << '\n';
		}
	}
	return 0;
}