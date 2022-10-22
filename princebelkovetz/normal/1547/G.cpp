#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <queue>
#include <iomanip>

using namespace std;

#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int mod = 1e9 + 7;

vector <bool> used, mark;
vector <vector <int>> g, rev, cg;
vector <int> ts, col;
void dfs(int v) {
	used[v] = true;
	for (auto u : g[v]) {
		if (!used[u]) dfs(u);
	}
	ts.push_back(v);
}

void dfs2(int v, int c) {
	used[v] = true;
	col[v] = c;
	for (auto u : rev[v]) {
		if (!used[u])
			dfs2(u, c);
	}
}

void dfs3(int v) {
	used[v] = true;
	for (auto u : cg[v]) {
		if (!used[u])
			dfs3(u);
	}
	ts.push_back(v);
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(8);
	int tt; cin >> tt;
	while (tt --> 0) {
		int n, m; cin >> n >> m;
		g.resize(0);
		g.resize(n + 1);
		rev.resize(0);
		rev.resize(n + 1);
		col.resize(0);
		col.resize(n + 1);
		ts = {};
		used.resize(0);
		used.resize(n + 1);
		mark.resize(0);
		mark.resize(n + 1);
		for (int i = 0, u, v; i < m; ++i) {
			cin >> u >> v;
			g[u].push_back(v);
			rev[v].push_back(u);
			if (u == v) mark[u] = 1;
		}
		for (int i = 1; i <= n; ++i) {
			if (!used[i])
				dfs(i);
		}
		reverse(ts.begin(), ts.end());
		for (int i = 1; i <= n; ++i)
			used[i] = false;
		int cnt = 0;
		for (int i = 1; i <= n; ++i) {
			if (!used[ts[i - 1]])
				dfs2(ts[i - 1], cnt++);
		}
		vector <int> sz(cnt);
		vector <vector <int>> team(cnt);
		cg.resize(0);
		cg.resize(cnt);
		for (int i = 1; i <= n; ++i) {
			sz[col[i]]++;
			team[col[i]].push_back(i);
			for (auto j : g[i]) {
				if (col[i] != col[j]) {
					cg[col[i]].push_back(col[j]);
				}
			}
		}
		for (int i = 0; i < cnt; ++i)
			used[i] = false;
		ts = {};
		for (int i = 0; i < cnt; ++i) {
			if (!used[i])
				dfs3(i);
		}
		reverse(ts.begin(), ts.end());
		int st = -1;
		for (int i = 0; i < ts.size(); ++i) {
			if (ts[i] == col[1]) st = i;
		}
		vector <int> cc(ts.size()), cc2(ts.size());
		if (team[col[1]].size() > 2 or mark[1]) {
			cc[col[1]] = 1;
		}
		cc2[col[1]] = 1;
		for (int i = st; i < ts.size(); ++i) {
			bool ok = false;
			if (team[ts[i]].size() > 1 or mark[team[ts[i]][0]])
				ok = true;
			cc[ts[i]] = cc[ts[i]] || ok;
			if (!cc2[ts[i]]) continue;
			for (auto u : cg[ts[i]]) {
				cc[u] = (cc[u] || cc[ts[i]]);
				cc2[u] += cc2[ts[i]];
				cc2[u] %= mod;
			}
		}
		for (int i = 1; i <= n; ++i) {
			if (!cc2[col[i]]) cout << "0 ";
			else if (cc[col[i]]) cout << "-1 ";
			else if (cc2[col[i]] > 1) cout << "2 ";
			else if (cc2[col[i]]) cout << "1 ";
			else cout << "0 ";
		}
		cout << '\n';
	}
	return 0;
}