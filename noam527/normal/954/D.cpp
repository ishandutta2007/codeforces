#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <stack>
#include <queue>
#include <random>
#include <fstream>
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, m, s, t, d[2][1000];
vector<vector<int>> g;

void bfs(int x, int row) {
	for (int i = 0; i < 1000; i++) d[row][i] = 1e9;
	d[row][x] = 0;

	queue<int> q;
	q.push(x);
	int v;
	while (!q.empty()) {
		v = q.front(), q.pop();
		for (const auto &i : g[v])
			if (d[row][i] > d[row][v] + 1) {
				d[row][i] = d[row][v] + 1;
				q.push(i);
			}
	}
}

bool exist[1000][1000] = {};

int main() {
	fast;
	cin >> n >> m >> s >> t;
	g.resize(n);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v;
		--u, --v;
		exist[u][v] = exist[v][u] = 1;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	bfs(--s, 0);
	bfs(--t, 1);

	int ans = 0, total = d[0][t];
	for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++)
		if (!exist[i][j] && (d[0][i] + d[1][j] + 1 >= total && d[0][j] + d[1][i] + 1 >= total))
			ans++;
	cout << ans << endl;
}