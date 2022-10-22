#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

template<class T> struct seg_tree {
	const T ID=0;
	int n;
	vector<T> seg, lazy;
	seg_tree(int _n) : n(_n) {
		seg.assign(4*n, 0);
		lazy.assign(4*n, 0);
	}

	T combine(T a, T b) {return max(a, b);} //combiner function
	void push(int u, int l, int r) {
		seg[u]+=lazy[u];
		if (l!=r) lazy[2*u]+=lazy[u], lazy[2*u+1]+=lazy[u];
		lazy[u]=0;
	}
	void pull(int u) {seg[u]=combine(seg[2*u], seg[2*u+1]);}

	void upd(int x, int y, T val, int u, int l, int r) {
		push(u, l, r); if (l>y||r<x) return;
		if (x<=l&&r<=y) { lazy[u]+=val; push(u, l, r); return; }
		int mid=(l+r)/2; upd(x, y, val, 2*u, l, mid), upd(x, y, val, 2*u+1, mid+1, r);
		pull(u);
	}
	void upd(int x, int y, T val) {upd(x, y, val, 1, 0, n-1);}

	void upd(int i, T x, int u, int l, int r) {
		push(u, l, r); if (l>i||r<i) return;
		if (l==r) { seg[u]=x; return; }
		int mid=(l+r)/2; upd(i, x, 2*u, l, mid), upd(i, x, 2*u+1, mid+1, r);
		pull(u);
	}
	void upd(int i, T x) {upd(i, x, 1, 0, n-1);}

	T qry(int x, int y, int u, int l, int r) {
		push(u, l, r); if (l>y||r<x) return 0;
		if (x<=l&&r<=y) return seg[u];
		int mid=(l+r)/2; return combine(qry(x, y, 2*u, l, mid), qry(x, y, 2*u+1, mid+1, r));
	}
	T qry(int x, int y) {return qry(x, y, 1, 0, n-1);}
};

// probably d&c dp works
// whoops i skimmed solution and something about segtree also works..

const int mxN=35000;
int n, k, a[mxN], oc[mxN], prv[mxN], dp[mxN][50];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	memset(oc, -1, 4*n);
	for (int i=0; i<n; ++i) {
		cin >> a[i], --a[i];
		prv[i]=oc[a[i]];
		oc[a[i]]=i;
	}
	for (int i=0; i<n; ++i)
		dp[i][0]=(i?dp[i-1][0]:0)+(prv[i]==-1);
	//cout << dp[1][0] << "\n";
	for (int j=1; j<k; ++j) {
		seg_tree<int> t(n);
		for (int i=0; i<n; ++i) {
			t.upd(prv[i], i-1, 1);
			//if (i>=2)
			//	cout << prv[i] << " " << i-1 << "\n";
			dp[i][j]=t.qry(0, i-1);
			t.upd(i, dp[i][j-1]);
		}
	}
	cout << dp[n-1][k-1];
	return 0;
}