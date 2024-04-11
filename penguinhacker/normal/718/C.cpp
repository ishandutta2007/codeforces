#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define Mat ar<ar<int, 2>, 2>

const int mxN=1e5, M=1e9+7;

Mat operator+(const Mat& a, const Mat& b) {
	Mat r={};
	for (int i : {0, 1}) for (int j : {0, 1}) r[i][j]=(a[i][j]+b[i][j])%M;
	return r;
}

Mat operator*(const Mat& a, const Mat& b) {
	Mat r={};
	for (int i : {0, 1}) for (int j : {0, 1}) for (int k : {0, 1}) r[i][k]=(r[i][k]+(ll)a[i][j]*b[j][k])%M;
	return r;
};

Mat bp(Mat b, ll p) {
	Mat r={ar<int, 2>{1, 0}, ar<int, 2>{0, 1}};
	for (; p; b=b*b, p/=2)
		if (p&1)
			r=r*b;
	return r;
}

int n, m, a[mxN];
Mat id, base, trans;
Mat a2[mxN], st[1<<18], lz[1<<18];

void bld(int u=1, int l=0, int r=n-1) {
	lz[u]=id;
	if (l==r) {
		st[u]=a2[l];
		return;
	}
	int mid=(l+r)/2;
	bld(2*u, l, mid);
	bld(2*u+1, mid+1, r);
	st[u]=st[2*u]+st[2*u+1];
}

void psh(int u, int l, int r) {
	if (lz[u]!=id) {
		st[u]=st[u]*lz[u];
		if (l^r)
			lz[2*u]=lz[2*u]*lz[u], lz[2*u+1]=lz[2*u+1]*lz[u];
		lz[u]=id;
	}
}

void upd(int ql, int qr, Mat x, int u=1, int l=0, int r=n-1) {
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
	st[u]=st[2*u]+st[2*u+1];
}

ll qry(int ql, int qr, int u=1, int l=0, int r=n-1) {
	psh(u, l, r);
	if (l>qr||r<ql)
		return 0;
	if (ql<=l&&r<=qr)
		return st[u][0][1];
	int mid=(l+r)/2;
	return (qry(ql, qr, 2*u, l, mid)+qry(ql, qr, 2*u+1, mid+1, r))%M;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	id={ar<int, 2>{1, 0}, ar<int, 2>{0, 1}};
	base={ar<int, 2>{0, 1}, ar<int, 2>{0, 0}};
	trans={ar<int, 2>{0, 1}, ar<int, 2>{1, 1}};
	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		a2[i]=base*bp(trans, a[i]-1);
	}
	bld();
	while(m--) {
		int t;
		cin >> t;
		if (t==1) {
			int l, r, x;
			cin >> l >> r >> x, --l, --r;
			upd(l, r, bp(trans, x));
		} else {
			int l, r;
			cin >> l >> r, --l, --r;
			cout << qry(l, r) << "\n";
		}
	}
	return 0;
}