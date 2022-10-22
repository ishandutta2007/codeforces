#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
const ll INF=1e18;
int n, m, a[mxN];
ll st[4*mxN], lz[4*mxN];

void build(int u=1, int l=0, int r=n-1) {
	if (l==r) {
		st[u]=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(2*u, l, mid);
	build(2*u+1, mid+1, r);
	st[u]=min(st[2*u], st[2*u+1]);
}

void push(int u, int l, int r) {
	if (lz[u]) {
		st[u]+=lz[u];
		if (l^r)
			lz[2*u]+=lz[u], lz[2*u+1]+=lz[u];
		lz[u]=0;
	}
}

void upd(int ql, int qr, int x, int u=1, int l=0, int r=n-1) {
	push(u, l, r);
	if (l>qr||r<ql)
		return;
	if (ql<=l&&r<=qr) {
		lz[u]+=x;
		push(u, l, r);
		return;
	}
	int mid=(l+r)/2;
	upd(ql, qr, x, 2*u, l, mid);
	upd(ql, qr, x, 2*u+1, mid+1, r);
	st[u]=min(st[2*u], st[2*u+1]);
}

ll qry(int ql, int qr, int u=1, int l=0, int r=n-1) {
	push(u, l, r);
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
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	build();
	cin >> m;
	string s;
	getline(cin, s);
	for (int i=0; i<m; ++i) {
		getline(cin, s);
		stringstream is(s);
		vector<int> v;
		int x;
		while(is >> x)
			v.push_back(x);
		int l=v[0], r=v[1];
		if (v.size()==3) {
			if (l<=r) {
				upd(l, r, v[2]);
			} else {
				upd(l, n-1, v[2]);
				upd(0, r, v[2]);
			}
		} else {
			if (l<=r) {
				cout << qry(l, r) << "\n";
			} else {
				cout << min(qry(l, n-1), qry(0, r)) << "\n";
			}
		}
	}
	return 0;
}