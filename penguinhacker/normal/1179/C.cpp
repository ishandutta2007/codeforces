#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=3e5, mxV=1e6;
int n, m, q, a[mxN], b[mxN];
ar<int, 2> st[1<<21];

void upd(int i, ar<int, 2> x, int u=1, int l=1, int r=mxV) {
	if (l==r) {
		int mn=min(st[u][0]+=x[0], st[u][1]+=x[1]);
		st[u][0]-=mn, st[u][1]-=mn;
		//cout << st[u][0] << " " << st[u][1] << " <- " << l << endl;
		return;
	}
	int mid=(l+r)/2;
	if (i<=mid)
		upd(i, x, 2*u, l, mid);
	else
		upd(i, x, 2*u+1, mid+1, r);
	int mn=min(st[2*u][0], st[2*u+1][1]);
	st[u][0]=st[2*u][0]+st[2*u+1][0]-mn;
	st[u][1]=st[2*u][1]+st[2*u+1][1]-mn;
}

int qry(int k=0, int u=1, int l=1, int r=mxV) {
	if (st[u][0]-k<=0)
		return -1;
	if (l==r)
		return l;
	//cout << l << " " << r << endl;
	int mid=(l+r)/2;
	int rs=qry(k, 2*u+1, mid+1, r);
	return rs^-1?rs:qry(k+st[2*u+1][1]-st[2*u+1][0], 2*u, l, mid);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		upd(a[i], {1, 0});
	}
	for (int i=0; i<m; ++i) {
		cin >> b[i];
		upd(b[i], {0, 1});
	}
	cin >> q;
	while(q--) {
		int t, i, x;
		cin >> t >> i >> x, --i;
		if (t==1) {
			upd(a[i], {-1, 0});
			upd(a[i]=x, {1, 0});
		} else {
			upd(b[i], {0, -1});
			upd(b[i]=x, {0, 1});
		}
		cout << qry() << "\n";
	}
	return 0;
}