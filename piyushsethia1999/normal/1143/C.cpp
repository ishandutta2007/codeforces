#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;


int dfs(int u, int p, std::vector<int>& c, std::vector<int>& d, std::vector<std::vector<int> >& adj) {
	d[u] = 1;
	if (!c[u])
		d[u] = 0;
	for (int v : adj[u])
		if (v != p)
			d[u] = d[u] & dfs(v, u, c, d, adj);
	return c[u];
}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	std::vector<int> c(n);
	std::vector<int> d(n, 0);
	std::vector<std::vector<int> > adj(n);
	int r = 0;
	for (int i = 0; i < n; ++i) {
		int po; cin >> po;
		if (po != -1) {
			adj[po - 1].pb(i);
			adj[i].pb(po - 1);
		} else {
			r = i;
		}
		cin >> c[i];
	}
	dfs(r, r, c, d, adj);
	int t = 0;
	for (int i = 0; i < n; ++i)
		if (d[i]) {
			t = 1;
			cout << i + 1 << " "; 
		} 
	if (!t) cout << -1 << "\n"; 
}