#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <cstdlib>
#include <memory>
#include <queue>
#include <cassert>
#include <cmath>
#include <ctime>
#include <complex>
#include <bitset>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <numeric>

using namespace std;

#define ws ws_____________________
#define y1 y1_____________________
#define y0 y0_____________________
#define left left_________________
#define right right_______________
#define next next_________________
#define prev prev_________________
#define hash hash_________________

#define pb push_back
#define fst first
#define snd second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define all(C) begin(C), end(C)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;

#define FILE_NAME "a"

const int MAXN = 1e5 + 10;

int n, k;
int m;
vi g[MAXN];
int q;

bool read() {
	if  (scanf("%d%d", &n, &k) < 2) {
		return 0;
	}
	forn(i, n) {
		g[i].clear();
	}
	scanf("%d", &m);
	forn(i, m) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u;
		--v;
		g[u].pb(v);
		g[v].pb(u);
	}
	return 1;
}

struct Node {
	int mid;
	vi lc;
	vi rc;
	int l, r;

	Node() {}

	Node(int pos) {
		mid = 0;
		l = r = pos;
		lc.pb(0);
		rc.pb(0);
	}

	int get_color(int i) {
		if  (l <= i && i - l < sz(lc)) {
			return lc[i - l];
		}
		if  (i <= r && (r - i) < sz(rc)) {
			return rc[r - i];
		}
		return -1;
	}

	void shift(int d) {
		for (int& c : lc) {
			c += d;
		}
		for (int& c : rc) {
			c += d;
		}
	}

	int cnt_colors() const {
		int mx = -1;
		for (int c : lc) {
			mx = max(mx, c);
		}
		for (int c : rc) {
			mx = max(mx, c);
		}
		return mx + 1;
	}

	void renum() {
		vi cs;
		for (int c : lc) {
			cs.pb(c);
		}
		for (int c : rc) {
			cs.pb(c);
		}
		sort(all(cs));
		cs.resize(unique(all(cs)) - cs.begin());

		for (int& c : lc) {
			c = lower_bound(all(cs), c) - cs.begin();
		}
		for (int& c : rc) {
			c = lower_bound(all(cs), c) - cs.begin();
		}
	}

	int get_ans() const {
		vi cs;
		for (int c : lc) {
			cs.pb(c);
		}
		for (int c : rc) {
			cs.pb(c);
		}
		sort(all(cs));
		cs.resize(unique(all(cs)) - cs.begin());

		return sz(cs) + mid;	
	}

	void print() const {
		printf("[%d, %d], mid=%d\n", l, r, mid);
		printf("lc:\n");
		for (int c : lc) {
			printf("%d ", c);
		}
		puts("");
		printf("rc:\n");
		for (int c : rc) {
			printf("%d ", c);
		}
		puts("");
	}
};

int par[MAXN];

struct DSU {
	int n;

	DSU(int n = 0) : n(n) {
		forn(i, n) {
			par[i] = -1;
		}
	}

	int get(int x) {
		// printf("x=%d, n=%d\n", x, n);
		assert(0 <= x && x < n);
		return par[x] < 0 ? x : par[x] = get(par[x]);
	}

	bool union_set(int x, int y) {
		x = get(x);
		y = get(y);
		if  (x == y) {
			return 0;
		}
		if  (-par[x] < -par[y]) {
			swap(x, y);
		}
		par[x] += par[y];
		par[y] = x;
		return 1;
	}
};

Node merge(Node left, Node right) {
	// printf("merge:\n");
	// printf("left:\n");
	// left.print();
	// printf("right:\n");
	// right.print();

	Node res;
	res.l = left.l;
	res.r = right.r;
	res.mid = left.mid + right.mid;

	int left_colors = left.cnt_colors();
	int right_colors = right.cnt_colors();

	right.shift(left_colors);

	// printf("left_colors = %d, right_colors = %d\n", left_colors, right_colors);

	DSU dsu(left_colors + right_colors);
	for (int i = left.r; i >= left.l; --i) {
		int c = left.get_color(i);
		// printf("from i = %d\n", i);
		if  (c == -1) {
			break;
		}
		for (int to : g[i]) {
			int c_to = right.get_color(to);
			if  (c_to == -1) {
				continue;
			}
			// printf("to=%d, c_to=%d, c=%d\n", to, c_to, c);
			dsu.union_set(c, c_to);
		}
	}

	vi in_res(left_colors + right_colors, 0);

	for (int i = left.l; i <= right.r && i < left.l + k; ++i) {
		int c = left.get_color(i);
		if  (c == -1) {
			c = right.get_color(i);
		}
		assert(c != -1);
		// printf("i=%d, c=%d\n", i, c);
		res.lc.pb(dsu.get(c));
		in_res[dsu.get(c)] = 1;
	}

	for (int i = right.r; i >= left.l && i > right.r - k; --i) {
		int c = left.get_color(i);
		if  (c == -1) {
			c = right.get_color(i);
		}
		assert(c != -1);
		// printf("i=%d, c=%d\n", i, c);
		res.rc.pb(dsu.get(c));
		in_res[dsu.get(c)] = 1;
	}

	vi was(left_colors + right_colors, 0);
	
	auto add_to_mid = [&](int c) {
		// printf("check c=%d\n", c);
		c = dsu.get(c);
		if  (was[c] || in_res[dsu.get(c)]) {
			return;
		}
		was[c] = 1;
		++res.mid;
	};

	{
		for (int i = left.l; ; ++i) {
			int c = left.get_color(i);
			if  (c == -1) {
				break;
			}
			add_to_mid(c);
		}

		for (int i = right.l; ; ++i) {
			int c = right.get_color(i);
			if  (c == -1) {
				break;
			}
			add_to_mid(c);
		}

		for (int i = left.r; ; --i) {
			int c = left.get_color(i);
			if  (c == -1) {
				break;
			}
			add_to_mid(c);
		}

		for (int i = right.r; ; --i) {
			int c = right.get_color(i);
			if  (c == -1) {
				break;
			}
			add_to_mid(c);
		}
	}

	res.renum();

	// printf("GET:\n");
	// res.print();
	// puts("-----");

	return res;
}

Node t[MAXN * 4];

void build(int v, int tl, int tr) {
	if  (tl == tr) {
		t[v] = Node(tl);
		return;
	}

	int tm = (tl + tr) >> 1;
	build(v * 2, tl, tm);
	build(v * 2 + 1, tm + 1, tr);
	t[v] = merge(t[v * 2], t[v * 2 + 1]);
}

void precalc() {
	build(1, 0, n - 1);
}

Node ask(int v, int tl, int tr, int l, int r) {
	l = max(l, tl);
	r = min(r, tr);

	assert(l <= r);

	if  (l == tl && r == tr) {
		return t[v];
	}

	int tm = (tl + tr) >> 1;
	if  (r <= tm) {
		return ask(v * 2, tl, tm, l, r);
	}
	if  (tm < l) {
		return ask(v * 2 + 1, tm + 1, tr, l, r);
	}
	return merge(ask(v * 2, tl, tm, l, r), ask(v * 2 + 1, tm + 1, tr, l, r));
}

int ask(int l, int r) {
	auto node = ask(1, 0, n - 1, l, r);
	return node.get_ans();
}

void solve() {
	precalc();

	scanf("%d\n", &q);
	forn(it, q) {
		int l, r;
		scanf("%d%d", &l, &r);
		--l;
		--r;
		printf("%d\n", ask(l, r));
	}
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		solve();
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}