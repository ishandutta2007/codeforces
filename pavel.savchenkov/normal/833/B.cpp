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


int n, k;
vi a;

bool read() {
	if  (scanf("%d%d", &n, &k) < 2) {
		return 0;
	}
	a.resize(n);
	forn(i, n) {
		scanf("%d", &a[i]);
		--a[i];
	}
	return 1;
}

const int INF = 1e9;

struct SegmTree {
	vi add;
	vi mx;
	int sz;

	SegmTree(int n = 0) {
		sz = 1;
		while (sz < n) sz *= 2;

		add.assign(sz * 2, 0);
		mx.assign(sz * 2, 0);
	}

	void push(int v) {
		add[v * 2] += add[v];
		add[v * 2 + 1] += add[v];
		mx[v * 2] += add[v];
		mx[v * 2 + 1] += add[v];
		add[v] = 0;
	}

	void recalc(int v) {
		assert(!add[v]);
		mx[v] = max(mx[v * 2], mx[v * 2 + 1]);
	}

	void go_add(int v, int tl, int tr, int l, int r, int val) {
		l = max(l, tl);
		r = min(r, tr);
		if  (l > r) {
			return;
		}

		if  (l == tl && r == tr) {
			add[v] += val;
			mx[v] += val;
			return;
		}

		push(v);

		int tm = (tl + tr) >> 1;
		go_add(v * 2, tl, tm, l, r, val);
		go_add(v * 2 + 1, tm + 1, tr, l, r, val);

		recalc(v);
	}

	void go_add(int l, int r, int val) {
		go_add(1, 0, sz - 1, l, r, val);
	}

	int get_max(int v, int tl, int tr, int l, int r) {
		l = max(l, tl);
		r = min(r, tr);

		if  (l > r) {
			return -INF;
		}

		if  (l == tl && r == tr) {
			return mx[v];
		}

		push(v);

		int tm = (tl + tr) >> 1;
		int res = max(get_max(v * 2, tl, tm, l, r), get_max(v * 2 + 1, tm + 1, tr, l, r));

		recalc(v);

		return res;
	}

	int get_max(int l, int r) {
		return get_max(1, 0, sz - 1, l, r);
	}
};

vi recalc(const vi& dp) {
	vi ans(n + 1, -INF);
	ans[0] = 0;

	SegmTree T(n + 1);
	T.go_add(0, 0, dp[0]);
	vi last(n, -1);

	forn(i, n) {
		int prev = last[a[i]];
		T.go_add(prev + 1, i, +1);
		ans[i + 1] = T.get_max(0, i);
		T.go_add(i + 1, i + 1, dp[i + 1]);
		last[a[i]] = i;
	}

	return ans;
}

int solve() {
	vi dp(n + 1, -INF);
	dp[0] = 0;
	forn(it, k) {
		dp = recalc(dp);
	}
	return dp[n];
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