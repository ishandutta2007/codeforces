#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

struct edge {
	int to;
	bool b;
	edge(int tt = 0, bool bb = true) {
		to = tt;
		b = bb;
	}
};

int n, m;
vector<vector<edge>> g;
vector<int> l;

int dfs(int v = 0, int d = 0, int prev = -1) {
	if (l[v] != -1) return l[v];
	l[v] = d;
	int tmp;
	for (auto &i : g[v]) {
		if (i.to != prev) {
			tmp = dfs(i.to, d + 1, v);
			l[v] = min(l[v], tmp);
			if (tmp <= d)
				i.b = false;
		}
	}
	if (l[v] < d)
		for (auto &i : g[v])
			if (i.to == prev)
				i.b = false;
	return l[v];
}

pair<int, int> bfs(int v) {
	for (auto &i : l) i = -1;
	l[v] = 0;
	queue<int> q[2];
	int curr = 0;
	q[curr].push(v);
	int x;
	while (!q[curr].empty()) {
		x = q[curr].front(), q[curr].pop();
		for (const auto &i : g[x]) {
			if (l[i.to] == -1) {
				l[i.to] = l[x] + (i.b ? 1 : 0);
				if (i.b) q[1 ^ curr].push(i.to);
				else q[curr].push(i.to);
			}
		}
		if (q[curr].empty()) curr ^= 1;
	}
	pair<int, int> rtn(-1, -1);
	for (int i = 0; i < n; i++)
		if (l[i] > rtn.first)
			rtn = { l[i], i };
	return rtn;
}

int main() {
	fast;
	cin >> n >> m;
	g.resize(n);
	l.resize(n, -1);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v;
		--u, --v;
		g[u].push_back(edge(v));
		g[v].push_back(edge(u));
	}
	dfs();
	cout << bfs(bfs(0).second).first << endl;
}