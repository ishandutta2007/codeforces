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

#define TEST 0

int n, q;
vi a;

bool read() {
#if !TEST
	if  (scanf("%d%d", &n, &q) < 2) {
		return 0;
	}
	a.resize(n);
	forn(i, n) {
		scanf("%d", &a[i]);
	}
#else
	n = rand() % 2 + 1;
	q = rand() % 5 + 1;
	a.resize(n);
	forn(i, n) {
		a[i] = rand() % 100;
	}
#endif
	return 1;
}

const int B = 10;

struct node {
	ll coef[B];
	int who[B];

	node() {
		memset (coef, 0, sizeof coef);
		reset_who();
	}

	node(ll x) : node() {
		ll pw = 1;
		while (x) {
			int dig = x % B;
			coef[dig] += pw;
			pw *= B;
			x /= B;
		}
	}

	void apply(int x, int y) {
		if  (x == y) {
			return;
		}
		forn(i, B) {
			if  (who[i] == x) {
				who[i] = y;
			}
		}
	}

	void push(node& other) {
		static int dest[B];
		forn(i, B) {
			dest[i] = who[other.who[i]];
		}
		memcpy(other.who, dest, sizeof dest);
	}

	void add(const node& other) {
		forn(i, B) {
			coef[other.who[i]] += other.coef[i];
		}
	}

	ll sum() const {
		ll res = 0;
		forn(i, B) {
			res += coef[i] * who[i];
		}
		return res;
	}

	void reset_who() {
		forn(i, B) {
			who[i] = i;
		}
	}

	void reset_comps() {
		static ll ncoef[B];
		memset (ncoef, 0, sizeof ncoef);
		forn(i, B) {
			ncoef[who[i]] += coef[i];
		}
		reset_who();
		memcpy(coef, ncoef, sizeof coef);
	}

	void print() const {
		forn(i, B) {
			printf("%d: coef=%lld, who=%d\n", i, coef[i], who[i]);
		}
	}
};

struct SegmTree {
	vector<node> t;
	int sz;

	SegmTree() {}

	SegmTree(const vi& a) {
		sz = 1;
		while (sz < sz(a)) sz *= 2;

		t.resize(sz * 2);
		forn(i, sz(a)) {
			t[sz + i] = node(a[i]);
		}
		for (int v = sz - 1; v > 0; --v) {
			recalc(v);
			// printf("v=%d, sum=%lld\n", v, t[v].sum());
		}

		// printf("root: %lld\n", t[1].sum());
	}

	void push(int v) {
		t[v].push(t[v * 2]);
		t[v].push(t[v * 2 + 1]);
		t[v].reset_comps();
	}

	void recalc(int v) {
		t[v] = node();
		t[v].add(t[v * 2]);
		t[v].add(t[v * 2 + 1]);
	}

	void change(int v, int tl, int tr, int l, int r, int x, int y) {
		l = max(l, tl);
		r = min(r, tr);

		if  (l > r) {
			return;
		}

		if  (l == tl && r == tr) {
			t[v].apply(x, y);
			return;
		}

		push(v);

		int tm = (tl + tr) >> 1;
		change(v * 2, tl, tm, l, r, x, y);
		change(v * 2 + 1, tm + 1, tr, l, r, x, y);

		recalc(v);

		// printf("after push, v*2=%d:\n", v*2);
		// t[v*2].print();
	}

	void change(int l, int r, int x, int y) {
		change(1, 0, sz - 1, l, r, x, y);
	}

	ll get(int v, int tl, int tr, int l, int r) {
		l = max(l, tl);
		r = min(r, tr);

		if  (l > r) {
			return 0;
		}

		if  (l == tl && r == tr) {
			return t[v].sum();
		}

		push(v);

		int tm = (tl + tr) >> 1;
		ll res = get(v * 2, tl, tm, l, r);
		res += get(v * 2 + 1, tm + 1, tr, l, r);

		recalc(v);

		// printf("after push, v*2=%d:\n", v*2);
		// t[v*2].print();

		return res;
	}

	ll get(int l, int r) {
		return get(1, 0, sz - 1, l, r);
	}
};

int do_replace(int num, int x, int y) {
	int nw = 0;
	int pw = 1;
	while (num) {
		int dig = num % 10;
		num /= 10;
		if  (dig == x) {
			dig = y;
		}
		nw = pw * dig + nw;
		pw *= 10;
	}
	return nw;
}

namespace Brut {
	vi a;

	ll get(int l, int r) {
		ll res = 0;
		for (int i = l; i <= r; ++i) {
			res += a[i];
		}
		return res;
	}

	void change(int l, int r, int x, int y) {
		for (int i = l; i <= r; ++i) {
			a[i] = do_replace(a[i], x, y);
		}
	}
};

void solve() {
#if TEST
	printf("n=%d\n", n);
	forn(i, n) {
		printf("%d ", a[i]);
	}
	puts("");
	Brut::a = a;
#endif
	// puts("a:");
	// forn(i, n) {
	// 	printf("%d ", a[i]);
	// }
	// puts("");

	SegmTree T(a);

	// printf("sum = %lld\n", T.get(0, n - 1));

	forn(it, q) {
		int type;

#if !TEST
		scanf("%d", &type);
#else
		type = rand() % 2 + 1;
#endif

		int l, r;
		
#if !TEST
		scanf("%d%d", &l, &r);
		--l;
		--r;
#else
		l = rand() % n;
		r = rand() % n;
		if (l > r) {
			swap(l, r);
		}
		printf("l=%d, r=%d\n", l, r);
#endif

		if  (type == 1) {
			int x, y;
#if !TEST
			scanf("%d%d", &x, &y);
#else
			x = rand() % 10;
			y = rand() % 9 + 1;
			printf("%d -> %d\n", x, y);
#endif

			assert(y);
#if TEST
			Brut::change(l, r, x, y);
#endif
			T.change(l, r, x, y);
		} else if  (type == 2) {
#if !TEST
			printf("%lld\n", T.get(l, r));
#else
			ll my = T.get(l, r);
			ll br = Brut::get(l, r);
			if  (my != br) {
				printf("my=%lld, br=%lld\n", my, br);
				exit(0);
			}
#endif
		} else {
			assert(0);
		}

		// printf("it=%d:\n", it);
		// forn(i, n) {
		// 	printf("%lld ", T.get(i, i));
		// }
		// puts("");
	}
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		solve();

		// break;
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}