#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=3e5, INF=1e9;
int n, q, a[mxN], ans[mxN];
vector<ar<int, 2>> v[mxN];

struct {
	int ft[mxN+1];
	void upd(int i) {
		for (++i; i<=n; i+=i&-i)
			++ft[i];
	}
	int qry(int i) {
		int r=0;
		for (++i; i; i-=i&-i)
			r+=ft[i];
		return r;
	}
} ft;

struct {
	ar<int, 2> st[1<<20]; // {min, index}
	int lz[1<<20];
	void bld() {
		fill(st, st+(1<<20), ar<int, 2>{INF, -1});
	}
	ar<int, 2> cmb(ar<int, 2> a, ar<int, 2> b) {
		return a[0]<=b[0]?a:b;
	}
	void psh(int u, int l, int r) {
		if (lz[u]) {
			st[u][0]+=lz[u];
			if (l^r)
				lz[2*u]+=lz[u], lz[2*u+1]+=lz[u];
			lz[u]=0;
		}
	}
	void upd(int ql, int qr, int u=1, int l=0, int r=n-1) {
		psh(u, l, r);
		if (l>qr||r<ql)
			return;
		if (ql<=l&&r<=qr) {
			--lz[u];
			psh(u, l, r);
			return;
		}
		int mid=(l+r)/2;
		upd(ql, qr, 2*u, l, mid);
		upd(ql, qr, 2*u+1, mid+1, r);
		st[u]=cmb(st[2*u], st[2*u+1]);
	}
	void upd2(int i, int x, int u=1, int l=0, int r=n-1) {
		psh(u, l, r);
		if (l>i||r<i)
			return;
		if (l==r) {
			st[u]={x, l};
			return;
		}
		int mid=(l+r)/2;
		upd2(i, x, 2*u, l, mid);
		upd2(i, x, 2*u+1, mid+1, r);
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
} st;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i=0; i<n; ++i) {
		cin >> a[i], --a[i];
		a[i]=i-a[i];
	}
	for (int i=0; i<q; ++i) {
		int x, y;
		cin >> x >> y;
		v[x].push_back({n-y-1, i});
	}
	st.bld();
	for (int i=n-1; ~i; --i) {
		if (a[i]>=0)
			st.upd2(i, a[i]);
		while(1) {
			ar<int, 2> x=st.qry(i, n-1);
			//cout << i << " " << x[0] << " " << x[1] << endl;
			if (x[0]<=0) {
				ft.upd(x[1]);
				st.upd(x[1], n-1);
				st.upd2(x[1], INF);
			} else
				break;
		}
		for (ar<int, 2> x : v[i])
			ans[x[1]]=ft.qry(x[0]);
	}
	for (int i=0; i<q; ++i)
		cout << ans[i] << "\n";
	return 0;
}