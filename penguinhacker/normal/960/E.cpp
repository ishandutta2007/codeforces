#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN = 200000;
const int MOD = 1e9 + 7;
int n, a[mxN], d[mxN], c[mxN][2];
vector<int> adj[mxN];
ll ans;

void dfs(int u = 0, int p = -1) {
	++c[u][d[u] & 1];
	for (int v : adj[u])
		if (v ^ p) {
			d[v] = d[u] + 1;
			dfs(v, u);
			c[u][0] += c[v][0], c[u][1] += c[v][1];
		}
}

void dfs2(int u = 0, int p = -1) {
	// yoyo compute some stuff?????
	int par = d[u] & 1;
	ll add = n;
	for (int v : adj[u]) {
		ll x = v ^ p ? c[v][par] : c[0][par] - c[u][par];
		ll y = v ^ p ? c[v][par ^ 1] : c[0][par ^ 1] - c[u][par ^ 1];
		add += (x - y) * (n - x - y);
	}
	add = (add + MOD * 696969ll) % MOD;
	ans = (ans + add * a[u]) % MOD;
	for (int v : adj[u])
		if (v ^ p)
			dfs2(v, u);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i], a[i] = (MOD + a[i]) % MOD;
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs();
	dfs2();
	cout << ans;
	return 0;
}