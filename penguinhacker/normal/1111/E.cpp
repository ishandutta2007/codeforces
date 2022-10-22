#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5, M=1e9+7;
int n, q, d[mxN], anc[mxN][17], tin[mxN], tout[mxN], t, dp[mxN][300], ft[2*mxN+1];
vector<int> adj[mxN], tour;
bool vis[mxN];

void dfs(int u=0, int p=-1) {
	tin[u]=t++;
	for (int i=1; i<17; ++i)
		anc[u][i]=anc[anc[u][i-1]][i-1];
	for (int v : adj[u]) {
		if (v==p)
			continue;
		anc[v][0]=u;
		d[v]=d[u]+1;
		dfs(v, u);
	}
	tout[u]=t++;
}

int lca(int u, int v) {
	if (d[u]>d[v])
		swap(u, v);
	for (int i=16; ~i; --i)
		if (d[v]-(1<<i)>=d[u])
			v=anc[v][i];
	if (u==v)
		return u;
	for (int i=16; ~i; --i)
		if (anc[u][i]!=anc[v][i])
			u=anc[u][i], v=anc[v][i];
	return anc[u][0];
}

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

void upd_node(int i, bool t) {
	vis[i]^=1;
	upd(tin[i], t?-1:1);
	upd(tout[i], t?1:-1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i=1; i<n; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs();
	while(q--) {
		int k, m, r;
		cin >> k >> m >> r, --r;
		vector<int> v(k);
		for (int& i : v) {
			cin >> i, --i;
			upd_node(i, 0);
		}
		vector<ll> dp(m+1);
		vector<int> cnt(k);
		int qr=qry(tin[r]);
		for (int i=0; i<k; ++i) {
			int lc=lca(v[i], r);
			cnt[i]=qry(tin[v[i]])+qr-2*qry(tin[lc])+vis[lc]-1;
		}
		for (int i : v)
			upd_node(i, 1);
		sort(cnt.begin(), cnt.end());
		if (cnt.back()>=m) {
			cout << "0\n";
			continue;
		}
		dp[0]=1;
		for (int i : cnt)
			for (int j=m; ~j; --j)
				dp[j]=j>=i+1?(dp[j]*(j-i)+(j?dp[j-1]:0))%M:0;
		cout << accumulate(dp.begin(), dp.end(), 0ll)%M << "\n";
	}
	return 0;
}