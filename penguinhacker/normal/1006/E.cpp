#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, q, T=0, tin[200000], tout[200000], tx[200000];
vector<int> adj[200000], ord;

void dfs(int u=0) {
	tin[u]=T++;
	tx[u]=ord.size();
	ord.push_back(u);
	for (int v : adj[u])
		dfs(v);
	tout[u]=T++;
}

bool isAnc(int u, int v) { //u is anc of v
	return tin[u]<=tin[v]&&tout[v]<=tout[u];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;
	for (int i=1, u; i<n; ++i) {
		cin >> u, --u;
		adj[u].push_back(i);
	}
	dfs();
	while(q--) {
		int u, k;
		cin >> u >> k, --u;
		int v=tx[u]+k-1;
		if (v>=n||!isAnc(u, ord[v]))
			cout << "-1\n";
		else
			cout << ord[v]+1 << '\n';
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/