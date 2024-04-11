#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, m, k, st[1<<20], lz[1<<20];
set<ar<int, 2>> pos;
multiset<int> heights;

void bld(int u=1, int l=0, int r=2*n-2) {
	if (l==r) {
		st[u]=l;
		return;
	}
	int mid=(l+r)/2;
	bld(2*u, l, mid);
	bld(2*u+1, mid+1, r);
	st[u]=max(st[2*u], st[2*u+1]);
}

void psh(int u, int l, int r) {
	if (lz[u]) {
		st[u]+=lz[u];
		if (l^r)
			lz[2*u]+=lz[u], lz[2*u+1]+=lz[u];
		lz[u]=0;
	}
}

void upd(int ql, int qr, int x, int u=1, int l=0, int r=2*n-2) {
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
	st[u]=max(st[2*u], st[2*u+1]);
}

int qry(int ql, int qr, int u=1, int l=0, int r=2*n-2) {
	psh(u, l, r);
	if (ql<=l&&r<=qr)
		return st[u];
	int mid=(l+r)/2;
	if (qr<=mid)
		return qry(ql, qr, 2*u, l, mid);
	if (ql>mid)
		return qry(ql, qr, 2*u+1, mid+1, r);
	return max(qry(ql, qr, 2*u, l, mid), qry(ql, qr, 2*u+1, mid+1, r));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k >> m, --k;
	bld();
	while(m--) {
		int x, y;
		cin >> x >> y, --x, --y;
		int d=abs(x-k)+y;
		if (pos.find({x, y})==pos.end()) { // add
			upd(0, d, 1);
			pos.insert({x, y});
			heights.insert(d);
		} else { // remove
			upd(0, d, -1);
			pos.erase({x, y});
			heights.erase(heights.find(d));
		}
		cout << (heights.empty()?0:max(qry(0, *heights.rbegin()), n)-n) << "\n";
	}
	return 0;
}