#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n, m, a[mxN], avg[mxN];
vector<int> b[mxN], c[mxN], d;
ll s[mxN];
ar<int, 2> bs[3*mxN], st[1<<20];

int id(int x) {
	auto it=lower_bound(d.begin(), d.end(), x);
	assert(it!=d.end()&&*it==x);
	return it-d.begin();
}

ar<int, 2> cmb(ar<int, 2> x, ar<int, 2> y) {
	int mn=min(x[1], y[0]);
	return {x[0]+y[0]-mn, x[1]+y[1]-mn};
}

void bld(int u=1, int l=0, int r=d.size()-1) {
	if (l==r) {
		int mn=min(bs[l][0], bs[l][1]);
		st[u][0]=bs[l][0]-mn, st[u][1]=bs[l][1]-mn;
		return;
	}
	int mid=(l+r)/2;
	bld(2*u, l, mid);
	bld(2*u+1, mid+1, r);
	st[u]=cmb(st[2*u], st[2*u+1]);
}

void upd(int i, ar<int, 2> x, int u=1, int l=0, int r=d.size()-1) {
	if (l==r) {
		st[u][0]+=x[0], st[u][1]+=x[1];
		int mn=min(st[u][0], st[u][1]);
		st[u][0]-=mn, st[u][1]-=mn;
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
	d.clear();
	for (int i=0; i<n; ++i) {
		cin >> a[i], --a[i];
		d.push_back(a[i]);
	}
	for (int i=0; i<m; ++i) {
		int k;
		cin >> k;
		b[i].resize(k);
		s[i]=0;
		for (int& j : b[i])
			cin >> j, --j, s[i]+=j;
		avg[i]=(s[i]+k-1)/k;
		d.push_back(avg[i]);
		c[i].resize(k);
		for (int j=0; j<k; ++j) {
			c[i][j]=(s[i]-b[i][j]+k-2)/(k-1);
			d.push_back(c[i][j]);
		}
	}
	sort(d.begin(), d.end());
	d.resize(unique(d.begin(), d.end())-d.begin());
	for (int i=0; i<d.size(); ++i)
		bs[i]={};
	for (int i=0; i<n; ++i)
		++bs[id(a[i])][0];
	for (int i=0; i<m; ++i)
		++bs[id(avg[i])][1];
	bld();
	for (int i=0; i<m; ++i) {
		upd(id(avg[i]), {0, -1});
		for (int j : c[i]) {
			upd(id(j), {0, 1});
			cout << (st[1][1]==0);
			upd(id(j), {0, -1});
		}
		upd(id(avg[i]), {0, 1});
	}
	cout << "\n";
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