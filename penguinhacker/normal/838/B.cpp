#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
const ll INF=696969696969696969ll;
int n, q, tin[mxN], tout[mxN], t, init_up[mxN];
vector<ar<int, 2>> adj[mxN];
ar<int, 2> forw[mxN], back[mxN];
ll init[mxN], st[1<<19], lz[1<<19];

struct {
	ll ft[mxN+1];
	void upd(int i, ll x) {
		for (++i; i<=n; i+=i&-i)
			ft[i]+=x;
	}
	ll qry(int i) {
		ll r=0;
		for (++i; i; i-=i&-i)
			r+=ft[i];
		return r;
	}
} ft;


void dfs(int u=0, ll d=0) {
	tin[u]=t++;
	init[tin[u]]=d+init_up[u];
	for (auto [v, w] : adj[u]) {
		dfs(v, d+w);
		ft.upd(tin[v], w);
		ft.upd(tout[v]+1, -w);
	}
	tout[u]=t-1;
}

void bld(int u=1, int l=0, int r=n-1) {
	if (l==r) {
		st[u]=init[l];
		return;
	}
	int mid=(l+r)/2;
	bld(2*u, l, mid);
	bld(2*u+1, mid+1, r);
	st[u]=min(st[2*u], st[2*u+1]);
}

void psh(int u, int l, int r) {
	if (lz[u]) {
		st[u]+=lz[u];
		if (l!=r)
			lz[2*u]+=lz[u], lz[2*u+1]+=lz[u];
		lz[u]=0;
	}
}

void upd(int ql, int qr, int x, int u=1, int l=0, int r=n-1) {
	psh(u, l, r);
	if (l>qr||r<ql)
		return;
	if (ql<=l&&r<=qr) {
		lz[u]=x;
		psh(u, l, r);
		return;
	}
	int mid=(l+r)/2;
	upd(ql, qr, x, 2*u, l, mid);
	upd(ql, qr, x, 2*u+1, mid+1, r);
	st[u]=min(st[2*u], st[2*u+1]);
}

ll qry(int ql, int qr, int u=1, int l=0, int r=n-1) {
	psh(u, l, r);
	if (l>qr||r<ql)
		return INF;
	if (ql<=l&&r<=qr)
		return st[u];
	int mid=(l+r)/2;
	return min(qry(ql, qr, 2*u, l, mid), qry(ql, qr, 2*u+1, mid+1, r));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i=0; i<2*n-2; ++i) {
		int u, v, w;
		cin >> u >> v >> w, --u, --v;
		if (i<n-1) {
			forw[i]={v, w};
			adj[u].push_back({v, w});
		} else {
			back[i-(n-1)]={u, w};
			init_up[u]=w;
		}
	}
	dfs();
	bld();
	//for (int i=0; i<n; ++i)
	//	cout << ft.qry(tin[i]) << endl;
	while(q--) {
		int t;
		cin >> t;
		if (t==1) {
			int i, w;
			cin >> i >> w, --i;
			if (i<n-1) {
				int u=forw[i][0], lw=forw[i][1];
				upd(tin[u], tout[u], w-lw);
				ft.upd(tin[u], w-lw);
				ft.upd(tout[u]+1, -(w-lw));
				forw[i][1]=w;
			} else {
				i-=n-1;
				upd(tin[back[i][0]], tin[back[i][0]], w-back[i][1]);
				back[i][1]=w;
			}
		} else {
			int u, v;
			cin >> u >> v, --u, --v;
			if (tin[u]<=tin[v]&&tout[v]<=tout[u])
				cout << ft.qry(tin[v])-ft.qry(tin[u]) << "\n";
			else
				cout << qry(tin[u], tout[u])-ft.qry(tin[u])+ft.qry(tin[v]) << "\n";
		}
	}
	return 0;
}