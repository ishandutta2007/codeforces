#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN = 150000;
const int MOD = 998244353;

int binPow(ll b, int p = MOD - 2) {
	ll res = 1;
	while(p) {
		if (p & 1)
			res = res * b % MOD;
		b = b * b % MOD;
		p >>= 1;
	}
	return res;
}

int n, q, mult;
int p[mxN], sz[mxN], hv[mxN], hd[mxN];
int tin[mxN], tout[mxN], timer;
ll e[mxN], bit[mxN + 1];
vector<int> adj[mxN];

void upd(int i, ll inc) {
	for (++i; i <= n; i += i & -i)
		bit[i] += inc;
}

ll qry(int i) {
	ll res = 0;
	for (++i; i > 0; i -= i & -i)
		res += bit[i];
	return res;
}

void dfs(int u = 0) {
	tin[u] = timer++;
	sz[u] = 1, hv[u] = -1;
	for (int& v : adj[u]) {
		adj[v].erase(find(adj[v].begin(), adj[v].end(), u));
		p[v] = u;
		dfs(v);
		sz[u] += sz[v];
		if (hv[u] == -1 || sz[v] > sz[hv[u]])
			hv[u] = v;
	}
	tout[u] = timer - 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	mult = binPow(n);
	for (int i = 1; i < n; ++i) {
		int u, v; cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs();
	for (int i = 0; i < n; ++i)
		if (!i || hv[p[i]] ^ i)
			for (int j = i; ~j; j = hv[j])
				hd[j] = i;
	for (int t, v, x; q--;) {
		cin >> t >> v, --v;
		if (t == 1) {
			cin >> x;
			e[v] += x;
			upd(0, (ll)sz[v] * x);
			upd(tin[v], -(ll)sz[v] * x);
			upd(tout[v] + 1, (ll)sz[v] * x);
			if (~hv[v]) {
				upd(tin[hv[v]], (ll)(n - sz[hv[v]]) * x);
				upd(tout[hv[v]] + 1, -(ll)(n - sz[hv[v]]) * x);
			}
		}
		else if (t == 2) {
			ll ans = (n * e[v] + qry(tin[v])) % MOD;
			for (v = hd[v]; v; v = hd[p[v]])
				ans = (ans + e[p[v]] * (n - sz[v])) % MOD;
			cout << ans * mult % MOD << "\n";
		}
	}
	return 0;
}