#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e6;
int n, m, a[mxN], b[mxN], ft[2*mxN+1];
ll ans;
ar<int, 2> st[1<<21];
vector<int> change[2*mxN+1];

void upd(int i) {
	for (++i; i<=n+m; i+=i&-i)
		++ft[i];
}

int qry(int i) {
	int r=0;
	for (++i; i; i-=i&-i)
		r+=ft[i];
	return r;
}

ar<int, 2> cmb(ar<int, 2> a, ar<int, 2> b) {
	return { a[0]+b[0], min(a[1], a[0]+b[1]) };
}

void bld(int u=1, int l=0, int r=n-1) {
	if (l==r) {
		st[u]={1, 0};
		return;
	}
	int mid=(l+r)/2;
	bld(2*u, l, mid);
	bld(2*u+1, mid+1, r);
	st[u]=cmb(st[2*u], st[2*u+1]);
}

void upd(int i, int x, int u=1, int l=0, int r=n-1) {
	if (l==r) {
		st[u]={x, min(0, x)};
		return;
	}
	int mid=(l+r)/2;
	if (i<=mid)
		upd(i, x, 2*u, l, mid);
	else
		upd(i, x, 2*u+1, mid+1, r);
	st[u]=cmb(st[2*u], st[2*u+1]);
}

void solve() {
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	for (int i=0; i<m; ++i)
		cin >> b[i];
	vector<int> d(a, a+n);
	d.insert(d.end(), b, b+m);
	sort(b, b+m);
	sort(d.begin(), d.end());
	d.resize(unique(d.begin(), d.end())-d.begin());
	for (int i=0; i<n; ++i)
		a[i]=lower_bound(d.begin(), d.end(), a[i])-d.begin();
	for (int i=0; i<m; ++i)
		b[i]=lower_bound(d.begin(), d.end(), b[i])-d.begin();
	ans=0;
	for (int i=0; i<n; ++i) {
		ans+=i-qry(a[i]);
		upd(a[i]);
	}
	memset(ft, 0, 4*(n+m+1));
	for (int i=0; i<d.size(); ++i)
		change[i].clear();
	for (int i=0; i<n; ++i)
		change[a[i]].push_back(i);
	bld();
	int cur=0;
	int smaller=0;
	for (int i=0; i<m; ++i) {
		if (!i||i&&b[i]^b[i-1]) {
			for (int j=cur; j<b[i]; ++j) {
				smaller+=change[j].size();
				for (int k : change[j])
					upd(k, -1);
			}
			for (int j : change[b[i]])
				upd(j, 0);
		}
		ans+=smaller+st[1][1];
		cur=b[i];
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}