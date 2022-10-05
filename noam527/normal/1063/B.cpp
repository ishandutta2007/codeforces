#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define endl '\n'
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

vector<int> dx = { -1, 0, 1, 0 }, dy = { 0, 1, 0, -1 };

int n, m;
int x, y, l, r;
char c[2005][2005];
int dist[2005][2005];

void bfs() {
	queue<pair<int, int>> q;
	q.push({ x, y });
	pair<int, int> t1;
	dist[x][y] = 0;
	int tmp;

	tmp = x - 1;
	while (c[tmp][y] != '*' && dist[tmp][y] == -1) {
		dist[tmp][y] = dist[x][y];
		q.push({ tmp, y });
		tmp--;
	}
	tmp = x + 1;
	while (c[tmp][y] != '*' && dist[tmp][y] == -1) {
		dist[tmp][y] = dist[x][y];
		q.push({ tmp, y });
		tmp++;
	}
	while (!q.empty()) {
		t1 = q.front(), q.pop();
		for (int i = 0; i < 4; i++)
			if (c[t1.first + dx[i]][t1.second + dy[i]] != '*' && dist[t1.first + dx[i]][t1.second + dy[i]] == -1) {
				dist[t1.first + dx[i]][t1.second + dy[i]] = 1 + dist[t1.first][t1.second];
				q.push({ t1.first + dx[i], t1.second + dy[i] });
				
				tmp = t1.first + dx[i] - 1;
				while (c[tmp][t1.second + dy[i]] != '*' && dist[tmp][t1.second + dy[i]] == -1) {
					dist[tmp][t1.second + dy[i]] = dist[t1.first + dx[i]][t1.second + dy[i]];
					q.push({ tmp, t1.second + dy[i] });
					tmp--;
				}
				tmp = t1.first + dx[i] + 1;
				while (c[tmp][t1.second + dy[i]] != '*' && dist[tmp][t1.second + dy[i]] == -1) {
					dist[tmp][t1.second + dy[i]] = dist[t1.first + dx[i]][t1.second + dy[i]];
					q.push({ tmp, t1.second + dy[i] });
					tmp++;
				}
			}
	}
}

int main() {
	fast;
	cin >> n >> m >> x >> y >> l >> r;
	for (int i = 0; i <= n; i++) c[i][0] = c[i][m + 1] = '*';
	for (int j = 0; j <= m; j++) c[0][j] = c[n + 1][j] = '*';
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
		cin >> c[i][j];
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
		dist[i][j] = -1;

	bfs();
	int ans = 0, ml, mr;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
		if (c[i][j] != '*' && dist[i][j] != -1) {
			mr = (dist[i][j] + j - y) / 2;
			ml = dist[i][j] - mr;
			if (ml <= l && mr <= r) ans++;
		}
	}
	finish(ans);
}