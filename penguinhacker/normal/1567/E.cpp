#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, q, a[mxN];
ar<ll, 5> st[1<<19]; // left index, right index, left, right, ans

ar<ll, 5> cmb(ar<ll, 5> x, ar<ll, 5> y) {
	return {
		x[0],
		y[1],
		x[2]==x[1]-x[0]+1&&a[x[1]]<=a[x[1]+1]?x[2]+y[2]:x[2],
		y[3]==y[1]-y[0]+1&&a[y[0]]>=a[y[0]-1]?y[3]+x[3]:y[3],
		x[4]+y[4]+(a[x[1]]<=a[x[1]+1]?x[3]*y[2]:0)
	};
}

void bld(int u=1, int l=0, int r=n-1) {
	if (l==r) {
		st[u]={l, l, 1, 1, 1};
		return;
	}
	int mid=(l+r)/2;
	bld(2*u, l, mid);
	bld(2*u+1, mid+1, r);
	st[u]=cmb(st[2*u], st[2*u+1]);
}

void upd(int i, int u=1, int l=0, int r=n-1) {
	if (l==r)
		return;
	int mid=(l+r)/2;
	i<=mid?upd(i, 2*u, l, mid):upd(i, 2*u+1, mid+1, r);
	st[u]=cmb(st[2*u], st[2*u+1]);
}

ar<ll, 5> qry(int ql, int qr, int u=1, int l=0, int r=n-1) {
	if (ql<=l&&r<=qr)
		return st[u];
	int mid=(l+r)/2;
	if (qr<=mid)
		return qry(ql, qr, 2*u, l, mid);
	if (ql>mid)
		return qry(ql, qr, 2*u+1, mid+1, r);
	return cmb(qry(ql, qr, 2*u, l, mid), qry(ql, qr, 2*u+1, mid+1, r));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	bld();
	while(q--) {
		int t;
		cin >> t;
		if (t==1) {
			int i, x;
			cin >> i >> x, --i;
			a[i]=x;
			upd(i);
		} else {
			int l, r;
			cin >> l >> r, --l, --r;
			cout << qry(l, r)[4] << "\n";
		}
	}
	return 0;
}