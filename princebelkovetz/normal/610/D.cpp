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
struct point {
	int x, y, z;
};
struct event {
	int ok, x, hi, lo, b;
	//ok = 0 for yline, = 1 for xline
};
bool cmp(point& a, point& b) {
	if (a.x != b.x) return a.x < b.x;
	return a.z > b.z;
}
bool cmp2(event& a, event& b) {
	if (a.x != b.x) return a.x < b.x;
	if (a.ok != b.ok) {
		if (a.b) {
			return a.b > 0;
		}
		else {
			return b.b < 0;
		}
	}
	return a.b > b.b;
}
struct segtree {
	int size;
	vector <int> tree;
	void init(int n) {
		size = 1;
		while (size < n) size *= 2;
		tree.resize(2 * size - 1);
	}
	void upd(int v, int lx, int rx, int i, int x) {
		if (lx + 1 == rx) {
			tree[v] += x;
			assert(tree[v] <= 1);
			assert(tree[v] >= 0);
			return;
		}
		int m = (lx + rx) / 2;
		if (i < m)
			upd(2 * v + 1, lx, m, i, x);
		else
			upd(2 * v + 2, m, rx, i, x);
		tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
	}
	void upd(int i, int x) {
		upd(0, 0, size, i, x);
	}
	int get(int v, int lx, int rx, int l, int r) {
		if (l <= lx and rx <= r) return tree[v];
		if (rx <= l or r <= lx) return 0;
		int m = (lx + rx) / 2;
		int s1 = get(2 * v + 1, lx, m, l, r);
		int s2 = get(2 * v + 2, m, rx, l, r);
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
	vector <point> yc, xc;
	map <int, int> xbalance, ybalance;
	map <int, int> curx, cury;
	for (int i = 0; i < n; ++i) {
		int x0, y0, x1, y1;
		cin >> x0 >> y0 >> x1 >> y1;
		if (x0 == x1) {
			if (y0 > y1) swap(y0, y1);
			yc.push_back({ y0, x0, 1 });
			yc.push_back({ y1, x0, -1 });
		}
		else if (y0 == y1) {
			if (x0 > x1) swap(x0, x1);
			xc.push_back({ x0, y0, 1 });
			xc.push_back({ x1, y0, -1 });
			xbalance[y0] = 0;
		}
	}
	sort(xc.begin(), xc.end(), cmp);
	sort(yc.begin(), yc.end(), cmp);
	vector <point> newy, newx;

	for (auto x : xc) {
		if (!xbalance[x.y]) curx[x.y] = x.x;
		xbalance[x.y] += x.z;
		if (!xbalance[x.y]) {
			newx.push_back({ curx[x.y], x.x, x.y });
		}
	}

	for (auto x : yc) {
		if (!ybalance[x.y]) cury[x.y] = x.x;
		ybalance[x.y] += x.z;
		if (!ybalance[x.y]) {
			newy.push_back({ cury[x.y], x.x, x.y });
		}
	}
	int fully = 0;
	set <int> ally;
	for (auto x : newx) {
		fully += x.y - x.x + 1;
		ally.insert(x.z);
	}
	for (auto x : newy) {
		fully += x.y - x.x + 1;
		ally.insert(x.x);
		ally.insert(x.y);
	}
	map <int, int> change;
	int cnt = 0;
	for (auto x : ally) {
		change[x] = cnt++;
	}
	vector <event> line;
	for (auto x : newx) {
		line.push_back({ 1, x.x, change[x.z], 0, 1 });
		line.push_back({ 1, x.y, change[x.z], 0, -1 });
	}
	for (auto x : newy) {
		if (x.x < x.y) swap(x.x, x.y);
		line.push_back({ 0, x.z, change[x.x], change[x.y], 0 });
	}
	sort(line.begin(), line.end(), cmp2);
	int inters = 0;
	segtree st;
	st.init(cnt);
	//debug(fully)
	for (auto x : line) {
		//cout << x.ok << ' ' << x.hi << ' ' << x.lo << ' ' << x.x << ' ' << x.b << '\n';
		if (x.ok) {
			st.upd(x.hi, x.b);
		}
		else {
			inters += st.get(x.lo, x.hi + 1);
		}
		//debug(inters)
	}
	cout << fully - inters << '\n';
}