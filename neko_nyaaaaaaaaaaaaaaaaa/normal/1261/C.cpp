#include <bits/stdc++.h>
using namespace std;

bool check(int f, vector<vector<int>> &dist, int n, int m) {
	vector<vector<int>> d(n+2, vector<int>(m+2, 0));
	queue<pair<int, int>> bfs;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (dist[i][j] >= f) {
				bfs.push({i, j});
				d[i][j] = f;
			}
		}
	} 

	while (bfs.size()) {
		auto [x, y] = bfs.front();
		bfs.pop();

		if (d[x][y] <= 1) continue;
 
		for (int dx = -1; dx <= 1; dx++) {
			for (int dy = -1; dy <= 1; dy++) {
				int i = x + dx, j = y + dy;
 
				if (i > 0 && i <= n && j > 0 && j <= m) {
					if (d[i][j] == 0) {
						bfs.push({i, j});
						d[i][j] = d[x][y] - 1;
					}
				} else {
					return 0;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (dist[i][j] == 0) {
				if (d[i][j] != 0) return 0;
			}
			if (d[i][j] == 0) {
				if (dist[i][j] != 0) return 0;
			}
			if (dist[i][j] < d[i][j]) return 0;
		}
	}
	return 1;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n, m; cin >> n >> m;
	vector<vector<char>> c(n+2, vector<char>(m+2, '.'));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> c[i][j];
		}
	}
 
	vector<vector<int>> dist(n+2, vector<int>(m+2, 998244353));
	queue<pair<int, int>> bfs;
	for (int i = 0; i <= n+1; i++) {
		for (int j = 0; j <= m+1; j++) {
			if (c[i][j] == '.') {
				bfs.push({i, j});
				dist[i][j] = 0;
			}
		}
	}
	
	while (bfs.size()) {
		auto [x, y] = bfs.front();
		bfs.pop();
 
		for (int dx = -1; dx <= 1; dx++) {
			for (int dy = -1; dy <= 1; dy++) {
				int i = x + dx, j = y + dy;
 
				if (i > 0 && i <= n && j > 0 && j <= m) {
					if (dist[i][j] > dist[x][y] + 1) {
						bfs.push({i, j});
						dist[i][j] = dist[x][y] + 1;
					}
				}
			}
		}
	}


	int lo = 0, hi = min((n+1)/2, (m+1)/2);
	while (lo < hi) {
		int mid = (lo + hi + 1)/2;

		if (check(mid, dist, n, m)) {
			lo = mid;
		} else {
			hi = mid-1;
		}
	}
	cout << lo-1 << '\n';
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (dist[i][j] >= lo) {
				cout << 'X';
			} else {
				cout << '.';
			}
		}
		cout << '\n';
	}


	return 0;
}