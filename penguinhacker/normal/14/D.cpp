#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, d[200][200];
ar<int, 2> e[200];
vector<int> adj[200], cur;

void dfs(int u, int p, int r, int c) {
	d[r][u] = c;
	for (int v : adj[u])
		if (v ^ p)
			dfs(v, u, r, c + 1);
}

void dfs2(int u, int p) {
	cur.push_back(u);
	for (int v : adj[u])
		if (v ^ p)
			dfs2(v, u);
}

int solve() {
	int res = 0;
	for (int i : cur)
		for (int j : cur)
			res = max(res, d[i][j]);
	cur.clear();
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		e[i] = {u, v};
	}
	for (int i = 0; i < n; ++i)
		dfs(i, -1, i, 0);
	int ans = 0;
	for (int i = 1; i < n; ++i) {
		dfs2(e[i][0], e[i][1]);
		int a = solve();
		dfs2(e[i][1], e[i][0]);
		int b = solve();
		ans = max(ans, a * b);
	}
	cout << ans;
	return 0;
}