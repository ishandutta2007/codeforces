#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=3e5;
int n, q, p[mxN], sz[mxN], ans[mxN];
vector<int> adj[mxN];

void dfs(int u=0) {
	sz[u]=1;
	int hv=-1;
	for (int v : adj[u]) {
		dfs(v);
		sz[u]+=sz[v];
		if (hv==-1||sz[v]>sz[hv])
			hv=v;
	}
	if (hv==-1||sz[hv]<=sz[u]/2) {
		ans[u]=u;
		return;
	}
	int c=ans[hv];
	while(c!=u&&sz[u]-sz[c]>sz[u]/2)
		c=p[c];
	ans[u]=c;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i=1; i<n; ++i) {
		cin >> p[i], --p[i];
		adj[p[i]].push_back(i);
	}
	dfs();
	while(q--) {
		int u;
		cin >> u, --u;
		cout << ans[u]+1 << "\n";
	}
	return 0;
}