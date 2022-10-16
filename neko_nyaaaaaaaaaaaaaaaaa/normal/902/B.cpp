#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ans = 0;
vector<bool> v;
vector<vector<ll>> adj;
vector<ll> c;

void dfs(ll now, ll color) {
	if (color != c[now]) {
		color = c[now];
		ans++;
	}
	for (ll i = 0; i < adj[now].size(); i++) {
		dfs(adj[now][i], color);
	}
}

int main() {
	
	ll n, x;
	cin >> n;
	v.resize(n+1, 0);
	c.resize(n+1, 0);
	adj.resize(n+1, vector<ll>(0));
	for (ll i = 2; i <= n; i++) {
		cin >> x;
		adj[x].push_back(i);
	}
	for (ll i = 1; i <= n; i++) {
		cin >> c[i];
	}
	dfs(1, 0);
	cout << ans;
	
	return 0;
}