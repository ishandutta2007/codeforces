#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n, m, d[mxN], e[mxN], anc[mxN][17], t, tin[mxN], tout[mxN], ft[2*mxN+1];
vector<ar<int, 2>> adj[mxN];

void upd(int i, int x) {
	for (++i; i<=2*n; i+=i&-i)
		ft[i]+=x;
}

int qry(int i) {
	int r=0;
	for (++i; i; i-=i&-i)
		r+=ft[i];
	return r;
}

void dfs(int u=0, int p=-1) {
	for (int i=1; i<17; ++i)
		anc[u][i]=anc[anc[u][i-1]][i-1];
	tin[u]=t++;
	for (ar<int, 2> v : adj[u]) {
		if (v[0]==p)
			continue;
		e[v[1]]=v[0];
		d[v[0]]=d[u]+1, anc[v[0]][0]=u;
		dfs(v[0], u);
	}
	tout[u]=t++;
}

int lca(int u, int v) {
	if (d[u]>d[v])
		swap(u, v);
	for (int i=16; ~i; --i)
		if (d[u]<=d[v]-(1<<i))
			v=anc[v][i];
	if (u==v)
		return u;
	for (int i=16; ~i; --i)
		if (anc[u][i]^anc[v][i])
			u=anc[u][i], v=anc[v][i];
	return anc[u][0];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=1; i<n; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back({v, i});
		adj[v].push_back({u, i});
	}
	dfs();
	for (int i=1; i<n; ++i) {
		int v=e[i];
		upd(tin[v], 1);
		upd(tout[v], -1);
	}
	cin >> m;
	while(m--) {
		int t;
		cin >> t;
		if (t==1) {
			int v;
			cin >> v, v=e[v];
			upd(tin[v], 1);
			upd(tout[v], -1);
		} else if (t==2) {
			int v;
			cin >> v, v=e[v];
			upd(tin[v], -1);
			upd(tout[v], 1);
		} else {
			int u, v;
			cin >> u >> v, --u, --v;
			int uv=lca(u, v);
			int d2=d[u]+d[v]-2*d[uv];
			int d3=qry(tin[u])+qry(tin[v])-2*qry(tin[uv]);
			cout << (d2==d3?d2:-1) << "\n";
		}
	}
	return 0;
}