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
const ll INF = 1e18;

struct Node {
	ll sum;
	ll max_pref;
	ll max_suff;
	ll ans;

	void norm() {
		sum = max(sum, -INF);
		max_pref = max(max_pref, 0ll);
		max_suff = max(max_suff, 0ll);
		ans = max(ans, 0ll);
	}
};

Node merge(const Node& left, const Node& right) {
	Node res;
	res.sum = left.sum + right.sum;
	res.max_pref = max(left.max_pref, left.sum + right.max_pref);
	res.max_suff = max(right.max_suff, left.max_suff + right.sum);
	res.ans = max(max(left.ans, right.ans), left.max_suff + right.max_pref);
	res.norm();
	return res;
}

struct SegmTree {
	Node t[4 * MAXN];
	int sz;

	SegmTree(int n = 0) {
		sz = 1;
		while (sz < n) sz *= 2;

		for (int v = sz; v < 2 * sz; ++v) {
			t[v] = {-INF, 0, 0, 0};
		}
		for (int v = sz - 1; v > 0; --v) {
			t[v] = merge(t[v * 2], t[v * 2 + 1]);
		}
	}

	void upd(int pos, int val) {
		int v = sz + pos;
		t[v] = Node{val, val, val, val};
		v >>= 1;
		while (v > 0) {
			t[v] = merge(t[v * 2], t[v * 2 + 1]);
			v >>= 1;
		}
	}

	Node get(int v, int tl, int tr, int l, int r) {
		l = max(l, tl);
		r = min(r, tr);

		if  (l > r) {
			return Node{-INF, 0, 0, 0};
		}

		if  (l == tl && r == tr) {
			return t[v];
		}

		int tm = (tl + tr) >> 1;
		return merge(get(v * 2, tl, tm, l, r), get(v * 2 + 1, tm + 1, tr, l, r));
	}

	ll get(int l, int r) {
		return get(1, 0, sz - 1, l, r).ans;
	}
};

int n;
int a[MAXN];
int p[MAXN];

bool read() {
	if  (scanf("%d", &n) < 1) {
		return false;
	}
	forn(i, n) {
		scanf("%d", &a[i]);
	}
	forn(i, n) {
		scanf("%d", &p[i]);
		--p[i];
	}
	return true;
}

ll ans[MAXN];

void solve() {
	SegmTree T(n);
	ford(i, n) {
		ans[i] = T.get(0, n - 1);
		T.upd(p[i], a[p[i]]);
	}
	forn(i, n) {
		printf("%lld\n", ans[i]);
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