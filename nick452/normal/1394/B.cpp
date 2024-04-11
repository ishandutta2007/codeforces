#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifdef _MSC_VER
	freopen("b.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<pair<int, int>>> g(n);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		--u;
		--v;
		g[u].push_back(make_pair(w, v));
	}
	vector<int> a[16][16];
	for (int i = 0; i < n; i++) {
		sort(g[i].begin(), g[i].end());
		for (int j = 0; j < g[i].size(); ++j) {
			a[g[i].size()][j].push_back(g[i][j].second);
		}
	}
	int b[16][16];
	for (int d = 1; d <= k; d++) {
		for (int i = 0; i < d; i++) {
			if (unordered_set<int>(a[d][i].begin(), a[d][i].end()).size() != a[d][i].size()) {
				b[d][i] = 0;
			}
			else {
				b[d][i] = 1;
			}
		}
	}
	int overlap[16][16][16][16];
	memset(overlap, 0, sizeof(overlap));
	int mask_id = 0;
	vector<int> mask(n);
	for (int d = 1; d <= k; d++) {
		for (int i = 0; i < d; i++) {
			++mask_id;
			for (int x : a[d][i]) {
				mask[x] = mask_id;
			}
			for (int e = 1; e < d; e++) {
				for (int j = 0; j < e; j++) {
					for (int y : a[e][j]) {
						if (mask[y] == mask_id) {
							overlap[d][i][e][j] = 1;
							break;
						}
					}
				}
			}
		}
	}
	int result = 0;
	int c[16];
	std::function<void(int)> dfs = [&](int deg) {
		if (deg == 0) {
			++result;
			return;
		}
		for (int i = 0; i < deg; i++) {
			if (b[deg][i]) {
				int valid = 1;
				for (int d = deg + 1; d <= k; d++) {
					if (overlap[d][c[d]][deg][i]) {
						valid = 0;
						break;
					}
				}
				if (valid) {
					c[deg] = i;
					dfs(deg - 1);
				}
			}
		}
	};
	dfs(k);
	cout << result << endl;
	return 0;
}