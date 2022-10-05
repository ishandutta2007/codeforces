#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define endl '\n'
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 998244353, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

void kill() {
	cout << "No" << endl;
	exit(0);
}

int n, k;
vector<vector<int>> g;
vector<int> deg;

void bfs() {
	queue<int> q;
	for (int i = 0; i < n; i++)
		if (g[i].size() == 1) {
			deg[i] = 0;
			q.push(i);
		}
	int x;
	while (!q.empty()) {
		x = q.front(), q.pop();
		for (const auto &i : g[x]) {
			if (deg[i] == -1) {
				deg[i] = 1 + deg[x];
				q.push(i);
			}
		}
	}
}

void dfs(int v, int prev = -1) {
	if (deg[v] == 0) return;
	if (deg[v] == k) {
		if (g[v].size() < 3) kill();
	}
	else {
		if (g[v].size() < 4) kill();
	}
	for (const auto &i : g[v])
		if (i != prev) {
			if (deg[i] + 1 != deg[v]) kill();
			dfs(i, v);
		}
}

int main() {
	fast;
	cin >> n >> k;
	g.resize(n);
	deg.resize(n, -1);
	for (int i = 0, u, v; i < n - 1; i++) {
		cin >> u >> v;
		--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	bfs();

	int mx = -1, pos, cnt = 1;
	for (int i = 0; i < n; i++) {
		if (mx < deg[i]) {
			mx = deg[i];
			pos = i;
			cnt = 1;
		}
		else if (mx == deg[i]) {
			cnt++;
		}
	}
	if (cnt > 1) kill();
	if (mx != k) kill();
	dfs(pos);
	finish("Yes");
}