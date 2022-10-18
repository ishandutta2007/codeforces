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

#ifdef LOCAL
#define eprintf(args...) fprintf(stderr, args), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define FILE_NAME "a"

const int MOD = 1e9 + 7;

void add(int& x, int y) {
	((x += y) >= MOD) && (x -= MOD);
}

int mul(int x, int y) {
	return x * 1ll * y % MOD;
}

int mpow(int a, int p) {
	int res = 1;
	for (; p > 0; p >>= 1, a = mul(a, a)) {
		if  (p & 1) {
			res = mul(res, a);
		}
	}
	return res;
}

int inv(int x) {
	int y = mpow(x, MOD - 2);
	assert(mul(x, y) == 1);
	return y;
}

struct Edge {
	int to;
	int val;
	int col;
};

int n;
vector<vector<Edge>> g;

bool read() {
	if  (scanf("%d", &n) < 1) {
		return 0;
	}
	g.clear();
	g.resize(n);
	forn(i, n - 1) {
		int a, b, val, col;
		scanf("%d%d%d%d", &a, &b, &val, &col);
		--a;
		--b;
		g[a].pb(Edge{b, val, col});
		g[b].pb(Edge{a, val, col});
	}
	return 1;
}

vi used;
vi sz;

void dfs_sz(int v, int p) {
	sz[v] = 1;
	for (auto e : g[v]) {
		if  (e.to == p || used[e.to]) {
			continue;
		}
		dfs_sz(e.to, v);
		sz[v] += sz[e.to];
	}
}

int get_root(int v) {
	dfs_sz(v, -1);
	const int S = sz[v];
	int p = -1;
	while (1) {
		int mx_to = -1;
		for (auto e : g[v]) {
			if  (e.to == p || used[e.to]) {
				continue;
			}
			if  (mx_to == -1 || sz[e.to] > sz[mx_to]) {
				mx_to = e.to;
			}
		}
		if  (mx_to == -1 || sz[mx_to] * 2 <= S) {
			return v;
		}
		p = v;
		v = mx_to;
	}
	assert(0);
	return -1;
}

struct Elem {
	int x, y, val;

	void print() const {
		eprintf("x=%d, y=%d, val=%d\n", x, y, val);
	}
};

void dfs_elems(int v, int p, int x, int y, int val, vector<Elem>& elems) {
	elems.pb(Elem{x, y, val});
	for (auto e : g[v]) {
		if  (e.to == p || used[e.to]) {
			continue;
		}
		dfs_elems(e.to, v, x + (e.col == 0), y + (e.col == 1), mul(val, e.val), elems);
	}
}

struct FenwTree {
	vi t;

	FenwTree(int n = 0) {
		t.assign(n, 1);
	}

	void change(int pos, int val) {
		for (int i = pos; i < sz(t); i |= i + 1) {
			t[i] = mul(t[i], val);
		}
	}

	int get(int r) {
		int ans = 1;
		for (int i = r; i >= 0; i &= i + 1, --i) {
			ans = mul(ans, t[i]);
		}
		return ans;
	}
};

const int ADD = 0;
const int ASK = 1;

struct Event {
	int type;
	int pos;
	int func;

	bool operator < (const Event& e) const {
		if  (func != e.func) {
			return func < e.func;
		}
		return (type == ADD) > (e.type == ADD);
	}
};

int calc(vector<Elem> left, vector<Elem> right) {
	sort(all(right), [](const Elem& e1, const Elem& e2) { return e1.x - 2 * e1.y < e2.x - 2 * e2.y; });

	vector<Event> es;
	forn(i, sz(left)) {
		Event e{ASK, i, 2 * left[i].x - left[i].y};
		es.pb(e);
	}
	forn(i, sz(right)) {
		Event e{ADD, i, right[i].y - 2 * right[i].x};
		es.pb(e);
	}

	sort(all(es));

	int ans = 1;

	// {
	// 	for (const auto& e1 : left) {
	// 		for (const auto& e2 : right) {
	// 			if  (e2.x - 2 * e2.y <= 2 * e1.y - e1.x && e2.y - 2 * e2.x <= 2 * e1.x - e1.y) {
	// 				ans = mul(ans, e2.val);
	// 			}
	// 		}
	// 	}
	// 	return ans;
	// }

	FenwTree T(sz(right));
	for (const auto& e : es) {
		if  (e.type == ADD) {
			T.change(e.pos, right[e.pos].val);
		} else {
			const auto elem = left[e.pos];
			int L = -1;
			int R = sz(right);
			while (L != R - 1) {
				int M = (L + R) >> 1;
				if  (right[M].x - 2 * right[M].y <= 2 * elem.y - elem.x) {
					L = M;
				} else {
					R = M;
				}
			}

			int prod = T.get(L);
			ans = mul(ans, prod);
		}
	}

	return ans;
}

int go(int tmp) {
	const int root = get_root(tmp);

	vector<vector<Elem>> elems;
	for (auto e : g[root]) {
		if  (used[e.to]) {
			continue;
		}
		vector<Elem> cur_elems;
		dfs_elems(e.to, root, e.col == 0, e.col == 1, e.val, cur_elems);
		elems.pb(cur_elems);
	}

	vector<Elem> all_elems;
	for (const auto& cur_elems : elems) {
		copy(all(cur_elems), back_inserter(all_elems));
	}
	int ans = calc(all_elems, all_elems);

	// eprintf("root=%d, all_ans=%d\n", root + 1, ans);
	// eprintf("all_elems:\n");
	// for (const auto& elem : all_elems) {
	// 	elem.print();
	// }
	// eprintf("\n");

	for (const auto& cur_elems : elems) {
		int cur_ans = calc(cur_elems, cur_elems);
		ans = mul(ans, inv(cur_ans));
	}

	for (const auto& elem : all_elems) {
		if  (elem.x * 2 >= elem.y && elem.y * 2 >= elem.x) {
			ans = mul(ans, elem.val);
		}
	}

	used[root] = 1;
	for (auto e : g[root]) {
		if  (!used[e.to]) {
			int cur = go(e.to);
			ans = mul(ans, cur);
		}
	}

	return ans;
}

int solve() {
	used.assign(n, 0);
	sz.assign(n, 0);
	int ans = go(0);
	return ans;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		printf("%d\n", solve());
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}