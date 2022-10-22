#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
int mxN=1e6;

int n, a[1000000], b[1000000], e[1000000], st1[4*1000000], sz;
ll st2[4*1000000];

void upd(int pos, ll val, int id=1, int l=0, int r=sz-1) {
	if (l>pos||r<pos)
		return;
	st1[id]+=val;
	if (l==r)
		return;
	int mid=(l+r)/2;
	upd(pos, val, 2*id, l, mid);
	upd(pos, val, 2*id+1, mid+1, r);
}

ll qry(int x, int y, int id=1, int l=0, int r=sz-1) {
	if (l>y||r<x)
		return 0;
	if (x<=l&&r<=y)
		return st1[id];
	int mid=(l+r)/2;
	return qry(x, y, 2*id, l, mid)+qry(x, y, 2*id+1, mid+1, r);
}

void upd2(int pos, ll val, int id=1, int l=0, int r=sz-1) {
	if (l>pos||r<pos)
		return;
	st2[id]+=val;
	if (l==r)
		return;
	int mid=(l+r)/2;
	upd2(pos, val, 2*id, l, mid);
	upd2(pos, val, 2*id+1, mid+1, r);
}

ll qry2(int x, int y, int id=1, int l=0, int r=sz-1) {
	if (l>y||r<x)
		return 0;
	if (x<=l&&r<=y)
		return st2[id];
	int mid=(l+r)/2;
	return qry2(x, y, 2*id, l, mid)+qry2(x, y, 2*id+1, mid+1, r);
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i], e[i]=a[i];
	sort(e, e+n);
	sz=unique(e, e+n)-e;
	for (int i=0; i<n; ++i)
		a[i]=lower_bound(e, e+sz, a[i])-e;

	for (int i=n-1; ~i; --i) {
		upd(a[i], 1);
		b[i]=qry(0, a[i]-1);
	}
	ll ans=0;
	for (int i=n-1; ~i; --i) {
		upd2(a[i], b[i]);
		ans+=qry2(0, a[i]-1);
	}
	cout << ans;
	return 0;
}