#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN = 500000;
int n, q, a[mxN], seg[4 * mxN];

void build(int u = 1, int l = 0, int r = n - 1) {
	if (l == r) {
		seg[u] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(2 * u, l, mid);
	build(2 * u + 1, mid + 1, r);
	seg[u] = __gcd(seg[2 * u], seg[2 * u + 1]);
}

void upd(int pos, int val, int u = 1, int l = 0, int r = n - 1) {
	if (pos < l || pos > r) return;
	if (l == r) {
		seg[u] = val;
		return;
	}
	int mid = (l + r) / 2;
	upd(pos, val, 2 * u, l, mid);
	upd(pos, val, 2 * u + 1, mid + 1, r);
	seg[u] = __gcd(seg[2 * u], seg[2 * u + 1]);
}

int qry(int ql, int qr, int g, int u = 1, int l = 0, int r = n - 1) {
	if (r < ql || l > qr) return 0;
	if (seg[u] % g == 0) return 0;
	if (l == r) return 1;
	int mid = (l + r) / 2;
	int x = qry(ql, qr, g, 2 * u, l, mid);
	if (x > 1) return 2;
	return x + qry(ql, qr, g, 2 * u + 1, mid + 1, r);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	build();
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int t; cin >> t;
		if (t == 1) {
			int l, r, x; cin >> l >> r >> x, --l, --r;
			//if (i == q - 1) cout << qry(l, r, x) << " ";
			cout << (qry(l, r, x) <= 1 ? "YES" : "NO") << "\n";
		}
		else if (t == 2) {
			int x, y; cin >> x >> y, --x;
			upd(x, y);
		}
	}
	return 0;
}