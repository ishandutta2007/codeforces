#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

struct seg_tree {
	const ll ID=1e18;
	int n;
	vector<ll> seg, lazy;
	seg_tree(int _n) : n(_n) {
		seg.assign(4*n, ID);
		lazy.assign(4*n, 0);
	}

	ll combine(ll a, ll b) {return min(a, b);}
	void push(int u, int l, int r) {
		seg[u]+=lazy[u];
		if (l!=r) lazy[2*u]+=lazy[u], lazy[2*u+1]+=lazy[u];
		lazy[u]=0;
	}
	void pull(int u) {seg[u]=combine(seg[2*u], seg[2*u+1]);}

	void upd(int x, int y, ll val, int u, int l, int r) {
		push(u, l, r); if (l>y||r<x) return;
		if (x<=l&&r<=y) { lazy[u]+=val; push(u, l, r); return; }
		int mid=(l+r)/2; upd(x, y, val, 2*u, l, mid), upd(x, y, val, 2*u+1, mid+1, r);
		pull(u);
	}
	void upd(int x, int y, ll val) {if (x<=y&&x>=0&&y<n) upd(x, y, val, 1, 0, n-1);}

	void setVal(int pos, ll val, int u, int l, int r) {
		push(u, l, r); if (r<pos||l>pos) return;
		if (l==r) {seg[u]=combine(seg[u], val); return;}
		int mid=(l+r)/2; setVal(pos, val, 2*u, l, mid), setVal(pos, val, 2*u+1, mid+1, r);
		pull(u);
	}
	void setVal(int pos, ll val) {if (pos>=0&&pos<n) setVal(pos, val, 1, 0, n-1);}

	ll qry(int x, int y, int u, int l, int r) {
		push(u, l, r); if (l>y||r<x) return ID;
		if (x<=l&&r<=y) return seg[u];
		int mid=(l+r)/2;
		return combine(qry(x, y, 2*u, l, mid), qry(x, y, 2*u+1, mid+1, r));
	}
	ll qry(int x, int y) {return qry(x, y, 1, 0, n-1);}
};

const int mxN=5e5;
int n, m, a[mxN], b[mxN], c[mxN];
ll ans=1e18;

void input() {
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	for (int i=0; i<n; ++i)
		cin >> c[i];
	cin >> m;
	for (int i=0; i<m; ++i)
		cin >> b[i];
}

void debug(seg_tree &t) {
	for (int i=0; i<=m; ++i)
		cout << t.qry(i, i) << " ";
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();

	seg_tree t(m+1);
	t.setVal(0, 0);
	for (int i=0; i<n; ++i) {
		int ind=lower_bound(b, b+m, a[i])-b;
		//cout << ind << ":  ";
		if (c[i]<0) t.upd(0, m, c[i]);
		else t.upd(0, ind, c[i]);
		if (ind<m&&a[i]==b[ind]) {
			t.setVal(ind+1, t.qry(ind, ind)-c[i]);
			//if (ind==m-1) ans=min(ans, t.qry(m, m));
		}
		//debug(t);
	}
	ans=t.qry(m, m);
	if (ans>(ll)1e17) {
		cout << "NO";
		return 0;
	}
	cout << "YES\n" << ans;
	return 0;
}