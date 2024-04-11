#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int mod = 1e9 + 7, N = 1e5 + 2, bb = 32;

struct segtree {
	int size;
	vector <int> tree;
	void build(int v, int lx, int rx, vector <int>& a) {
		if (lx + 1 == rx) {
			if (lx < a.size()) tree[v] = a[lx];
			return;
		}
		int m = (lx + rx) / 2;
		build(2 * v + 1, lx, m, a);
		build(2 * v + 2, m, rx, a);
		tree[v] = min(tree[2 * v + 1], tree[2 * v + 2]);
	}
	segtree(vector <int>& a) {
		int n = a.size();
		size = 1;
		while (size < n) size <<= 1;
		tree.resize(2 * size - 1);
		build(0, 0, size, a);
	}

	int get(int v, int lx, int rx, int l, int r) {
		if (l <= lx and rx <= r) return tree[v];
		if (rx <= l or r <= lx) return mod * mod;
		int m = (lx + rx) / 2;
		return min(get(2 * v + 1, lx, m, l, r),
			get(2 * v + 2, m, rx, l, r));
	}
	int get(int l, int r) {
		return get(0, 0, size, l, r);
	}
};

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, q; cin >> n >> q;

	vector <int> d(n), pref(n + 1), rpref;

	for (auto& x : d) cin >> x;
	for (auto& x : d) {
		int y; cin >> y;
		x -= y;
	}

	for (int i = 0; i < n; ++i)
		pref[i + 1] = pref[i] + d[i];

	rpref = pref;
	for (auto& x : rpref) x = -x;

	segtree ST1(pref), ST2(rpref);


	while (q--) {
		int l, r; cin >> l >> r;
		int mxpref = ST2.get(l, r) - rpref[l - 1];
		mxpref = -mxpref;
		int mnpref = ST1.get(l, r) - pref[l - 1];
		cout << (mxpref > 0 or pref[r] - pref[l - 1] != 0 ? -1 : -mnpref) << '\n'; 
	}

	return 0;
}