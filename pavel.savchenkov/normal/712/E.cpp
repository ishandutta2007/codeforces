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
typedef vector<vector <int> > vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

#define FILE_NAME "a"

const int MAXN = 1e5 + 10;

struct Seg {
	ld a, b;

	Seg() : a(0), b(0) {}

	Seg(ld p) {
		a = b = 1 - p;
	}
};

Seg merge(Seg left, Seg right) {
	Seg res;
	ld a = left.a;
	ld b = left.b;
	ld c = right.a;
	ld d = right.b;
	res.a = 1 - (1 - a) * (1 - c) * (1.0 / (1.0 - c * (1 - b)));
	res.b = (d) * (b) * (1.0 / (1.0 - (1 - b) * c));
	return res;
}

struct SegmTree {
	vector<Seg> t;
	int sz;

	SegmTree(int n = 0) {
		sz = 1;
		while (sz < n) sz *= 2;
		t.resize(sz * 2);
	}

	void put(int pos, ld p) {
		int v = sz + pos;
		t[v] = Seg(p);
		v >>= 1;
		while (v) {
			t[v] = merge(t[v * 2], t[v * 2 + 1]);
			v >>= 1;
		}
	}

	Seg get(int v, int tl, int tr, int l, int r) {
		l = max(l, tl);
		r = min(r, tr);
		assert(l <= r);

		if  (l == tl && r == tr) {
			return t[v];
		}

		int tm = (tl + tr) >> 1;
		if  (r <= tm) {
			return get(v * 2, tl, tm, l, r);
		} else if  (tm < l) {
			return get(v * 2 + 1, tm + 1, tr, l, r);
		} else {
			return merge(get(v * 2, tl, tm, l, r), get(v * 2 + 1, tm + 1, tr, l, r));
		}
	}

	ld get(int l, int r) {
		auto res = get(1, 0, sz - 1, l, r);
		return 1 - res.a;
	}
};

int a[MAXN];
int b[MAXN];
int n, q;

bool read() {
	if  (scanf("%d%d", &n, &q) < 2) {
		return false;
	}
	forn(i, n) {
		scanf("%d%d", &a[i], &b[i]);
	}
	return true;
}

void solve() {
	SegmTree T(n);
	forn(i, n) {
		T.put(i, (ld) a[i] / b[i]);
	}

	forn(it, q) {
		int t;
		scanf("%d", &t);
		if  (t == 1) {
			int i, aa, bb;
			scanf("%d%d%d", &i, &aa, &bb);
			--i;
			T.put(i, (ld) aa / bb);
		} else {
			assert(t == 2);
			int l, r;
			scanf("%d%d", &l, &r);
			--l;
			--r;
			printf("%.10f\n", (double) T.get(l, r));
		}
	}
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	freopen(FILE_NAME ".out", "w", stdout);
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