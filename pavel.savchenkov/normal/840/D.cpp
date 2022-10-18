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

int n, q;
vi a;

bool read() {
	if  (scanf("%d%d", &n, &q) < 2) {
		return 0;
	}
	a.resize(n);
	forn(i, n) {
		scanf("%d", &a[i]);
	}
	return 1;
}

const int MAXK = 5;
const int MAXN = 3e5 + 10;

vi t[4 * MAXN];
vi p[MAXN];

struct SegmTree {
	int sz;

	SegmTree() {}

	SegmTree(const vi& a) {
		// const int mx = *max_element(all(a));
		// p.resize(mx + 1);
		forn(i, sz(a)) {
			p[a[i]].pb(i);
		}

		sz = 1;
		while (sz < sz(a)) sz *= 2;

		// t.resize(sz * 2);
		forn(i, sz(a)) {
			t[sz + i].pb(a[i]);
		}
	
		build(1, 0, sz - 1);
	}

	int cnt(int x, int l, int r) {
		return upper_bound(all(p[x]), r) - lower_bound(all(p[x]), l);
	}

	vi merge(const vi& left, const vi& right, int l, int r) {
		vi xs(sz(left) + sz(right));
		::merge(all(left), all(right), xs.begin());
		xs.resize(unique(all(xs)) - xs.begin());

		vi res;
		for (int x : xs) {
			if  (cnt(x, l, r) * MAXK > (r - l + 1)) {
				res.pb(x);
			}
		}
		return res;
	}

	void build(int v, int tl, int tr) {
		if  (tl == tr) {
			return;
		}

		int tm = (tl + tr) >> 1;
		build(v * 2, tl, tm);
		build(v * 2 + 1, tm + 1, tr);

		t[v] = merge(t[v * 2], t[v * 2 + 1], tl, tr);
	}

	void get(int v, int tl, int tr, int l, int r, vi& res) {
		l = max(l, tl);
		r = min(r, tr);

		if  (l > r) {
			return;
		}

		if  (l == tl && r == tr) {
			for (int x : t[v]) {
				res.pb(x);
			}
			return;
		}

		int tm = (tl + tr) >> 1;
		get(v * 2, tl, tm, l, r, res);
		get(v * 2 + 1, tm + 1, tr, l, r, res);
	}

	int get(int l, int r, int k) {
		vi cands;
		get(1, 0, sz - 1, l, r, cands);
		sort(all(cands));
		cands.resize(unique(all(cands)) - cands.begin());

		int ans = -1;
		for (int x : cands) {
			if  (cnt(x, l, r) * k > (r - l + 1)) {
				if  (ans == -1 || ans > x) {
					ans = x;
				}
			}
		}
		return ans;
	}
};

SegmTree T;

void prepare() {
	T = SegmTree(a);
}

void solve() {
	prepare();

	forn(it, q) {
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		--l;
		--r;
		printf("%d\n", T.get(l, r, k));
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