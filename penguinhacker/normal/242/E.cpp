#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=100000;
int n, q, val[mxN];
struct Seg_Tree {
	int bit, a[4*mxN], lazy[4*mxN];
	void build(int u=1, int l=0, int r=n-1) {
		if (l==r) {
			a[u]=(val[l]>>bit)&1;
			//if (bit==0) cout << a[u] << ' ';
			return;
		}
		int mid=(l+r)/2;
		build(2*u, l, mid);
		build(2*u+1, mid+1, r);
		a[u]=a[2*u]+a[2*u+1];
	}
	inline void propagate(int u, int l, int r) {
		if (lazy[u]==0) return;
		a[u]=r-l+1-a[u];
		if (l!=r) {
			lazy[2*u]^=1;
			lazy[2*u+1]^=1;
		}
		lazy[u]=0;
	}
	void upd(int x, int y, int u=1, int l=0, int r=n-1) {
		propagate(u, l, r);
		if (l>y||r<x) return;
		if (x<=l&&r<=y) {lazy[u]^=1; propagate(u, l, r); return;}
		int mid=(l+r)/2;
		upd(x, y, 2*u, l, mid);
		upd(x, y, 2*u+1, mid+1, r);
		a[u]=a[2*u]+a[2*u+1];
	}
	int qry(int x, int y, int u=1, int l=0, int r=n-1) {
		propagate(u, l, r);
		if (l>y||r<x) return 0;
		if (x<=l&&r<=y) return a[u];
		int mid=(l+r)/2;
		int ls=qry(x, y, 2*u, l, mid), rs=qry(x, y, 2*u+1, mid+1, r);
		a[u]=a[2*u]+a[2*u+1];
		return ls+rs;
	}
} s[20];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) cin >> val[i];
	for (int i=0; i<20; ++i) {s[i].bit=i; s[i].build();}
	cin >> q;
	while(q--) {
		int t; cin >> t;
		if (t==1) {
			int l, r; cin >> l >> r, --l, --r;
			ll ans=0;
			for (int i=0; i<20; ++i) ans+=(1ll<<i)*s[i].qry(l, r);
			cout << ans << '\n';
		}
		else {
			int l, r, x; cin >> l >> r >> x, --l, --r;
			for (int i=0; i<20; ++i) if (x&(1<<i)) s[i].upd(l, r);
		}
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/