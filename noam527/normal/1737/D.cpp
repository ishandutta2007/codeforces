#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
using namespace std;

const int N = 500;

int n, m;
vector<vector<int>> g;
int w[N][N];
int dist[N * N];

int indexof(int i, int j) {
	return n * i + j;
}
void split(int x, int &i, int &j) {
	i = x / n;
	j = x % n;
}

void solve() {
	cin >> n >> m;
	g.clear();
	g.resize(n);
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
		w[i][j] = dist[indexof(i, j)] = md;
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		--x, --y;
		g[x].push_back(y);
		g[y].push_back(x);
		w[x][y] = min(w[x][y], z);
		w[y][x] = min(w[y][x], z);
	}

	queue<int> q;
	q.push(indexof(0, n - 1));
	dist[indexof(0, n - 1)] = 0;
	while (q.size()) {
		int x = q.front();
		q.pop();
		int u, v;
		split(x, u, v);
		for (const auto &i : g[u]) {
			int z = indexof(i, v);
			if (dist[z] == md) {
				dist[z] = dist[x] + 1;
				q.push(z);
			}
		}
		for (const auto &i : g[v]) {
			int z = indexof(u, i);
			if (dist[z] == md) {
				dist[z] = dist[x] + 1;
				q.push(z);
			}
		}

		if (u == v) {
			int z;
			for (int ww = 0; ww < n; ww++) {
				z = indexof(u, ww);
				if (dist[z] == md) {
					dist[z] = dist[x] + 1;
					q.push(z);
				}
				z = indexof(ww, v);
				if (dist[z] == md) {
					dist[z] = dist[x] + 1;
					q.push(z);
				}
			}
		}
	}
	ll ans = inf;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		if (w[i][j] != md) {
			ans = min(ans, (ll)w[i][j] * (dist[indexof(i, j)] + 1));
		}
	}
	
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}