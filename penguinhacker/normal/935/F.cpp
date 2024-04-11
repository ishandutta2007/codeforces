#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
const int mxN=1e5;
const ll INF=1e18;
int n, q, a[mxN];
ll cur, d[mxN];
set<int> pos;
 
ll get(int i) {
	if (d[i]>=0&&d[i+1]>=0)
		return d[i+1];
	if (d[i]<=0&&d[i+1]<=0)
		return -d[i];
	if (d[i]<=0&&d[i+1]>=0)
		return -d[i]+d[i+1];
	return INF;
}
 
struct seg_tree {
	ll st[1<<18];
	void bld(int u=1, int l=1, int r=n-2) {
		if (l==r) {
			st[u]=get(l);
			return;
		}
		int mid=(l+r)/2;
		bld(2*u, l, mid);
		bld(2*u+1, mid+1, r);
		st[u]=min(st[2*u], st[2*u+1]);
	}
	void upd(int i, int u=1, int l=1, int r=n-2) {
		if (l==r) {
			st[u]=get(l);
			return;
		}
		int mid=(l+r)/2;
		if (i<=mid)
			upd(i, 2*u, l, mid);
		else
			upd(i, 2*u+1, mid+1, r);
		st[u]=min(st[2*u], st[2*u+1]);
	}
	ll qry(int ql, int qr, int u=1, int l=1, int r=n-2) {
		if (ql<=l&&r<=qr)
			return st[u];
		int mid=(l+r)/2;
		return min(ql<=mid?qry(ql, qr, 2*u, l, mid):INF, qr>mid?qry(ql, qr, 2*u+1, mid+1, r):INF);
	}
} st; // (pos, pos), (neg, neg)
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	for (int i=1; i<n; ++i) {
		d[i]=a[i]-a[i-1];
		cur+=abs(d[i]);
	}
	for (int i=1; i+1<n; ++i)
		if (a[i]>=a[i-1]&&a[i]>=a[i+1])
			pos.insert(i);
	st.bld();
	cin >> q;
	while(q--) {
		int t, l, r, x;
		cin >> t >> l >> r >> x, --l, --r;
		if (t==1) {
			auto it=pos.lower_bound(l);
			if (it!=pos.end()&&*it<=r) {
				cout << cur+2*x << "\n";
				continue;
			}
			if (l==r) {
				cout << cur-abs(d[l])-abs(d[l+1])+abs(d[l]+x)+abs(d[l+1]-x) << "\n";
				continue;
			}
			cout << cur+max(0ll, 2*(x-st.qry(l, r))) << "\n";
		} else {
			for (int i : {l, l-1, r, r+1})
				if (1<=i&&i<=n-2&&d[i]>=0&&d[i+1]<=0)
					pos.erase(i);
			cur-=abs(d[l])+abs(d[r+1]);
			d[l]+=x, d[r+1]-=x;
			cur+=abs(d[l])+abs(d[r+1]);
			for (int i : {l, l-1, r, r+1})
				if (1<=i&&i<=n-2) {
					st.upd(i);
					if (d[i]>=0&&d[i+1]<=0)
						pos.insert(i);
 
				}
		}
	}
	return 0;
}