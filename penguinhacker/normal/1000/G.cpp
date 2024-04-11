#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN = 300000;
int n, q, val[mxN];
vector<pair<int, int>> adj[mxN];
ll dp[mxN], pre1[mxN], pre2[mxN], pre3[mxN], pre4[mxN]; // 1: node val 2: edge val 3: dp 4: substract val
int dep[mxN], anc[mxN][19];

void dfs1(int u = 0, int p = -1) {
	pre1[u] = val[u];
	for (int i = 1; i < 19; ++i) {
		anc[u][i] = anc[anc[u][i - 1]][i - 1];
	}
	for (pair<int, int> v : adj[u]) {
		if (v.first != p) {
			pre2[v.first] = v.second;
			dep[v.first] = dep[u] + 1;
			anc[v.first][0] = u;
			dfs1(v.first, u);
			ll x = max(0ll, dp[v.first] + val[v.first] - 2 * v.second);
			dp[u] += x;
			pre4[v.first] += x;
		}
	}
}

void dfs2(int u = 0, int p = -1) {
	pre3[u] = dp[u];
	for (pair<int, int> v : adj[u]) {
		if (v.first != p) {
			ll old = dp[u];
			dp[u] -= max(0ll, dp[v.first] + val[v.first] - 2 * v.second);
			ll x = max(0ll, dp[u] + val[u] - 2 * v.second);
			dp[v.first] += x;
			pre4[v.first] += x;
			dfs2(v.first, u);
			dp[u] = old;
		}
	}
}

void dfs3(int u = 0, int p = -1) { //push prefix sums
	for (pair<int, int> v : adj[u]) {
		if (v.first != p) {
			pre1[v.first] += pre1[u];
			pre2[v.first] += pre2[u];
			pre3[v.first] += pre3[u];
			pre4[v.first] += pre4[u];
			dfs3(v.first, u);
		}
	}
}

int lca(int a, int b) {
	if (dep[a] > dep[b]) {
		swap(a, b);
	}
	for (int i = 18; ~i; --i) {
		if (dep[b] - (1 << i) >= dep[a]) {
			b = anc[b][i];
		}
	}
	if (a == b) {
		return a;
	}
	for (int i = 18; ~i; --i) {
		if (anc[a][i] != anc[b][i]) {
			a = anc[a][i];
			b = anc[b][i];
		}
	}
	return anc[a][0];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 0; i < n; ++i) {
		cin >> val[i];
	}
	for (int i = 1; i < n; ++i) {
		int a, b, c;
		cin >> a >> b >> c, --a, --b;
		adj[a].emplace_back(b, c);
		adj[b].emplace_back(a, c);
	}
	dfs1();
	//cout << dp[0] << "\n";
	dfs2();
	dfs3();
	for (int i = 0; i < q; ++i) {
		int a, b;
		cin >> a >> b, --a, --b;
		int l = lca(a, b);
		ll ans = pre1[a] + pre1[b] - 2 * pre1[l] + val[l];
		//cout << ans << "\n";
		ans -= pre2[a] + pre2[b] - 2 * pre2[l];
		//cout << ans << "\n";
		ans += pre3[a] + pre3[b] - 2 * pre3[l] + dp[l];
		//cout << ans << "\n";
		ans -= pre4[a] + pre4[b] - 2 * pre4[l];
		cout << ans << "\n";
	}
	return 0;
}