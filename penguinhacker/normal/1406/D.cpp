#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n;
ll bit[100001];
void upd(int idx, int val) {
    for (++idx; idx <= n; idx += idx & -idx)
        bit[idx] += val;
}
void upd(int l, int r, int val) {
    upd(l, val);
    upd(r + 1, -val);
}
ll qry(int idx) {
    ll ret = 0;
    for (++idx; idx > 0; idx -= idx & -idx)
        ret += bit[idx];
    return ret;
}

int q, a[100000];
ll pos = 0, neg = 0;

bool ok(ll x) {
	ll start = qry(0) - x;
	start += pos;
	return start <= x;
}

void solve() {
	ll l = -1e16, r = 1e16;
	while(l < r) {
		ll mid = (l + r);
		if (mid > 0) mid >>= 1;
		else {
			if (mid % 2 == 0) mid /= 2;
			else mid = (mid - 1) / 2;
		}
		//cout << l << " " << r << "\n";
		if (ok(mid)) r = mid;
		else l = mid + 1;
	}
	cout << l << "\n";
}

void change(ll d, int inc) {
	if (d > 0) pos += d * inc;
	else neg += d * inc;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		upd(i, i, a[i]);
	}
	for (int i = 1; i < n; ++i) {
		change(a[i] - a[i - 1], 1);
	}
	solve();
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int l, r, x; cin >> l >> r >> x, --l, --r;
		if (l > 0) {
			ll p1 = qry(l - 1), p2 = qry(l);
			change(p2 - p1, -1);
		}
		if (r < n - 1) {
			ll p1 = qry(r), p2 = qry(r + 1);
			change(p2 - p1, -1);
		}
		upd(l, r, x);
		if (l > 0) {
			ll p1 = qry(l - 1), p2 = qry(l);
			change(p2 - p1, 1);
		}
		if (r < n - 1) {
			ll p1 = qry(r), p2 = qry(r + 1);
			change(p2 - p1, 1);
		}
		solve();
	}
	return 0;
}