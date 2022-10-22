#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n, st[8*mxN], lz[8*mxN], flip[8*mxN];
ar<ll, 3> q[mxN];
vector<ll> d;

void push(int u, int l, int r) {
	if (!flip[u]&&lz[u]==-1)
		return;
	if (flip[u]&&lz[u]==-1) {
		st[u]=r-l+1-st[u];
		if (l^r)
			flip[2*u]^=1, flip[2*u+1]^=1;
	} else {
		lz[u]^=flip[u];
		st[u]=lz[u]*(r-l+1);
		if (l^r) {
			lz[2*u]=lz[2*u+1]=lz[u];
			flip[2*u]=flip[2*u+1]=0;
		}
	}
	lz[u]=-1, flip[u]=0;
}

void upd1(int ql, int qr, int t, int u=1, int l=0, int r=d.size()-1) {
	push(u, l, r);
	if (l>qr||r<ql)
		return;
	if (ql<=l&&r<=qr) {
		lz[u]=t;
		push(u, l, r);
		return;
	}
	int mid=(l+r)/2;
	upd1(ql, qr, t, 2*u, l, mid);
	upd1(ql, qr, t, 2*u+1, mid+1, r);
	st[u]=st[2*u]+st[2*u+1];
}

void upd2(int ql, int qr, int u=1, int l=0, int r=d.size()-1) {
	push(u, l, r);
	if (l>qr||r<ql)
		return;
	if (ql<=l&&r<=qr) {
		flip[u]=1;
		push(u, l, r);
		return;
	}
	int mid=(l+r)/2;
	upd2(ql, qr, 2*u, l, mid);
	upd2(ql, qr, 2*u+1, mid+1, r);
	st[u]=st[2*u]+st[2*u+1];
}

int qry(int u=1, int l=0, int r=d.size()-1) {
	push(u, l, r);
	if (st[u]==r-l+1)
		return -1;
	if (l==r)
		return l;
	int mid=(l+r)/2;
	int x=qry(2*u, l, mid);
	return x^-1?x:qry(2*u+1, mid+1, r);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> q[i][0] >> q[i][1] >> q[i][2];
		d.push_back(q[i][1]);
		d.push_back(q[i][2]+1);
	}
	sort(d.begin(), d.end());
	d.resize(unique(d.begin(), d.end())-d.begin());
	for (int i=0; i<n; ++i) {
		int t=q[i][0];
		ll l=q[i][1], r=q[i][2];
		l=lower_bound(d.begin(), d.end(), l)-d.begin();
		r=lower_bound(d.begin(), d.end(), r+1)-d.begin();
		if (t==1) {
			upd1(l, r-1, 1);
		} else if (t==2) {
			upd1(l, r-1, 0);
		} else {
			upd2(l, r-1);
		}
		cout << (d[0]>1?1:d[qry()]) << "\n";
	}
	return 0;
}