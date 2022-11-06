#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int a[300001];
std::vector<int> adj[300001];
int siz[300001] = {};
int val[300001] = {};
int n;

void dfs(int u, int p) {
	int y = 0;
	for (int v : adj[u]) {
		if (v != p) {
			dfs(v, u);
			y += val[v];
			siz[u] += siz[v];
		}
	}
	if (a[u] == 1) {
		for (int v : adj[u]) {
			if (v != p) {
				val[u] = max(val[u], siz[u] - siz[v] + val[v]);
			}
		}
	} else {
		for (int v : adj[u]) {
			if (v != p) {
				val[u] += val[v];
			} 
		} 
	}
	if (siz[u] == 0) {
		siz[u] = 1;
	}
}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int o = 0; o < n; o++) { cin >> a[o]; }
	for (int i = 1; i < n; ++i) {
		int p; cin >> p; p--;
		adj[p].pb(i);
		adj[i].pb(p);
	}
	dfs(0, 0);
	cout << val[0] + 1 << "\n";
}