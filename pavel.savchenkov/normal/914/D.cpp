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

int n;
vi a;

bool read() {
	if  (scanf("%d", &n) < 1) {
		return 0;
	}
	a.resize(n);
	forn(i, n) {
		scanf("%d", &a[i]);
	}
	return 1;
}

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

struct SegmTree {
	vi t;
	int sz;

	SegmTree(int n = 0) {
		sz = 1;
		while (sz < n) sz *= 2;
		t.assign(sz * 2, 0);
	}

	int get_gcd(int l, int r) {
		l += sz;
		r += sz;
		int res = 0;
		while (l <= r) {
			if (l & 1) {
				res = gcd(res, t[l]);
				++l;
			}
			if (~r & 1) {
				res = gcd(res, t[r]);
				--r;
			}
			l >>= 1;
			r >>= 1;
		}
		return res;
	}

	int get_gcd(int v, int tl, int tr, int l, int r) {
		l = max(l, tl);
		r = min(r, tr);
		if (l > r) {
			return 0;
		}		

		if  (tl == l && tr == r) {
			return t[v];
		}

		int tm = (tl + tr) >> 1;
		int ans = gcd(get_gcd(v * 2, tl, tm, l, r), get_gcd(v * 2 + 1, tm + 1, tr, l, r));
		return ans;
	}

	int first_not(int v, int tl, int tr, int l, int r, int g) {
		l = max(l, tl);
		r = min(r, tr);
		if (l > r) {
			return -1;
		}

		if  (t[v] % g == 0) {
			return -1;
		}

		if (tl == tr) {
			assert(l == r);
			return tl;
		}

		int tm = (tl + tr) >> 1;
		int left = first_not(v * 2, tl, tm, l, r, g);
		if  (left != -1) {
			return left;
		}
		int right = first_not(v * 2 + 1, tm + 1, tr, l, r, g);
		return right;
	}

	int first_not(int l, int r, int g) {
		return first_not(1, 0, sz - 1, l, r, g);
	}

	void upd(int pos, int val) {
		int v = sz + pos;
		t[v] = val;
		v >>= 1;
		while (v) {
			t[v] = gcd(t[v * 2], t[v * 2 + 1]);
			v >>= 1;
		}
	}
};

SegmTree T;

bool good(int l, int r, int g) {
	int pos = T.first_not(l, r, g);
	// eprintf("l=%d, r=%d, g=%d --> pos=%d\n", l, r, g, pos);
	if  (pos == -1) {
		return 1;
	}
	assert(l <= pos && pos <= r);
	return T.get_gcd(pos + 1, r) % g == 0;
}

void solve() {
	T = SegmTree(n);
	forn(i, n) {
		T.upd(i, a[i]);
	}

	int q;
	scanf("%d", &q);
	forn(it, q) {
		int type;
		scanf("%d", &type);

		if  (type == 1) {
			int l, r, g;
			scanf("%d%d%d", &l, &r, &g);
			--l;
			--r;

			printf("%s\n", good(l, r, g) ? "YES" : "NO");
		} else if  (type == 2) {
			int i, y;
			scanf("%d%d", &i, &y);
			--i;
			T.upd(i, y);
		} else {
			assert(0);
		}
	}
	// printf("\n");
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
	eprintf("Time: %.10f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}