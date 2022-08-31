#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int q;
	cin >> q;

	int lg = 32 - __builtin_clz(q);
	vector<vector<int>> up(q + 1, vector<int>(lg, -1));

	vector<int> a(q + 1), c(q + 1);
	cin >> a[0] >> c[0];

	for (int i = 1; i <= q; i++) {
		int t;
		cin >> t;

		if (t == 1) {
			cin >> up[i][0] >> a[i] >> c[i];
			for (int j = 1; j < lg && up[i][j - 1] != -1; j++) {
				up[i][j] = up[up[i][j - 1]][j - 1];
			}
		} else {
			int v, w;
			cin >> v >> w;

			long long gold = 0, cost = 0;
			while (w > 0) {
				int u = v;
				for (int j = lg - 1; j >= 0; j--) {
					if (up[u][j] != -1 && a[up[u][j]] > 0) {
						u = up[u][j];
					}
				}
				long long cur = min(w, a[u]);
				gold += cur;
				cost += c[u] * cur;
				w -= cur;
				a[u] -= cur;
				if (u == v) {
					break;
				}
			}

			cout << gold << ' ' << cost << endl;
		}
	}
	return 0;
}