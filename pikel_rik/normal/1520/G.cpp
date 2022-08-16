#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, w;
	cin >> n >> m >> w;

	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	const vector<int> dx = {1, -1, 0, 0};
	const vector<int> dy = {0, 0, 1, -1};

	vector<vector<array<int, 2>>> lvl(n, vector<array<int, 2>>(m, {-1, -1}));
	for (int f = 0; f < 2; f++) {
		queue<pair<int, int>> q;
		if (f == 0) {
			q.emplace(0, 0);
			lvl[0][0][0] = 0;
		} else {
			q.emplace(n - 1, m - 1);
			lvl[n - 1][m - 1][1] = 0;
		}

		while (!q.empty()) {
			auto [x, y] = q.front();
			q.pop();

			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k], ny = y + dy[k];
				if (0 <= nx && nx < n && 0 <= ny && ny < m && a[nx][ny] != -1 && lvl[nx][ny][f] == -1) {
					lvl[nx][ny][f] = 1 + lvl[x][y][f];
					q.emplace(nx, ny);
				}
			}
		}
	}

	long long ans = LLONG_MAX;
	if (lvl[n - 1][m - 1][0] != -1) {
		ans = min(ans, (long long)w * lvl[n - 1][m - 1][0]);
	}

	vector<long long> from_source, from_sink;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (lvl[i][j][0] != -1 && a[i][j] > 0) {
				from_source.push_back((long long)w * lvl[i][j][0] + a[i][j]);
			}
			if (lvl[i][j][1] != -1 && a[i][j] > 0) {
				from_sink.push_back((long long)w * lvl[i][j][1] + a[i][j]);
			}
		}
	}

	if (!from_source.empty() && !from_sink.empty()) {
		long long mn_source = *min_element(from_source.begin(), from_source.end());
		long long mn_sink = *min_element(from_sink.begin(), from_sink.end());
		ans = min(ans, mn_source + mn_sink);
	}
	cout << (ans == LLONG_MAX ? -1 : ans) << '\n';
	return 0;
}