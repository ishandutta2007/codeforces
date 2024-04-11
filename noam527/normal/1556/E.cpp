#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

struct segtree {
	int n;
	vector<ll> mn, mx;
	segtree() {}
	segtree(const vector<ll> &a) {
		n = max(2, (int)a.size());
		while (n != (n & -n)) n += (n & -n);
		mn.resize(2 * n);
		mx.resize(2 * n);
		for (int i = 0; i < a.size(); i++) {
			mn[i + n - 1] = mx[i + n - 1] = a[i];
		}
		for (int i = n - 2; i >= 0; i--) {
			mn[i] = min(mn[i + i + 1], mn[i + i + 2]);
			mx[i] = max(mx[i + i + 1], mx[i + i + 2]);
		}
	}
	void query(int l, int r, ll &m, ll &M) {
		m = inf, M = -inf;
		for (l += n - 1, r += n - 1; l < r; l = (l - 1) / 2, r = (r - 1) / 2) {
			if (!(l & 1)) {
				m = min(m, mn[l]);
				M = max(M, mx[l]);
				l++;
			}
			if (r & 1) {
				m = min(m, mn[r]);
				M = max(M, mx[r]);
				r--;
			}
		}
		if (l == r) {
			m = min(m, mn[l]);
			M = max(M, mx[l]);
		}
	}
};

int n, q;
vector<ll> d;
vector<ll> ps;

bool good(int l, int r) {
	if (l == 0) return ps[r] == 0;
	return ps[l - 1] == ps[r];
}

void solve() {
	cin >> n >> q;
	d.resize(n), ps.resize(n);
	for (auto &i : d) cin >> i;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		d[i] -= x;
	}
	ps[0] = d[0];
	for (int i = 1; i < n; i++)
		ps[i] = ps[i - 1] + d[i];
	segtree T(ps);

	while (q--) {
		int l, r;
		cin >> l >> r;
		--l, --r;
		if (!good(l, r)) {
			cout << "-1\n";
			continue;
		}
		ll mx, mn;
		T.query(l, r, mn, mx);
		if (mx != ps[r]) {
			cout << "-1\n";
			continue;
		}
		cout << mx - mn << '\n';
	}
}

int main() {
	//ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	//cin >> tst;
	while (tst--) solve();
}