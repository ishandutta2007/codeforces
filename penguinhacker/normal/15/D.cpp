#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1000;
const ll INF=1e18;
int n, m, a, b, h[mxN][mxN], dp1[mxN][mxN], dp2[mxN][mxN], dq[mxN];
ll p[mxN+1][mxN+1];
set<ar<ll, 2>> r; // {min, row}
vector<ar<ll, 3>> ans;

ll Get(int i1, int j1, int i2, int j2) {
	++i2, ++j2;
	return p[i2][j2]-p[i2][j1]-p[i1][j2]+p[i1][j1];
}

struct seg_tree {
	ll st[4*mxN];
	void build(ll a[], int u=1, int l=0, int r=m-b) {
		if (l==r) {
			st[u]=a[l];
			return;
		}
		int mid=(l+r)/2;
		build(a, 2*u, l, mid);
		build(a, 2*u+1, mid+1, r);
		st[u]=min(st[2*u], st[2*u+1]);
	}
	void upd(int ql, int qr, int u=1, int l=0, int r=m-b) {
		if (l>qr||r<ql||st[u]==INF)
			return;
		if (l==r) {
			st[u]=INF;
			return;
		}
		int mid=(l+r)/2;
		upd(ql, qr, 2*u, l, mid);
		upd(ql, qr, 2*u+1, mid+1, r);
		st[u]=min(st[2*u], st[2*u+1]);
	}
	int qry(int u=1, int l=0, int r=m-b) {
		if (l==r)
			return l;
		int mid=(l+r)/2;
		if (st[2*u]<=st[2*u+1])
			return qry(2*u, l, mid);
		return qry(2*u+1, mid+1, r);
	}
} st[mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> a >> b;
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j) {
			cin >> h[i][j];
			p[i+1][j+1]=p[i+1][j]+p[i][j+1]-p[i][j]+h[i][j];
		}
	for (int j=0; j<m; ++j) {
		int s=0, e=0;
		for (int i=0; i<n; ++i) {
			while(s<e&&h[i][j]<=h[dq[e-1]][j])
				--e;
			dq[e++]=i;
			if (i>=a&&dq[s]==i-a)
				++s;
			if (i>=a-1)
				dp1[i-a+1][j]=h[dq[s]][j];
		}
	}
	for (int i=0; i+a-1<n; ++i) {
		int s=0, e=0;
		for (int j=0; j<m; ++j) {
			while(s<e&&dp1[i][j]<=dp1[i][dq[e-1]])
				--e;
			dq[e++]=j;
			if (j>=b&&dq[s]==j-b)
				++s;
			if (j>=b-1)
				dp2[i][j-b+1]=dp1[i][dq[s]];
		}
	}
	for (int i=0; i+a-1<n; ++i) {
		ll t[m-b+1];
		for (int j=0; j+b-1<m; ++j)
			t[j]=Get(i, j, i+a-1, j+b-1)-(ll)dp2[i][j]*a*b;
		st[i].build(t);
		r.insert({st[i].st[1], i});
	}
	while((*r.begin())[0]<INF) {
		int i=(*r.begin())[1];
		int j=st[i].qry();
		ll c=(*r.begin())[0];
		ans.push_back({i+1, j+1, c});
		int li=max(0, i-a+1), ri=min(n-a, i+a-1);
		int lj=max(0, j-b+1), rj=min(m-b, j+b-1);
		for (int k=li; k<=ri; ++k) {
			r.erase({st[k].st[1], k});
			st[k].upd(lj, rj);
			r.insert({st[k].st[1], k});
		}
	}
	cout << ans.size() << "\n";
	for (ar<ll, 3> x : ans)
		cout << x[0] << " " << x[1] << " " << x[2] << "\n";
	return 0;
}