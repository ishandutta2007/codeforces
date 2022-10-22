#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <cassert>
using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define int long long
#define ld long double
struct segtree {
	int size;
	vector <int> tree;
	void build(int v, int lx, int rx, vector <int>&a) {
		if (lx + 1 == rx) {
			if (lx < a.size()) tree[v] = a[lx];
			else tree[v] = -1e9;
			return;
		}
		int m = (lx + rx) / 2;
		build(2 * v + 1, lx, m, a);
		build(2 * v + 2, m, rx, a);
		tree[v] = max(tree[2 * v + 1], tree[2 * v + 2]);
	}
	void init(vector <int>& a) {
		int n = a.size();
		size = 1;
		while (size < n) size *= 2;
		tree.resize(2 * size - 1);
		build(0, 0, size, a);
	}
	int get(int v, int lx, int rx, int l, int r) {
		if (l <= lx and rx <= r) {
			return tree[v];
		}
		if (rx <= l or r <= lx) {
			return -1e9;
		}
		int m = (lx + rx) / 2;
		int s1 = get(2 * v + 1, lx, m, l, r);
		int s2 = get(2 * v + 2, m, rx, l, r);
		return max(s1, s2);
	}
	int get(int l, int r) {
		return get(0, 0, size, l, r);
	}
};
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int testcases; cin >> testcases;
	while (testcases --> 0) {
		int n, m; cin >> n >> m;
		string s;
		vector <int> a(n), b(n);
		cin >> s;
		for (int i = 0; i < n; ++i) {
			a[i] = (s[i] == '-' ? -1 : 1);
			if (i) a[i] += a[i - 1];
			b[i] = -a[i];
		}
		segtree s1, s2;
		s1.init(a), s2.init(b);
		while (m --> 0) {
			int l, r; cin >> l >> r;
			int add = 0;
			if (l != 1)
				add = -a[r - 1] + a[l - 2];
			else add = -a[r - 1];
			int mx1 = s1.get(0, l - 1);
			int mx2 = s1.get(r, n) +add;
			int mn1 = s2.get(0, l - 1);
			int mn2 = s2.get(r, n) - add;
			mx1 = max(mx1, mx2), mn1 = max(mn1, mn2);
			mx1 = max(0ll, mx1), mn1 = max(0ll, mn1);
			cout << mx1 + mn1 + 1 << '\n';
		}

	}
	return 0;
}