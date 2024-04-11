#include <bits/stdc++.h>
using namespace std;

vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};

int deg(int n, int m, vector<string> &s, int x, int y) {
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if (s[nx][ny] == '.') {
				ans++;
			} 
		}
	}
	return ans;
}

void solve() {
	int n, m; cin >> n >> m;
	vector<string> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == 'L') {
				q.push({i, j});
			}
		}
	}

	while (q.size()) {
		auto [x, y] = q.front(); q.pop();
		if (s[x][y] != 'L') {
			s[x][y] = '+';
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (s[nx][ny] == '.' && deg(n, m, s, nx, ny) <= 1) {
					q.push({nx, ny});
				} 
			}
		}
	}

	for (string str: s) {
		cout << str << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}