#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <iomanip>

using namespace std;

#define int long long
#define debug(x) cout << #x << " is " << x << '\n';
const int mod = 1e14 + 7;

struct segtree {
	int size;
	vector <int> tree, add;
	segtree(int n = 0) {
		size = 1;
		while (size < n) size <<= 1;
		tree.resize(2 * size - 1, mod);
		add.resize(2 * size - 1);
	}
	void push(int v) {
		tree[2 * v + 1] += add[v];
		tree[2 * v + 2] += add[v];
		add[2 * v + 1] += add[v];
		add[2 * v + 2] += add[v];
		add[v] = 0;
	}
	void upd(int v, int lx, int rx, int l, int r, int x) {
		if (l <= lx and rx <= r) {
			tree[v] += x;
			add[v] += x;
			return;
		} 
		if (rx <= l or r <= lx) return;
		push(v);
		int m = (lx + rx) / 2;
		upd(2 * v + 1, lx, m, l, r, x);
		upd(2 * v + 2, m, rx, l, r, x);
		tree[v] = min(tree[2 * v + 1], tree[2 * v + 2]);
	}
	void upd(int l, int r, int x) {
		upd(0, 0, size, l, r, x);
	}
	int get(int k, int lx, int x, int l, int r) {
		if (tree[x] >= k or r <= lx) return mod;
		if (l == r - 1) return l;
		push(x);
		int m = (l + r) / 2;
		int s = get(k, lx, 2 * x + 1, l, m);
		if (s == mod)
			s = get(k, lx, 2 * x + 2, m, r);
		return s;
	}
	int get(int k, int lx) {
		return get(k, lx, 0, 0, size);
	}
};

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		vector <int> a(n);
		int ans = 0;
		for (auto& x : a) cin >> x, ans += !x;
		vector <segtree> ST(2);
		ST[0] = segtree(n);
		ST[1] = segtree(n);
		vector <int> cur = { a[0] };
		for (int i = 1; i < n; ++i) {
			cur.push_back(a[i] - cur.back());
			ST[i & 1].upd(i, i + 1, -mod + cur[i]);
		}
		vector <map <int, vector <int>>> ids(2);
		for (int i = 0; i < n; ++i)
			ids[i & 1][cur[i]].push_back(i);
		vector <int> dlt(2);
		for (int i = 0; i < n; ++i) {
			int r = min({
				ST[0].get(0, i + 1),
				ST[1].get(0, i + 1),
				n
			});
			int l = i + 1;
			for (int b : {0, 1}) {
				int need = dlt[b];
				ans += lower_bound(ids[b][need].begin(), ids[b][need].end(), r) -
					lower_bound(ids[b][need].begin(), ids[b][need].end(), l);
			}
			dlt[i & 1] += a[i];
			dlt[i & 1 ^ 1] -= a[i];
			ST[i & 1].upd(l + 1, n, -a[i]);
			ST[i & 1 ^ 1].upd(l + 1, n, a[i]);
		}
		cout << ans << '\n';
	}
}