#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n, q, p[mxN], s[mxN], hd[mxN], tin[mxN], t;
vector<int> adj[mxN];
ar<int, 2> st[1<<18]; // { sum, max suffix }
bool lz[1<<18];

void dfs1(int u=0) {
	s[u]=1;
	for (int& v : adj[u]) {
		dfs1(v);
		s[u]+=s[v];
		if (s[v]>s[adj[u][0]])
			swap(v, adj[u][0]);
	}
}

void dfs2(int u=0) {
	tin[u]=t++;
	if (adj[u].empty())
		return;
	hd[adj[u][0]]=hd[u];
	dfs2(adj[u][0]);
	for (int i=1; i<adj[u].size(); ++i) {
		hd[adj[u][i]]=adj[u][i];
		dfs2(adj[u][i]);
	}
}

ar<int, 2> cmb(ar<int, 2> a, ar<int, 2> b) {
	return { a[0]+b[0], max(a[1]+b[0], b[1]) };
}

void bld(int u=1, int l=0, int r=n-1) {
	if (l==r) {
		st[u]={-1, -1};
		return;
	}
	int mid=(l+r)/2;
	bld(2*u, l, mid);
	bld(2*u+1, mid+1, r);
	st[u]=cmb(st[2*u], st[2*u+1]);
}

void psh(int u, int l, int r) {
	if (lz[u]) {
		st[u]={-(r-l+1), -1};
		if (l!=r)
			lz[2*u]=lz[2*u+1]=1;
		lz[u]=0;
	}
}

void upd1(int i, int x, int u=1, int l=0, int r=n-1) { // add x to st[i]
	psh(u, l, r);
	if (l>i||r<i)
		return;
	if (l==r) {
		st[u][0]+=x;
		st[u][1]=st[u][0];
		return;
	}
	int mid=(l+r)/2;
	upd1(i, x, 2*u, l, mid);
	upd1(i, x, 2*u+1, mid+1, r);
	st[u]=cmb(st[2*u], st[2*u+1]);
}

void upd2(int ql, int qr, int u=1, int l=0, int r=n-1) {
	psh(u, l, r);
	if (l>qr||r<ql)
		return;
	if (ql<=l&&r<=qr) {
		lz[u]=1;
		psh(u, l, r);
		return;
	}
	int mid=(l+r)/2;
	upd2(ql, qr, 2*u, l, mid);
	upd2(ql, qr, 2*u+1, mid+1, r);
	st[u]=cmb(st[2*u], st[2*u+1]);
}

ar<int, 2> qry(int ql, int qr, int u=1, int l=0, int r=n-1) {
	psh(u, l, r);
	if (ql<=l&&r<=qr)
		return st[u];
	int mid=(l+r)/2;
	if (qr<=mid)
		return qry(ql, qr, 2*u, l, mid);
	if (ql>mid)
		return qry(ql, qr, 2*u+1, mid+1, r);
	return cmb(qry(ql, qr, 2*u, l, mid), qry(ql, qr, 2*u+1, mid+1, r));
}

int qry(int u) {
	/*if (u==4) {
		ar<int, 2> x=qry(tin[4], tin[4]);
		ar<int, 2> y=qry(tin[3], tin[3]);
		ar<int, 2> xy=cmb(y, x);
		cout << "4 " << y[0] << " " << y[1] << " " << x[0] << " " << x[1] << " " << xy[0] << " " << xy[1] << endl;
		cout << hd[u] << " " << u << " " << qry(tin[hd[u]], tin[u])[0] << " " << qry(tin[hd[u]], tin[u])[1] <<  endl;
	}*/
	ar<int, 2> res=qry(tin[hd[u]], tin[u]);
	for (u=hd[u]; u; u=hd[u]) {
		u=p[u];
		//cout << hd[u] << " "  << u << endl;
		res=cmb(qry(tin[hd[u]], tin[u]), res);
	}
	//if (u==4)
	//	cout << "DONE" << endl;
	return res[1];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i=1; i<n; ++i) {
		cin >> p[i], --p[i];
		adj[p[i]].push_back(i);
	}
	dfs1();
	dfs2();
	bld();
	while(q--) {
		int t, u;
		cin >> t >> u, --u;
		if (t==1) {
			//cout << qry(4) << endl;
			upd1(tin[u], 1);
			//cout << qry(4) << endl;
		} else if (t==2) {
			upd2(tin[u], tin[u]+s[u]-1);
			int x=qry(u);
			//cout << st[1][0] << " " << st[1][1] << endl;
			//cout << tin[u] << " " << tin[u]+s[u]-1 << " " << x << endl;
			if (x!=-1)
				upd1(tin[u], -1-x);
		} else {
			cout << (qry(u)==-1?"white":"black") << "\n";
		}
		//cout << "NODE 4 " << qry(tin[4], tin[4])[0] << " " << qry(tin[4], tin[4])[1] << endl;
	}
	return 0;
}