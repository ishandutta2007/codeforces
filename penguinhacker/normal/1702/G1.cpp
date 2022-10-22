#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, q, d[mxN], anc[mxN][18];
vector<int> adj[mxN];

void dfs(int u=0, int p=-1) {
	for (int i=1; i<18; ++i)
		anc[u][i]=anc[anc[u][i-1]][i-1];
	for (int v : adj[u])
		if (v!=p) {
			d[v]=d[u]+1;
			anc[v][0]=u;
			dfs(v, u);
		}
}

int lca(int u, int v) {
	if (d[u]>d[v])
		swap(u, v);
	for (int i=17; ~i; --i)
		if (d[v]-(1<<i)>=d[u])
			v=anc[v][i];
	if (u==v)
		return u;
	for (int i=17; ~i; --i)
		if (anc[u][i]!=anc[v][i])
			u=anc[u][i], v=anc[v][i];
	return anc[u][0];
}

int dist(int u, int v) {
	return d[u]+d[v]-2*d[lca(u, v)];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=1; i<n; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs();
	cin >> q;
	while(q--) {
		int k;
		cin >> k;
		vector<int> nodes(k);
		for (int& i : nodes)
			cin >> i, --i;
		int a=nodes[0], b=nodes[0];
		bool ok=1;
		for (int i=1; i<nodes.size(); ++i) {
			int u=nodes[i];
			int ua=dist(a, u), ub=dist(b, u), ab=dist(a, b);
			if (ua+ub==ab)
				continue;
			else if (ua+ab==ub)
				a=u;
			else if (ub+ab==ua)
				b=u;
			else {
				ok=0;
				break;
			}
		}
		cout << (ok?"YES":"NO") << "\n";
	}
	return 0;
}