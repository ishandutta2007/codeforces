#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const ll mxN = 2e5;
ll n, pos[mxN], sz[mxN], dep[mxN], anc[mxN][18], tin[mxN], tout[mxN], timer;
vector<ll> adj[mxN];

void dfs(ll u = 0, ll p = -1) {
	tin[u] = timer++;
	for (ll i = 1; i < 18; ++i)
		anc[u][i] = anc[anc[u][i - 1]][i - 1];
	sz[u] = 1;
	for (ll v : adj[u])
		if (v ^ p) {
			dep[v] = dep[u] + 1, anc[v][0] = u;
			dfs(v, u);
			sz[u] += sz[v];
		}
	tout[u] = timer++;
}

bool is_anc(ll u, ll v) {
	return tin[u] <= tin[v] && tout[v] <= tout[u];
}

ll lca(ll a, ll b) {
	if (dep[a] > dep[b])
		swap(a, b);
	if (is_anc(a, b))
		return a;
	for (ll i = 17; ~i; --i)
		if (!is_anc(anc[b][i], a))
			b = anc[b][i];
	return anc[b][0];
}

ll lift(ll u, ll d) {
	ll r = u;
	for (ll i = 0; i < 18; ++i)
		if (d & (1 << i))
			r = anc[r][i];
	return r;
}

void solve() {
	cin >> n;
	for (ll i = 0; i < n; ++i) {
		pos[i] = i;
		adj[i].clear();
	}
	for (ll i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs();
	ll a = pos[0], b = pos[0];
	vector<ll> ans(n+1);
	ans[1] = (ll)n * (n + 1) / 2 - 1;
	for (ll v : adj[a]) {
		ll s = v ^ anc[a][0] ? sz[v] : sz[0] - sz[a];
		ans[1] -= (ll)s * (s + 1) / 2;
	}
	//cout << ans[0] << "\n";
	ans[0]=n*(n-1)/2;
	b = pos[1];
	auto Cmp = [&](int k) {
		if (dep[a] > dep[b])
			swap(a, b);
		if (is_anc(a, b))
			ans[k] += (ll)sz[b] * (sz[0] - sz[lift(b, dep[b] - dep[a] - 1)]);
		else
			ans[k] += (ll)sz[a] * sz[b];
	};
	Cmp(2);
	for (ll i = 2; i < n; ++i) {
		ll x = pos[i];
		ll l = lca(a, b);
		if (dep[a] > dep[b]) // a is higher
			swap(a, b);
		if (is_anc(a, b)) {
			if (is_anc(a, x) && is_anc(x, b));
			else if (is_anc(b, x))
				b = x;
			else if (is_anc(x, a) || lca(x, b) == a)
				a = x;
			else
				break;
		}
		else {
			ll l = lca(a, b);
			if (is_anc(l, x) && is_anc(x, a));
			else if (is_anc(l, x) && is_anc(x, b));
			else if (is_anc(a, x))
				a = x;
			else if (is_anc(b, x))
				b = x;
			else break;
		}
		Cmp(i+1);
	}
	for (int i=0; i<n; ++i)
		ans[i]-=ans[i+1];
	for (int i=0; i<=n; ++i)
		cout << ans[i] << " ";
	cout << "\n";
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}