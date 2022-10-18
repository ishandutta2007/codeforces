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

int n, p, q, r;
vi a;
vi b;
vi c;

bool read() {
#if TEST
	n = 1 + rand() % 500;
	p = 1 + rand() % 500;
	q = 1 + rand() % 500;
	r = 1 + rand() % 500;
	a.resize(n);
	b.resize(n);
	c.resize(n);
	forn(i, n) {
		a[i] = rand() % p;
		b[i] = rand() % q;
		c[i] = rand() % r;
	}
	return 1;
#else
	if  (scanf("%d%d%d%d", &n, &p, &q, &r) < 4) {
		return 0;
	}
	a.resize(n);
	b.resize(n);
	c.resize(n);
	forn(i, n) {
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
		--a[i];
		--b[i];
		--c[i];
	}
	return 1;
#endif
}

struct SegmTree {
	vi put;
	vll sum;
	vi mx;
	int sz;

	SegmTree(int n = 0) {
		sz = 1;
		while (sz < n) sz *= 2;

		put.assign(sz * 2, -1);
		sum.assign(sz * 2, 0);
		mx.assign(sz * 2, -1);
		for (int v = sz; v < sz * 2; ++v) {
			sum[v] = -1;
		}
		for (int v = sz - 1; v > 0; --v) {
			recalc(v);
		}
	}

	void recalc(int v) {
		assert(put[v] == -1);
		sum[v] = sum[v * 2] + sum[v * 2 + 1];
		mx[v] = max(mx[v * 2], mx[v * 2 + 1]);
	}

	void push(int v, int tl, int tr) {
		if  (put[v] == -1) {
			return;
		}
		const int len = (tr - tl + 1) >> 1;
		const int val = put[v];
		put[v] = -1;
		const ll nsum = val * 1ll * len;

		put[v * 2] = val;
		sum[v * 2] = nsum;
		mx[v * 2] = val;

		put[v * 2 + 1] = val;
		sum[v * 2 + 1] = nsum;
		mx[v * 2 + 1] = val;
	}

	void go_put(int v, int tl, int tr, int l, int r, int val) {
		l = max(l, tl);
		r = min(r, tr);

		if  (l > r) {
			return;
		}

		if  (l == tl && r == tr) {
			put[v] = val;
			sum[v] = (tr - tl + 1) * 1ll * val;
			mx[v] = val;
			return;
		}

		push(v, tl, tr);

		const int tm = (tl + tr) >> 1;
		go_put(v * 2, tl, tm, l, r, val);
		go_put(v * 2 + 1, tm + 1, tr, l, r, val);

		recalc(v);
	}

	void go_put(int l, int r, int val) {
		go_put(1, 0, sz - 1, l, r, val);
	}

	int get_max(int v, int tl, int tr, int l, int r) {
		l = max(l, tl);
		r = min(r, tr);

		if  (l > r) {
			return -1;
		}

		if  (l == tl) {
			return mx[v];
		}

		push(v, tl, tr);

		const int tm = (tl + tr) >> 1;
		int ans = -1;
		if  (l <= tm) {
			ans = get_max(v * 2, tl, tm, l, r);
		} else {
			ans = get_max(v * 2 + 1, tm + 1, tr, l, r);
		}

		recalc(v);

		return ans;
	}
	

	int get_right_gr(int v, int tl, int tr, int l, int r, int val) {
		l = max(l, tl);
		r = min(r, tr);

		if  (l > r) {
			return -1;
		}

		if  (tl == tr) {
			return tl;
		}

		if  (get_max(v, tl, tr, l, r) <= val) {
			return -1;
		}

		push(v, tl, tr);

		int ans = -1;
		const int tm = (tl + tr) >> 1;
		if  (r > tm && mx[v * 2 + 1] > val) {
			ans = get_right_gr(v * 2 + 1, tm + 1, tr, l, r, val);
		} else {
			ans = get_right_gr(v * 2, tl, tm, l, r, val);
		}

		recalc(v);

		return ans;
	}

	int get_right_gr(int l, int r, int val) {
		return get_right_gr(1, 0, sz - 1, l, r, val);
	}

	ll get_sum(int v, int tl, int tr, int l, int r) {
		l = max(l, tl);
		r = min(r, tr);

		if  (l > r) {
			return 0;
		}

		if  (l == tl && r == tr) {
			return sum[v];
		}

		push(v, tl, tr);

		int tm = (tl + tr) >> 1;
		ll ans = get_sum(v * 2, tl, tm, l, r) + get_sum(v * 2 + 1, tm + 1, tr, l, r);
		recalc(v);
		return ans;
	}

	ll get_sum(int l, int r) {
		return get_sum(1, 0, sz - 1, l, r);
	}
};

struct Solver {
	SegmTree T;
	int X, Y;

	Solver() {}

	Solver(int X, int Y) : X(X), Y(Y) {
		T = SegmTree(X);
	}

	void push(int x, int y) {
		int pos = T.get_right_gr(0, x, y);
		if  (pos < x) {
			T.go_put(pos + 1, x, y);
		}
	}

	ll get(int x0, int y0) {
		int pos = T.get_right_gr(x0, X - 1, y0 - 1);
		if  (pos == -1) {
			return (Y - 1 - (y0 - 1)) * 1ll * (X - x0); 
		}
		ll ans = 0;
		ans += (Y - 1) * 1ll * (pos - x0 + 1) - T.get_sum(x0, pos);
		if  (pos >= X - 1) {
			return ans;
		}
		ans += (Y - 1 - (y0 - 1)) * 1ll * (X - (pos + 1));
		return ans;
	}
};

ll solve() {
	vi perm(n);
	forn(i, n) {
		perm[i] = i;
	}
	sort(all(perm), [&](int i, int j) { return c[i] < c[j]; });

	vi mx_a(n + 1, -1);
	ford(i, n) {
		mx_a[i] = a[perm[i]];
		mx_a[i] = max(mx_a[i], mx_a[i + 1]);
	}

	vi mx_b(n + 1, -1);
	ford(i, n) {
		mx_b[i] = b[perm[i]];
		mx_b[i] = max(mx_b[i], mx_b[i + 1]);
	}

	Solver solver(p, q);
	ll ans = 0;
	int ptr = 0;
	forn(C, r) {
		while (ptr < n && c[perm[ptr]] < C) {
			solver.push(a[perm[ptr]], b[perm[ptr]]);
			++ptr;
		}

		const int start_a = mx_a[ptr] + 1;
		const int start_b = mx_b[ptr] + 1;
		ll cur = 0;
		cur += solver.get(start_a, start_b);

		// printf("with c=%d --> %lld\n", C, cur);

		ans += cur;
	}

	return ans;
}

ll brut() {
	ll ans = 0;
	for (int A = 0; A < p; ++A) {
		for (int B = 0; B < q; ++B) {
			for (int C = 0; C < r; ++C) {
				bool ok = 1;
				forn(i, n) {
					bool win = 0;
					win |= A > a[i] && B > b[i];
					win |= B > b[i] && C > c[i];
					win |= A > a[i] && C > c[i];
					if  (!win) {
						ok = 0;
						break;
					}
				}
				if  (ok) {
					++ans;
				}
			}
		}
	}
	return ans;
}
//
int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

#if TEST
	while (1) {
		read();

		ll my = solve();
		ll br = brut();

		if  (my == br) {
			printf("OK n=%d, my=%lld, br=%lld\n", n, my, br);
			continue;
		}

		printf("FAIL n=%d\n", n);
		printf("%d %d %d\n", p, q, r);
		forn(i, n) {
			printf("%d %d %d\n", a[i], b[i], c[i]);
		}
		printf("my=%lld, br=%lld\n", my, br);
		exit(0);
	}
#endif

	while (read()) {
		cout << solve() << endl;
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}