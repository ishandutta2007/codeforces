#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <queue>
#include <iterator>
#include <sstream>
#include <cassert>
#include <locale>
#define int long long
#define ull unsigned long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
const int bb = 31;
struct node {
	int bits[bb];
	int sum = 0;
};
struct segtree {
	int size;
	vector <node> tree;
	vector <int> mod;
	void init(int n) {
		size = 1;
		while (size < n) size *= 2;
		tree.resize(2 * size - 1);
		mod.resize(2 * size - 1);
	}
	node merge(node& a, node& b) {
		node res;
		for (int i = 0; i < bb; ++i) {
			res.bits[i] = a.bits[i] + b.bits[i];
		}
		res.sum = a.sum + b.sum;
		return res;
	}
	void build(int v, int lx, int rx, vector <int>& a) {
		if (lx + 1 == rx) {
			if (lx < a.size()) {
				tree[v].sum += a[lx];
				for (int i = 0; i < bb; ++i, a[lx] /= 2) {
					tree[v].bits[i] = a[lx] & 1;
				}
			}
			return;
		}
		int m = (lx + rx) / 2;
		build(2 * v + 1, lx, m, a);
		build(2 * v + 2, m, rx, a);
		tree[v] = merge(tree[2 * v + 1], tree[2 * v + 2]);
	}
	void build(vector <int>& a) {
		build(0, 0, size, a);
	}
	void apply(int v, int lx, int rx, int x) {
		mod[v] ^= x;
		int copy = x;
		tree[v].sum = 0;
		for (int i = 0, two = 1; i < bb; ++i, copy /= 2, two *= 2) {
			if (copy & 1) {
				tree[v].bits[i] = (rx - lx) - tree[v].bits[i];
			}
			tree[v].sum += two * tree[v].bits[i];
		}
	}
	void push(int v, int lx, int rx) {
		if (lx + 1 == rx) {
			return;
		}
		int m = (lx + rx) / 2;
		apply(2 * v + 1, lx, m, mod[v]);
		apply(2 * v + 2, m, rx, mod[v]);
		tree[v] = merge(tree[2 * v + 1], tree[2 * v + 2]);
		apply(v, lx, rx, mod[v]);
	}
	void upd(int v, int lx, int rx, int l, int r, int x) {
		if (l <= lx and rx <= r) {
			apply(v, lx, rx, x);
			return;
		}
		if (rx <= l or r <= lx)
			return;
		int m = (lx + rx) / 2;
		apply(v, lx, rx, 0);
		push(v, lx, rx);
		upd(2 * v + 1, lx, m, l, r, x);
		upd(2 * v + 2, m, rx, l, r, x);
		tree[v] = merge(tree[2 * v + 1], tree[2 * v + 2]);
		apply(v, lx, rx, 0);
	}
	void upd(int l, int r, int x) {
		upd(0, 0, size, l, r, x);
	}
	int get(int v, int lx, int rx, int l, int r) {
		if (l <= lx and rx <= r) {
			return tree[v].sum;
		}
		if (rx <= l or r <= lx)
			return 0;
		push(v, lx, rx);
		int m = (lx + rx) / 2;
		int s1 = get(2 * v + 1, lx, m, l, r);
		int s2 = get(2 * v + 2, m, rx, l, r);
		tree[v] = merge(tree[2 * v + 1], tree[2 * v + 2]);
		apply(v, lx, rx, 0);
		return s1 + s2;
	}
	int get(int l, int r) {
		return get(0, 0, size, l, r);
	}
};
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(7);
	int n; cin >> n;
	vector <int> a(n);
	for (auto& x : a) cin >> x;
	segtree st;
	st.init(n);
	st.build(a);
	int q; cin >> q;
	while (q-- > 0) {
		int cc; cin >> cc;
		if (cc == 1) {
			int l, r; cin >> l >> r;
			cout << st.get(l - 1, r) << '\n';
		}
		else {
			int l, r, x;
			cin >> l >> r >> x;
			st.upd(l - 1, r, x);
		}
	}
	return 0;
}