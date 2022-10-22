#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5, mxA=3e5;
int n, a[mxN];
ll ans;

struct {
	ar<ll, 2> st[1<<20]; // count, sum
	void upd(int i, int u=1, int l=0, int r=mxA) {
		++st[u][0], st[u][1]+=i;
		if (l==r)
			return;
		int mid=(l+r)/2;
		i<=mid?upd(i, 2*u, l, mid):upd(i, 2*u+1, mid+1, r);
	}
	ar<ll, 2> qry(int ql, int qr, int u=1, int l=0, int r=mxA) {
		if (ql<=l&&r<=qr)
			return st[u];
		int mid=(l+r)/2;
		ar<ll, 2> x=ql<=mid?qry(ql, qr, 2*u, l, mid):ar<ll, 2>{0, 0};
		ar<ll, 2> y=qr>mid?qry(ql, qr, 2*u+1, mid+1, r):ar<ll, 2>{0, 0};
		return {x[0]+y[0], x[1]+y[1]};
	}
} st1;

struct { // segtree for adding [0, 1, 2, ... x] to a range [l, r]
	ar<ll, 2> st[1<<20]; // count, sum of startings
	void upd(int ql, int qr, int x, int u=1, int l=0, int r=mxA) {
		if (ql<=l&&r<=qr) {
			++st[u][0], st[u][1]+=l-ql;
			return;
		}
		int mid=(l+r)/2;
		if (ql<=mid)
			upd(ql, qr, x, 2*u, l, mid);
		if (qr>mid)
			upd(ql, qr, x, 2*u+1, mid+1, r);
	}
	ll qry(int i, int u=1, int l=0, int r=mxA) {
		if (l==r)
			return st[u][1];
		int mid=(l+r)/2;
		return st[u][0]*(i-l)+st[u][1]+(i<=mid?qry(i, 2*u, l, mid):qry(i, 2*u+1, mid+1, r));
	}
} st2;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		ans+=st1.qry(0, a[i]-1)[1]+st1.qry(a[i]+1, mxA)[0]*a[i]+st2.qry(a[i]);
		for (int j=a[i]; j<=mxA; j+=a[i]) {
			ar<ll, 2> cur=st1.qry(j, min(j+a[i]-1, mxA));
			ans+=cur[1]-cur[0]*j;
			st2.upd(j, min(j+a[i]-1, mxA), 0);
		}
		st1.upd(a[i]);
		cout << ans << " ";
	}
	return 0;
}