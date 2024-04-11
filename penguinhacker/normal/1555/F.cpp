#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=3e5, mxQ=5e5;
int n, q, p[mxN], tin[mxN], tout[mxN], t, anc[mxN][19], dp[mxN], ft[2*mxN+1];
ar<int, 3> qry[mxQ];
bool ans[mxQ];
vector<ar<int, 2>> adj[mxN];

int find(int i) {
	return i^p[i]?p[i]=find(p[i]):i;
}

void dfs(int u) {
	tin[u]=++t;
	for (auto [v, w] : adj[u])
		if (!tin[v]) {
			anc[v][0]=u;
			dp[v]=dp[u]^w;
			dfs(v);
		}
	tout[u]=++t;
}

bool ia(int u, int v) {
	return tin[u]<=tin[v]&&tout[v]<=tout[u];
}

int lca(int u, int v) {
	if (ia(u, v)||ia(v, u))
		return ia(u, v)?u:v;
	for (int i=18; ~i; --i)
		if (anc[u][i]^-1&&!ia(anc[u][i], v))
			u=anc[u][i];
	return anc[u][0];
}

void bupd(int i, int x) {
	for (; i<=2*n; i+=i&-i)
		ft[i]+=x;
}

int bqry(int i) {
	int r=0;
	for (; i; i-=i&-i)
		r+=ft[i];
	return r;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	iota(p, p+n, 0);
	for (int i=0; i<q; ++i) {
		int u, v, w;
		cin >> u >> v >> w, --u, --v;
		qry[i]={u, v, w};
		if (find(u)^find(v)) {
			ans[i]=1;
			p[p[v]]=p[u];
			adj[u].push_back({v, w});
			adj[v].push_back({u, w});
		}
	}
	for (int i=0; i<n; ++i)
		if (!tin[i]) {
			anc[i][0]=-1;
			dfs(i);
		}
	for (int j=1; j<19; ++j)
		for (int i=0; i<n; ++i)
			anc[i][j]=anc[i][j-1]^-1?anc[anc[i][j-1]][j-1]:-1;
	for (int i=0; i<q; ++i) {
		if (ans[i]) {
			cout << "YES\n";
			continue;
		}
		auto [u, v, w]=qry[i];
		if (dp[u]^dp[v]^w^1) {
			cout << "NO\n";
			continue;
		}
		int uv=lca(u, v);
		if (bqry(tin[u])+bqry(tin[v])-2*bqry(tin[uv])) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		for (int x : {u, v})
			for (; x!=uv; x=anc[x][0]) {
				bupd(tin[x], 1);
				bupd(tout[x], -1);
			}
	}
	return 0;
}