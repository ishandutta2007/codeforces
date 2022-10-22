#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=100000;
int n, q, dep[mxN], anc[mxN][17];
vector<int> adj[mxN];

void dfs(int u=0, int p=-1) {
	dep[u]=p==-1?0:dep[p]+1;
	for (int i=1; i<17; ++i) anc[u][i]=anc[anc[u][i-1]][i-1];
	for (int v : adj[u]) if (v!=p) {
		anc[v][0]=u;
		dfs(v, u);
	}
}
int lca(int u, int v) { //u is higher
	if (dep[u]>dep[v]) swap(u, v);
	for (int i=16; ~i; --i) if (dep[v]-(1<<i)>=dep[u]) v=anc[v][i];
	if (u==v) return u;
	for (int i=16; ~i; --i) if (anc[u][i]!=anc[v][i]) u=anc[u][i], v=anc[v][i];
	return anc[u][0];
}
int dist(int u, int v) {return dep[u]+dep[v]-2*dep[lca(u, v)];}
bool ok(int x) {return x>=0&&x%2==0;}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=1, u, v; i<n; ++i) {
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs();
	cin >> q;
	while(q--) {
		int u, v, x, y, k;
		cin >> x >> y >> u >> v >> k, --x, --y, --u, --v; //added edge from x to y
		bool b=0;
		b|=ok(k-dist(u, v));
		b|=ok(k-1-dist(u, x)-dist(y, v));
		b|=ok(k-1-dist(u, y)-dist(x, v));
		cout << (b?"YES":"NO") << '\n';
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/