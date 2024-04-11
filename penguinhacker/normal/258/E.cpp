#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n, m, t, tin[mxN], tout[mxN], lz[1<<18], ans[mxN];
vector<int> adj[mxN], qry[mxN];
ar<int, 2> col[mxN], st[1<<18];

void dfs(int u=0, int p=-1) {
	tin[u]=t++;
	for (int v : adj[u])
		if (v^p)
			dfs(v, u);
	tout[u]=t-1;
}

ar<int, 2> cmb(ar<int, 2> a, ar<int, 2> b) {
	return a[0]^b[0]?a<b?a:b:ar<int, 2>{a[0], a[1]+b[1]};
}

void psh(int u, int l, int r) {
	if (lz[u]) {
		st[u][0]+=lz[u];
		if (l^r)
			lz[2*u]+=lz[u], lz[2*u+1]+=lz[u];
		lz[u]=0;
	}
}

void bld(int u=1, int l=0, int r=n-1) {
	if (l==r) {
		st[u]={0, 1};
		return;
	}
	int mid=(l+r)/2;
	bld(2*u, l, mid);
	bld(2*u+1, mid+1, r);
	st[u]=cmb(st[2*u], st[2*u+1]);
}

void upd(int ql, int qr, int x, int u=1, int l=0, int r=n-1) {
	psh(u, l, r);
	if (l>qr||r<ql)
		return;
	if (ql<=l&&r<=qr) {
		lz[u]+=x;
		psh(u, l, r);
		return;
	}
	int mid=(l+r)/2;
	upd(ql, qr, x, 2*u, l, mid);
	upd(ql, qr, x, 2*u+1, mid+1, r);
	st[u]=cmb(st[2*u], st[2*u+1]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i=1; i<n; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs();
	bld();
	for (int i=0; i<m; ++i) {
		cin >> col[i][0] >> col[i][1], --col[i][0], --col[i][1];
		auto Add=[&](int u) {
			qry[tin[u]].push_back(i+1);
			if (tout[u]+1<n)
				qry[tout[u]+1].push_back(-(i+1));
		};
		Add(col[i][0]);
		Add(col[i][1]);
	}
	for (int i=0; i<n; ++i) {
		for (int j : qry[i]) {
			int x=j>0?1:-1;
			for (int u : col[abs(j)-1])
				upd(tin[u], tout[u], x); //, cout << tin[u] << " " << tout[u] << endl;
		}
		//cout << st[1][0] << " " << st[1][1] << endl;
		int nz=st[1][0]?n:n-st[1][1];
		ans[i]=max(0, nz-1);
	}
	for (int i=0; i<n; ++i)
		cout << ans[tin[i]] << " ";
	return 0;
}