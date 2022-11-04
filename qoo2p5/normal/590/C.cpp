#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define sz(x) (int) x.size()
#define INF (int) 1e9
#define LINF (ll) 1e18
#define EPS 1e-10
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eq(a, b) abs(a - b) < EPS

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int n, m;
int field[1000][1000];
bool can_build[1000][1000];
int d[3][1000][1000];

bool in_bounds(int i, int j) {
	return 0 <= i && i < n && 0 <= j && j < m;
}

void bfs(int from) {
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (field[i][j] == from) {
				q.push(mp(i, j));
				d[from - 1][i][j] = 0;
			}
		}
	}

	while (!q.empty()) {
		pair<int, int> el = q.front();
		q.pop();
		int x = el.first;
		int y = el.second;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int ndist = d[from - 1][x][y] + (field[nx][ny] == 0);

			if (in_bounds(nx, ny) && can_build[nx][ny] && (d[from - 1][nx][ny] == -1 || d[from - 1][nx][ny] > ndist)) {
				d[from - 1][nx][ny] = ndist;
				q.push(mp(nx, ny));
			}
		}
	}
}

void solve() {
	scanf("%d%d\n", &n, &m);

	for (int i = 0; i < n; i++) {
		string s;
		getline(cin, s);

		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 3; k++) {
				d[k][i][j] = -1;
			}

			char x = s[j];

			if (x == '#' || x == '.') {
				can_build[i][j] = x == '.';
			} else {
				field[i][j] = x - '0';
				can_build[i][j] = true;
			}
		}
	}

	for (int i = 1; i <= 3; i++) {
		bfs(i);
	}

	int ans = INF;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			bool ok = true;
			int sum = 0;

			for (int k = 0; k < 3; k++) {
				sum += d[k][i][j];
				if (d[k][i][j] == -1) {
					ok = false;
				}
			}

			if (field[i][j] == 0) {
				sum -= 2;
			}

			if (ok && sum < ans) {
				ans = sum;
			}
		}
	}

	cout << (ans == INF ? -1 : ans) << endl;
}

int main() {
	//freopen("tree.in", "r", stdin);
	//freopen("tree.out", "w", stdout);
    //ios::sync_with_stdio(false);
    solve();
    return 0;
}