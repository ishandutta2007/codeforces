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
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
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

const int MAXN = 3e5 + 10;

struct Seg {
	ll lval;
	ll rval;
	int best;
	int LC;
	int L;
	int RC;
	int R;
	int center;
	int tl;
	int tr;
	bool bad;

	Seg() {
		bad = 1;
	}

	Seg(ll val, int tl, int tr) : tl(tl), tr(tr) {
		lval = rval = val;
		best = 1;
		LC = 1;
		L = 1;
		RC = 1;
		R = 1;
		center = tl;
		bad = 0;
	}

	void go_add(ll val) {
		lval += val;
		rval += val;
	}

	void print() const {
 		printf("[%d, %d], lval=%lld, rval=%lld, best=%d, center=%d, RC=%d\n", tl, tr, lval, rval, best, center, RC);
	}
};

Seg merge_segs(const Seg& left, const Seg& right) {
	if  (left.bad) {
		return right; 
	}
	if  (right.bad) {
		return left;
	}

	Seg res;
	res.bad = 0;
	res.lval = left.lval;
	res.rval = right.rval;
	res.tl = left.tl;
	res.tr = right.tr;

	res.LC = left.LC;
	if  (left.center != -1 && right.lval < left.rval) {
		res.LC = max(res.LC, left.best + right.L);
	}
	if  (left.center == left.tr && left.rval < right.lval) {
		res.LC = max(res.LC, left.best + right.LC);
	}

	res.L = left.L;
	if  (left.center == left.tl && right.lval < left.rval) {
		res.L = max(res.L, left.best + right.L);
	}

	res.RC = right.RC;
	if  (right.center != -1 && left.rval < right.lval) {
		res.RC = max(res.RC, left.R + right.best);
	}
	if  (right.center == right.tl && left.rval > right.lval) {
		res.RC = max(res.RC, right.best + left.RC);
	}

	res.R = right.R;
	if  (right.center == right.tr && left.rval < right.lval) {
		res.R = max(res.R, left.R + right.best);
	}

	// center
	res.center = -1;
	if  (left.center != -1 && right.center == right.tl && left.rval > right.lval) {
		res.center = left.center;
	}
	if  (right.center != -1 && left.center == left.tr && left.rval < right.lval) {
		res.center = right.center;
	}

	res.best = max(left.best, right.best);
	res.best = max(res.best, res.L);
	res.best = max(res.best, res.LC);
	res.best = max(res.best, res.R);
	res.best = max(res.best, res.RC);
	if  (left.rval < right.lval) {
		res.best = max(res.best, left.R + right.LC);
	}
	if  (left.rval > right.lval) {
		res.best = max(res.best, left.RC + right.L);
	}

	if  (res.center != -1) {
		res.RC = res.LC = res.best;
	}

	// printf("MERGE\n");
	// left.print();
	// right.print();
	// res.print();

	return res;
}

struct SegmTree {
	vector<Seg> t;
	vll add;
	int sz;

	SegmTree() {}

	SegmTree(const vi& a) {
		sz = 1;
		while (sz < sz(a)) sz *= 2;

		t.resize(sz * 2);
		add.assign(sz * 2, 0);

		init(1, 0, sz - 1, a);
 	}

 	void init(int v, int tl, int tr, const vi& a) {
 		if  (tl == tr) {
 			if  (tl < sz(a)) {
 				t[v] = Seg(a[tl], tl, tr);
 			} else {
 				t[v].bad = 1;
 			}
 		} else {
 			int tm = (tl + tr) >> 1;
 			init(v * 2, tl, tm, a);
 			init(v * 2 + 1, tm + 1, tr, a);
 			upd(v);
 		}
 	}

 	void upd(int v) {
 		assert(add[v] == 0);
 		t[v] = merge_segs(t[v * 2], t[v * 2 + 1]);
 	}

 	void push(int v) {
 		t[v * 2].go_add(add[v]);
 		t[v * 2 + 1].go_add(add[v]);
 		add[v * 2] += add[v];
 		add[v * 2 + 1] += add[v];
 		add[v] = 0;
 	}

 	void go_add(int v, int tl, int tr, int l, int r, int val) {
 		l = max(l, tl);
 		r = min(r, tr);

 		if  (l > r) {
 			return;
 		}

 		if  (l == tl && r == tr) {
 			t[v].go_add(val);
 			add[v] += val;
 			return;
 		}

 		push(v);

 		int tm = (tl + tr) >> 1;
 		go_add(v * 2, tl, tm, l, r, val);
 		go_add(v * 2 + 1, tm + 1, tr, l, r, val);

 		upd(v);
 	}

 	void go_add(int l, int r, int val) {
 		go_add(1, 0, sz - 1, l, r, val);
 	}

 	Seg get_max(int v, int tl, int tr, int l, int r) {
 		l = max(l, tl);
 		r = min(r, tr);

 		if  (l > r) {
 			return Seg();
 		}

 		if  (l == tl && r == tr) {
 			return t[v];
 		}

 		push(v);

 		int tm = (tl + tr) >> 1;
 		auto left = get_max(v * 2, tl, tm, l, r);
 		auto right = get_max(v * 2 + 1, tm + 1, tr, l, r);

 		upd(v);

 		return merge_segs(left, right);
 	}

 	Seg get_max(int l, int r) {
 		return get_max(1, 0, sz - 1, l, r);
 	}

 	void print(int v, int tl, int tr) {
 		if  (!t[v].bad) {
 			printf("v = %d\n", v);
 			t[v].print();
 		}
 		if  (tl == tr) {
 			return;
 		}
 		push(v);
 		int tm = (tl + tr) >> 1;
 		print(v * 2, tl, tm);
 		print(v * 2 + 1, tm + 1, tr);
 		upd(v);
 	}

 	void print() {
 		print(1, 0, sz - 1);
 	}
};

int n, m;
int a[MAXN];

bool read() {
	if  (scanf("%d", &n) < 1) {
		return 0;
	}
	forn(i, n) {
		scanf("%d", &a[i]);
	}
	return 1;
}

bool my_read() {
	n = rand() % 100 + 1;
	forn(i, n) {
		a[i] = rand() % 100;
	}
	return 1;
}

void brut_add(int l, int r, int d) {
	for (int i = l; i <= r; ++i) {
		a[i] += d;
	}
}

int brut_max() {
	int mx = 0;
	forn(i, n) {
		int l = i - 1;
		while (l >= 0 && a[l] < a[l + 1]) {
			--l;
		}
		++l;

		int r = i + 1;
		while (r < n && a[r] < a[r - 1]) {
			++r;
		}
		--r;

		mx = max(mx, r - l + 1);
		// printf("i = %d, len = %d\n", i, r - l + 1);
	}
	return mx;
}

void stress() {
	SegmTree T(vi(a, a + n));

	vi A(a, a + n);
	vi L;
	vi R;
	vi D;

	m = rand() % 100 + 1;
	forn(i, m) {
		int l, r, d;
		l = rand() % n;
		r = rand() % n;
		if  (l > r) {
			swap(l, r);
		}
		d = rand() % 100;

		L.pb(l);
		R.pb(r);
		D.pb(d);

		T.go_add(l, r, d);
		brut_add(l, r, d);
		// T.print();
		int my = T.get_max(0, n - 1).best;
		int br = brut_max();
		if  (my != br) {
			printf("n=%d\n", n);
			forn(i, n) {
				printf("%d ", A[i]);
			}
			puts("");
			forn(i, sz(L)) {
				printf("[%d, %d] += %d\n", L[i], R[i], D[i]);
			}
			forn(i, n) {
				printf("%d ", a[i]);
			}
			puts("");
			printf("my = %d, br = %d\n", my, br);
			exit(0);
		}
		printf("%d\n", my);
	} 
}

void solve() {
	SegmTree T(vi(a, a + n));

	scanf("%d", &m);
	forn(i, m) {
		int l, r, d;
		scanf("%d%d%d", &l, &r, &d);
		--l;
		--r;

		T.go_add(l, r, d);
		// T.print();

		int my = T.get_max(0, n - 1).best;
		printf("%d\n", my);
	} 
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	// while (my_read()) {
	// 	stress();
	// }

	while (read()) {
		solve();
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}