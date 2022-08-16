#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 1e3 + 5;

int n;
pair<int, int> e[N][N];

bool visited[N][N];

int dirx[4] = {1, -1, 0, 0};
int diry[4] = {0, 0, 1, -1};
char ans[N][N], dir_ans[4] = {'U', 'D', 'L', 'R'};

void bfs(int sx, int sy) {
	queue<pair<int, int>> q;
	q.emplace(sx, sy);
	visited[sx][sy] = true;

	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dirx[k], ny = y + diry[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < n && !visited[nx][ny] && e[nx][ny] == e[sx][sy]) {
				ans[nx][ny] = dir_ans[k];
				visited[nx][ny] = true;
				q.emplace(nx, ny);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> e[i][j].first >> e[i][j].second;
			if (e[i][j] != make_pair(-1, -1)) {
				--e[i][j].first;
				--e[i][j].second;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (e[i][j] == make_pair(i, j)) {
				bfs(i, j);
				ans[i][j] = 'X';
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (e[i][j] == make_pair(-1, -1) && ans[i][j] == 0) {
				if (j + 1 < n && e[i][j + 1] == e[i][j]) {
					ans[i][j] = 'R';
					ans[i][j + 1] = 'L';
				} else if (i + 1 < n && e[i + 1][j] == e[i][j]) {
					ans[i][j] = 'D';
					ans[i + 1][j] = 'U';
				} else if (j > 0 && e[i][j - 1] == e[i][j] && ans[i][j - 1] != 0) {
					ans[i][j] = 'L';
				} else if (i > 0 && e[i - 1][j] == e[i][j] && ans[i - 1][j] != 0) {
					ans[i][j] = 'U';
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (ans[i][j] == 0) {
				cout << "INVALID\n";
				return 0;
			}
		}
	}

	cout << "VALID\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ans[i][j];
		}
		cout << '\n';
	}
	return 0;
}