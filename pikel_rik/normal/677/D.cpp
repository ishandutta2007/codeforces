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

	int n, m, p;
	cin >> n >> m >> p;

	vector<vector<int>> a(n, vector<int>(m));
	vector<vector<pair<int, int>>> keys(p);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			keys[--a[i][j]].emplace_back(i, j);
		}
	}

	//|r1 - r2| + |c1 - c2| = max((r1 + c1) - (r2 + c2), (r1 - c1) - (r2 - c2))

	const vector<int> dirx = {1, -1, 0, 0}, diry = {0, 0, 1, -1};

	vector<vector<int>> dp(n, vector<int>(m));
	for (auto&[i, j] : keys[0]) {
		dp[i][j] = i + j;
	}

	for (int k = 1; k < p; k++) {
		if (keys[k].size() * keys[k - 1].size() >= n * m) {
			vector<vector<int>> lvl(n, vector<int>(m, -1));
			vector<pair<int, int>> q1, q2;

			for (auto&[px, py] : keys[k - 1]) {
				q1.emplace_back(px, py);
				lvl[px][py] = dp[px][py];
			}

			sort(q1.begin(), q1.end(), [&] (const pair<int, int> &p1, const pair<int, int> &p2) {
				return lvl[p1.first][p1.second] < lvl[p2.first][p2.second];
			});

			const auto process = [&](int px, int py) {
				for (int j = 0; j < 4; j++) {
					int nx = px + dirx[j], ny = py + diry[j];
					if (0 <= nx && nx < n && 0 <= ny && ny < m && lvl[nx][ny] == -1) {
						lvl[nx][ny] = 1 + lvl[px][py];
						q2.emplace_back(nx, ny);
					}
				}
			};

			int i = 0, j = 0;
			while (true) {
				if (i < q1.size() && j < q2.size()) {
					if (lvl[q1[i].first][q1[i].second] <= lvl[q2[j].first][q2[j].second]) {
						process(q1[i].first, q1[i].second);
						i++;
					} else {
						process(q2[j].first, q2[j].second);
						j++;
					}
				} else if (i < q1.size()) {
					process(q1[i].first, q1[i].second);
					i++;
				} else if (j < q2.size()) {
					process(q2[j].first, q2[j].second);
					j++;
				} else break;
			}

			for (auto&[nx, ny] : keys[k]) {
				dp[nx][ny] = lvl[nx][ny];
			}
		} else {
			for (auto&[nx, ny] : keys[k]) {
				dp[nx][ny] = INT_MAX;
				for (auto&[px, py] : keys[k - 1]) {
					dp[nx][ny] = min(dp[nx][ny], abs(nx - px) + abs(ny - py) + dp[px][py]);
				}
			}
		}
	}

	auto&[fx, fy] = keys.back().front();
	cout << dp[fx][fy] << '\n';
	return 0;
}