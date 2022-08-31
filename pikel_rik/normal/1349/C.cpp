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

	int n, m, t;
	cin >> n >> m >> t;

	vector<string> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	const vector<int> dx = {1, -1, 0, 0};
	const vector<int> dy = {0, 0, 1, -1};

	auto is_valid = [&](int i, int j) -> bool {
		return 0 <= i && i < n && 0 <= j && j < m;
	};

	vector<vector<int>> dist(n, vector<int>(m, -1));

	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 4; k++) {
				int ni = i + dx[k], nj = j + dy[k];
				if (is_valid(ni, nj) && a[ni][nj] == a[i][j]) {
					dist[i][j] = 0;
					q.emplace(i, j);
					break;
				}
			}
		}
	}

	while (!q.empty()) {
		auto [i, j] = q.front();
		q.pop();

		for (int k = 0; k < 4; k++) {
			int ni = i + dx[k], nj = j + dy[k];
			if (is_valid(ni, nj) && dist[ni][nj] == -1) {
				dist[ni][nj] = 1 + dist[i][j];
				q.emplace(ni, nj);
			}
		}
	}

	int i, j;
	ll p;
	while (t--) {
		cin >> i >> j >> p;
		--i; --j;

		if (dist[i][j] == -1) {
			cout << a[i][j] << '\n';
		} else if (p <= dist[i][j]) {
			cout << a[i][j] << '\n';
		} else if ((p - dist[i][j]) % 2 == 0) {
			cout << a[i][j] << '\n';
		} else {
			cout << (a[i][j] == '1' ? '0' : '1') << '\n';
		}
	}
	return 0;
}