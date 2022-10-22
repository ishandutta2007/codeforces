#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=3e5, M=1e9+7;
int n, q, p[mxN], d[mxN], tin[mxN], tout[mxN], t;
vector<int> adj[mxN];

struct ft {
	ll ft[2*mxN+1];
	void upd(int i, ll x) {
		for (++i; i<=2*n; i+=i&-i)
			ft[i]=(ft[i]+x)%M;
	}
	ll qry(int i) {
		ll r=0;
		for (++i; i; i-=i&-i)
			r+=ft[i];
		return r%M;
	}
} f1, f2;

void dfs(int u=0) {
	tin[u]=t++;
	for (int v : adj[u]) {
		d[v]=d[u]+1;
		dfs(v);
	}
	tout[u]=t++;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=1; i<n; ++i) {
		cin >> p[i], --p[i];
		adj[p[i]].push_back(i);
	}
	dfs();
	cin >> q;
	while(q--) {
		int t;
		cin >> t;
		if (t==1) {
			int u;
			ll x, k;
			cin >> u >> x >> k, --u;
			f1.upd(tin[u], (x+d[u]*k)%M);
			f1.upd(tout[u], M-(x+d[u]*k)%M);
			f2.upd(tin[u], k);
			f2.upd(tout[u], -k);
		} else {
			int u;
			cin >> u, --u;
			cout << (f1.qry(tin[u])-f2.qry(tin[u])*d[u]%M+M)%M << "\n";
		}
	}
	return 0;
}