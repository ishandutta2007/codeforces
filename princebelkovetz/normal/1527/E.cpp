#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <iomanip>
#include <string>
using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#pragma GCC optimize("O3")
constexpr int inf = 1e9 + 7;
struct segtree {
	int size;
	vector <int> tree, mod;
	segtree(int n) {
		size = 1;
		while (size < n) size <<= 1;
		tree.resize(size * 2 - 1);
		mod.resize(2 * size - 1);
	}
	void nulling() {
		for (auto& x : tree)x = 0;
		for (auto& x : mod) x = 0;
	}
	void push(int v) {
		tree[2 * v + 1] += mod[v];
		mod[2 * v + 1] += mod[v];
		tree[2 * v + 2] += mod[v];
		mod[2 * v + 2] += mod[v];
		mod[v] = 0;
	}
	int get(int v, int lx, int rx, int l, int r) {
		if (l <= lx and rx <= r)
			return tree[v];
		if (r <= lx or rx <= l) return inf;
		int m = (lx + rx) / 2;
		push(v);
		return min(get(2 * v + 1, lx, m, l, r),
			get(2 * v + 2, m, rx, l, r));
	}
	int get(int l, int r) {
		return get(0, 0, size, l, r);
	}
	void upd(int v, int lx, int rx, int l, int r, int x) {
		if (l <= lx and rx <= r) {
			tree[v] += x;
			mod[v] += x;
			return;
		}
		if (rx <= l or r <= lx)
			return;
		int m = (lx + rx) / 2;
		push(v);
		upd(2 * v + 1, lx, m, l, r, x);
		upd(2 * v + 2, m, rx, l, r, x);
		tree[v] = min(tree[2 * v + 1], tree[2 * v + 2]);
	}
	void upd(int l, int r, int x) {
		upd(0, 0, size, l, r, x);
	}
};
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(8);
	int n, k; cin >> n >> k;
	vector <vector <int>> dp(k + 1, vector <int>(n + 1, inf));
	vector <int> a(n), last(n, -1);
	map <int, int> was;
	for (auto& x : a) cin >> x;
	for (int i = 0; i < n; ++i) {
		if (was.find(a[i]) != was.end())
			last[i] = was[a[i]];
		was[a[i]] = i;
	}
	dp[0][0] = 0;
	segtree ST(n + 1);
	for (int i = 1; i <= k; ++i) {
		ST.nulling();
		for (int j = 0; j <= n; ++j) {
			ST.upd(j, j + 1, dp[i - 1][j]);
		}
		for (int j = 1; j <= n; ++j) {
			ST.upd(0, last[j - 1] + 1, j - 1 - last[j - 1]);
			dp[i][j] = ST.get(0, j);
		}
	}
	cout << dp[k][n] << '\n';
}