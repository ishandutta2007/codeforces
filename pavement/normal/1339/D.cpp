#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
typedef long double ld;
 
int n, dist[100005];
bool il[100005];
bool lo, le;
vector<int> adj[100005];

void dfs(int n, int e, int d) {
	dist[n] = d;
	int s = 0;
	for (auto u : adj[n])
		if (u != e) dfs(u, n, d + 1), s++;
	if (n == 1 && s == 1) {
		il[n] = 1;
		if (dist[n] & 1) lo = 1;
		else le = 1;
	} else if (s == 0) {
		il[n] = 1;
		if (dist[n] & 1) lo = 1;
		else le = 1;
	}
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int u, v, i = 1; i < n; i++) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1, -1, 0);
	if (lo && le) cout << "3 ";
	else cout << "1 ";
	int tt = n - 1;
	for (int i = 1; i <= n; i++) {
		int cur = 0;
		for (auto u : adj[i])
			if (il[u]) cur++;
		tt -= max(0ll, cur - 1);
	}
	cout << tt << '\n';
}