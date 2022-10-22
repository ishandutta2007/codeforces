#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=100000;
int n, m, a[mxN];
ll s[4*mxN], mx[4*mxN];

void pull(int u) {
	s[u]=s[2*u]+s[2*u+1];
	mx[u]=max(mx[2*u], mx[2*u+1]);
}

void build(int u=1, int l=0, int r=n-1) {
	if (l==r) {
		s[u]=mx[u]=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(2*u, l, mid);
	build(2*u+1, mid+1, r);
	pull(u);
}

void upd(int ql, int qr, int x, int u=1, int l=0, int r=n-1) {
	//cerr << "[l, r, mx] = " << l << " " << r << " " << mx[u] << "\n";
	if (l>qr||r<ql||mx[u]<x)
		return;
	//cerr << "[l, r] = " << l << " " << r << "\n";
	if (l==r) {
		s[u]%=x, mx[u]%=x;
		return;
	}
	int mid=(l+r)/2;
	upd(ql, qr, x, 2*u, l, mid);
	upd(ql, qr, x, 2*u+1, mid+1, r);
	pull(u);
}

void Set(int i, int x, int u=1, int l=0, int r=n-1) {
	if (l>i||r<i)
		return;
	if (l==r) {
		s[u]=mx[u]=x;
		return;
	}
	int mid=(l+r)/2;
	Set(i, x, 2*u, l, mid);
	Set(i, x, 2*u+1, mid+1, r);
	pull(u);
}

ll qry(int ql, int qr, int u=1, int l=0, int r=n-1) {
	if (l>qr||r<ql)
		return 0;
	if (ql<=l&&r<=qr)
		return s[u];
	int mid=(l+r)/2;
	return qry(ql, qr, 2*u, l, mid)+qry(ql, qr, 2*u+1, mid+1, r);
}

void debug(int u=1, int l=0, int r=n-1) {
	if (l==r) {
		cerr << s[u] << " ";
		return;
	}
	int mid=(l+r)/2;
	debug(2*u, l, mid);
	debug(2*u+1, mid+1, r);
}

void dbg() {
	cerr << "DEBUG:   -->  ";
	debug();
	cerr << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	build();
	//dbg();
	while(m--) {
		int t;
		cin >> t;
		if (t==1) {
			int l, r;
			cin >> l >> r, --l, --r;
			cout << qry(l, r) << "\n";
		} else if (t==2) {
			int l, r, x;
			cin >> l >> r >> x, --l, --r;
			upd(l, r, x);
			//dbg();
		} else if (t==3) {
			int i, x;
			cin >> i >> x, --i;
			Set(i, x);
			//dbg();
		}
	}
	return 0;
}