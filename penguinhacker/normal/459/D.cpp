#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
const int mxN=1e6+1;

int n, a[mxN], suff[mxN], cnt[mxN], st[4*mxN];
map<int, int> mp;

void build(int id=1, int l=0, int r=n) {
	if (l==r) {
		st[id]=cnt[l];
		return;
	}
	int mid=(l+r)/2;
	build(2*id, l, mid);
	build(2*id+1, mid+1, r);
	st[id]=st[2*id]+st[2*id+1];
}

void upd(int x, int id=1, int l=0, int r=n) {
	if (l>x||r<x)
		return;
	--st[id];
	if (l==r)
		return;
	int mid=(l+r)/2;
	upd(x, 2*id, l, mid);
	upd(x, 2*id+1, mid+1, r);
}

int qry(int x, int y, int id=1, int l=0, int r=n) {
	if (l>y||r<x)
		return 0;
	if (x<=l&&r<=y)
		return st[id];
	int mid=(l+r)/2;
	return qry(x, y, 2*id, l, mid)+qry(x, y, 2*id+1, mid+1, r);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	for (int i=n-1; ~i; --i)
		suff[i]=++mp[a[i]];
	mp.clear();
	for (int i=0; i<n; ++i)
		++cnt[suff[i]];
	build();
	ll ans=0;
	for (int i=0; i<n; ++i) {
		upd(suff[i]);
		ans+=qry(0, mp[a[i]]++);
	}
	cout << ans;
	return 0;
}