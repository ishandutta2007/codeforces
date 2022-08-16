#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 1e5 + 5;

int n, m, d[N], timer, tin[N], tout[N], up[N][17];
vector<int> g[N];

int sz[N];
ll dp[N];

void dfs(int x, int p) {
	up[x][0] = p;
	for (int i = 1; i < 17; i++) up[x][i] = up[up[x][i - 1]][i - 1];
	tin[x] = timer++;

	sz[x] = 1;
	for (int i : g[x]) {
		if (i == p) continue;
		d[i] = 1 + d[x];
		dfs(i, x);
		sz[x] += sz[i];
		dp[x] += sz[i] + dp[i];
	}
	tout[x] = timer++;
}

inline bool f(int u, int v) {
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
	if (f(u, v))
		return u;
	if (f(v, u))
		return v;
	for (int i = 16; i >= 0; i--) {
		if (up[u][i] && !f(up[u][i], v)) {
			u = up[u][i];
		}
	}
	return up[u][0];
}

ll sum[N];

void reroot(int x, int p) {
	sum[x] = sum[p] + n - 2 * sz[x];
	for (int i : g[x]) {
		if (i == p) continue;
		reroot(i, x);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(1, 0);
	sum[1] = dp[1];
	for (int i : g[1]) {
		reroot(i, 1);
	}

	cout << fixed << setprecision(12);
	while (m--) {
		int u, v;
		cin >> u >> v;
		int l = lca(u, v);
		if (l != u && l != v) {
			ld ans = d[u] + d[v] - 2 * d[l] + 1 + dp[u] / ld(sz[u]) + dp[v] / ld(sz[v]);
			cout << ans << '\n';
		} else {
			if (l == v)
				swap(u, v);
			l = v;
			for (int i = 16; i >= 0; i--) {
				if (up[l][i] && d[up[l][i]] > d[u]) {
					l = up[l][i];
				}
			}
			ld ans = d[v] - d[u] + 1 + (sum[u] - dp[l] - sz[l]) / ld(n - sz[l]) + dp[v] / ld(sz[v]);
			cout << ans << '\n';
		}
	}
	return 0;
}