#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n, m, d[mxN], anc[mxN][17], t, tin[mxN], tout[mxN], cc, cmp[mxN];
vector<int> adj[mxN], oc[mxN];

void dfs(int u, int p=-1) {
	for (int i=1; i<17; ++i)
		anc[u][i]=anc[u][i-1]^-1?anc[anc[u][i-1]][i-1]:-1;
	tin[u]=t++, cmp[u]=cc;
	oc[d[u]].push_back(tin[u]);
	for (int v : adj[u])
		if (v^p)
			d[v]=d[u]+1, dfs(v, u);
	tout[u]=t-1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> anc[i][0], --anc[i][0];
		if (anc[i][0]^-1)
			adj[anc[i][0]].push_back(i);
	}
	for (int i=0; i<n; ++i)
		if (!cmp[i])
			++cc, dfs(i);
	cin >> m;
	while(m--) {
		int u, k;
		cin >> u >> k, --u;
		if (k>d[u]) {
			cout << "0\n";
			continue;
		}
		int v=u;
		for (int i=0; i<17; ++i)
			if (k&(1<<i))
				v=anc[v][i];
		auto lo=lower_bound(oc[d[u]].begin(), oc[d[u]].end(), tin[v]);
		auto hi=upper_bound(oc[d[u]].begin(), oc[d[u]].end(), tout[v]);
		cout << hi-lo-1 << "\n";
	}
	return 0;
}