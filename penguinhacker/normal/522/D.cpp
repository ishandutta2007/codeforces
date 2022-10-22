#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=5e5, INF=1e9;
int n, m, a[mxN], st[1<<20], ans[mxN];
vector<ar<int, 2>> v[mxN];
map<int, int> mp;

void upd(int i, int x, int u=1, int l=0, int r=n-1) {
	if (l==r) {
		st[u]=min(st[u], x);
		return;
	}
	int mid=(l+r)/2;
	i<=mid?upd(i, x, 2*u, l, mid):upd(i, x, 2*u+1, mid+1, r);
	st[u]=min(st[2*u], st[2*u+1]);
}

int qry(int ql, int qr, int u=1, int l=0, int r=n-1) {
	if (ql<=l&&r<=qr)
		return st[u];
	int mid=(l+r)/2;
	return min(ql<=mid?qry(ql, qr, 2*u, l, mid):INF, qr>mid?qry(ql, qr, 2*u+1, mid+1, r):INF);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	for (int i=0; i<m; ++i) {
		int l, r;
		cin >> l >> r, --l, --r;
		v[r].push_back({l, i});
	}
	memset(st, 0x3f, sizeof(st));
	for (int i=0; i<n; ++i) {
		if (mp.count(a[i])) {
			int pos=mp[a[i]];
			upd(pos, i-pos);
		}
		mp[a[i]]=i;
		for (ar<int, 2> b : v[i]) {
			int x=qry(b[0], i);
			ans[b[1]]=x<INF?x:-1;
		}
	}
	for (int i=0; i<m; ++i)
		cout << ans[i] << "\n";
	return 0;
}