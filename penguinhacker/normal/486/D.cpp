#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>
const int MOD=1e9+7;

int n, d, a[2000], inds[2000], pos[2000];
vector<int> adj[2000];

int dfs(int u, int s, int p) {
	if (pos[u]<pos[s] || a[u]>a[s]+d)
		return 0;
	ll dp = 1;
	for (int v:adj[u]) {
		if (v!=p)
			dp = dp*(dfs(v, s, u)+1)%MOD;
	}
	return dp;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> d >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	for (int i=0, u, v; i<n-1; ++i) {
		cin >> u >> v, u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	iota(inds, inds+n, 0);
	sort(inds, inds+n, [](int x, int y) {return a[x]<a[y]; } );
	for (int i=0; i<n; ++i)
		pos[inds[i]] = i;
	
	ll ans = 0;
	for (int i=0; i<n; ++i)
		ans = (ans+dfs(inds[i], inds[i], -1))%MOD;
	cout << ans;
	return 0;
}