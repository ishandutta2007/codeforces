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

using namespace std;

#define pb push_back
#define fst first
#define snd second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define next jskdfksdhfjkdsjksdjkgf
#define prev koeuigrihjdkjdfj
#define hash kjfdkljkdhgjdkfhgurehg
#define all(C) begin(C), end(C)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef vector <vector <int> > vvi;
typedef vector <pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

#define FILE_NAME "a"

const ld EPS = 1e-9;
const int MAXN = 2e5 + 10;

const int MOD = 1e9 + 7;

void add(int& x, int y) {
	((x += y) >= MOD) && (x -= MOD);
}

int mul(int x, int y) {
	return x * 1ll * y % MOD;
}

struct SegmTreeMul {
	vi sum;
	vi to_mul;
	int sz;

	SegmTreeMul(int n = 0) {
		sz = 1;
		while (sz < n) sz *= 2;
		to_mul.assign(sz * 2, 1);
		sum.assign(sz * 2, 0);
	}

	void upd(int v) {
		assert(to_mul[v] == 1);
		sum[v] = sum[v * 2];
		add(sum[v], sum[v * 2 + 1]);
	}

	void push(int v) {
		to_mul[v * 2] = mul(to_mul[v * 2], to_mul[v]);
		sum[v * 2] = mul(sum[v * 2], to_mul[v]);
		to_mul[v * 2 + 1] = mul(to_mul[v * 2 + 1], to_mul[v]);
		sum[v * 2 + 1] = mul(sum[v * 2 + 1], to_mul[v]);
		to_mul[v] = 1;
		upd(v);	
	}

	void go_mul(int v, int tl, int tr, int l, int r, int val) {
		l = max(l, tl);
		r = min(r, tr);

		if  (l > r) {
			return;
		}

		if  (l == tl && r == tr) {
			to_mul[v] = mul(to_mul[v], val);
			sum[v] = mul(sum[v], val);
			return;
		}

		push(v);
		int tm = (tl + tr) / 2;
		go_mul(v * 2, tl, tm, l, r, val);
		go_mul(v * 2 + 1, tm + 1, tr, l, r, val);
		upd(v);
	}

	void go_mul(int l, int r, int val) {
		go_mul(1, 0, sz - 1, l, r, val);
	}

	int get_sum(int v, int tl, int tr, int l, int r) {
		l = max(l, tl);
		r = min(r, tr);

		if  (l > r) return 0;

		if  (l == tl && r == tr) {
			return sum[v];
		}
		assert(v * 2 < sz(sum));

		int tm = (tl + tr) / 2;
		push(v);
		int ans = get_sum(v * 2, tl, tm, l, r);
		add(ans, get_sum(v * 2 + 1, tm + 1, tr, l, r));
		upd(v);
		return ans;
	}

	int get(int pos) {
		return get_sum(pos, pos);
	}

	int get_sum(int l, int r) {
		assert(0 <= l && r < sz);
		return get_sum(1, 0, sz - 1, l, r);
	}

	void put(int v, int tl, int tr, int pos, int val) {
		if  (pos < tl || tr < pos) return;

		if  (tl == tr) {
			to_mul[v] = 1;
			sum[v] = val;
			return;
		}

		push(v);
		int tm = (tl + tr) / 2;
		put(v * 2, tl, tm, pos, val);
		put(v * 2 + 1, tm + 1, tr, pos, val);
		upd(v);
	}

	void put(int pos, int val) {
		put(1, 0, sz - 1, pos, val);
		assert(get(pos) == val);
	}
};

struct Query {
	int t;
	int p, v;
	int u;

	void read() {
		scanf("%d", &t);
		if  (t == 1) {
			scanf("%d%d", &p, &v);
			--p;
		} else {
			scanf("%d", &u);
			--u;
		}
	}
};

int mpow(int a, int p) {
	int res = 1;
	for (; p > 0; p /= 2, a = mul(a, a))
		if  (p & 1)
			res = mul(res, a);
	return res;
}

int inv(int x) {
	int ix = mpow(x, MOD - 2);
	assert(mul(x, ix) == 1);
	return ix;
}

int val[MAXN];
vi sons[MAXN];
int cur_deg[MAXN];
int n;
int q;
vector<Query> qs;
int tin[MAXN];
int tout[MAXN];
int timer;
vi order;
SegmTreeMul mul_ans_to_root;
SegmTreeMul mul_deg_to_root;
int parent[MAXN];

bool read() {
	if  (scanf("%d%d", &val[0], &q) < 2) {
		return false;
	}
	forn(i, q) {
		Query Q;
		Q.read();
		qs.pb(Q);
	}
	return true;
}

int get_ans(int v) {
	int l = tin[v];
	int r = tout[v];
	assert(order[l] == v);
	int res = mul_ans_to_root.get_sum(l, r);
	if  (v == 0) {
		return res;
	}
	int to_root = mul_deg_to_root.get(tin[parent[v]]);
	res = mul(res, inv(to_root));
	return res;
}

void dfs(int v) {
	tin[v] = timer++;
	order.pb(v);
	for (int to : sons[v]) {
		dfs(to);
	}
	tout[v] = timer - 1;
}

void precalc() {
	memset (parent, -1, sizeof parent);
	int ptr = 1;
	forn(i, q) {
		Query Q = qs[i];
		if  (Q.t == 1) {
			sons[Q.p].pb(ptr);
			parent[ptr] = Q.p;
			++ptr;
		}
	}
	n = ptr;

	timer = 0;
	dfs(0);

	forn(v, n) cur_deg[v] = 1;

	// puts("order:");
	// for (int v : order) {
	// 	printf("%d ", v);
	// }
	// puts("");
	// forn(v, n) {
	// 	printf("%d -> [%d, %d]\n", v, tin[v], tout[v]);
	// }
}

void solve() {
	precalc();

	mul_ans_to_root = SegmTreeMul(sz(order));
	mul_deg_to_root = SegmTreeMul(sz(order));

	mul_deg_to_root.put(0, 1);
	mul_ans_to_root.put(0, val[0]);

	int ptr = 1;
	forn(i, q) {
		// printf("next q ----\n");
		Query Q = qs[i];
		if  (Q.t == 1) {
			int v = ptr++;
			int pos = tin[v];

			int l = tin[Q.p];
			int r = tout[Q.p];
			mul_deg_to_root.go_mul(l, r, inv(cur_deg[Q.p]));
			mul_ans_to_root.go_mul(l, r, inv(cur_deg[Q.p]));
			++cur_deg[Q.p];
			mul_deg_to_root.go_mul(l, r, cur_deg[Q.p]);
			mul_ans_to_root.go_mul(l, r, cur_deg[Q.p]);

			int deg_to_root = mul_deg_to_root.get(l);
			mul_ans_to_root.put(pos, mul(deg_to_root, Q.v));
			mul_deg_to_root.put(pos, deg_to_root);
		} else {
			printf("%d\n", get_ans(Q.u));
		}
	}

	// ford(i, n) {
	// 	printf("ans(%d) = %d\n", i, get_ans(i));
	// }

	// forn(v, n) {
	// 	printf("v = %d\n", v);
	// 	printf("deg to root = %d\n", mul_deg_to_root.get(tin[v]));
	// 	printf("ans to root = %d\n", mul_ans_to_root.get(tin[v]));
	// }
}

int main() {
#ifdef DEBUG
	freopen(FILE_NAME ".in", "r", stdin);
//	freopen(FILE_NAME ".out", "w", stdout);
#endif
	
	while (read()) {
		solve();
	}
	return 0;
}