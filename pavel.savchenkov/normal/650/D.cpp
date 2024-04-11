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

const int MAXN = 4e5 + 10;

struct SegmTree {
	vi t;
	int sz;

	SegmTree(int n = 0) {
		sz = 1;
		while (sz < n) sz *= 2;
		t.assign(sz * 2, 0);
	}

	void put(int pos, int val) {
		int v = sz + pos;
		t[v] = max(t[v], val);
		v >>= 1;
		while (v) {
			t[v] = max(t[v * 2], t[v * 2 + 1]);
			v >>= 1;
		}
	}

	int get_max(int l, int r) {
		int res = 0;
		l += sz;
		r += sz;
		while (l <= r) {
			if  (l & 1) {
				res = max(res, t[l]);
				++l;
			}
			if  (~r & 1) {
				res = max(res, t[r]);
				--r;
			}
			l >>= 1;
			r >>= 1;
		}
		return res;
	}
};

int h[MAXN];
int a[MAXN];
int b[MAXN];
int n, m;
vi c;
vi who[MAXN];

bool read() {
	if  (scanf("%d%d", &n, &m) < 2) {
		return false;
	}
	forn(i, n) {
		scanf("%d", &h[i]);
	}
	forn(i, m) {
		scanf("%d%d", &a[i], &b[i]);
		--a[i];
	}
	return true;
}

int with[MAXN];
int without[MAXN];

int code(int v) {
	return lower_bound(all(c), v) - c.begin();
}

void precalc_with() {
	// forward
	SegmTree T(sz(c));
	forn(i, n) {
		for (int id : who[i]) {
			int mx = T.get_max(0, code(b[id]) - 1);
			with[id] = 1 + mx;
		}
		int pos = code(h[i]);
		int mx = T.get_max(0, pos - 1);
		T.put(pos, mx + 1);
	}

	// backward
	T = SegmTree(sz(c));
	ford(i, n) {
		for (int id : who[i]) {
			int mx = T.get_max(code(b[id]) + 1, sz(c) - 1);
			with[id] += mx;
		}
		int pos = code(h[i]);
		int mx = T.get_max(pos + 1, sz(c) - 1);
		T.put(pos, mx + 1);
	}
}

void precalc_without() {
	forn(i, m) {
		without[i] = 0;
	}

	// left ans
	vi left_ans(n, 0);
	SegmTree T(sz(c));
	forn(i, n) {
		for (int id : who[i]) {
			without[id] = max(without[id], T.get_max(0, sz(c) - 1));
		}
		int pos = code(h[i]);
		left_ans[i] = T.get_max(0, pos - 1) + 1;
		T.put(pos, left_ans[i]);
	}

	// right ans
	vi right_ans(n, 0);
	T = SegmTree(sz(c));
	ford(i, n) {
		for (int id : who[i]) {
			without[id] = max(without[id], T.get_max(0, sz(c) - 1));
		}
		int pos = code(h[i]);
		right_ans[i] = T.get_max(pos + 1, sz(c) - 1) + 1;
		T.put(pos, right_ans[i]);
	}

	vi ans(n, 0);
	forn(i, n) {
		ans[i] = left_ans[i] + right_ans[i] - 1;
		for (int id : who[i]) {
			without[id] = max(without[id], ans[i] - 1);
		}
	}

	// printf("ans\n");
	// forn(i, n) {
	// 	printf("%d ", ans[i]);
	// }
	// puts("");

	// printf("before forward\n");
	// forn(i, m) {
	// 	printf("%d %d\n", with[i], without[i]);
	// } 

	// forward
	T = SegmTree(sz(c));
	forn(i, n) {
		int pos = code(h[i]);
		for (int id : who[i]) {
			without[id] = max(without[id], T.get_max(pos, sz(c) - 1));
		}
		T.put(pos, ans[i]);
	}

	// backward
	T = SegmTree(sz(c));
	ford(i, n) {
		int pos = code(h[i]);
		for (int id : who[i]) {
			without[id] = max(without[id], T.get_max(0, pos));
		}
		T.put(pos, ans[i]);
	}
}

int lis() {
	vi dp(n, 1);
	forn(i, n) {
		forn(j, i) {
			if  (h[j] < h[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	return *max_element(all(dp));
}

int brut(int i, int nval) {
	int old = h[i];
	h[i] = nval;
	int res = lis();
	h[i] = old;
	return res;
}

void solve() {
	c.clear();
	forn(i, n) {
		c.pb(h[i]);
	}
	forn(i, m) {
		c.pb(b[i]);
	}
	sort(all(c));
	c.resize(unique(all(c)) - c.begin());

	forn(i, n) {
		who[i].clear();
	}
	forn(i, m) {
		who[a[i]].pb(i);
	}

	precalc_with();
	precalc_without();

	// printf("with, without\n");
	// forn(i, m) {
	// 	printf("%d %d\n", with[i], without[i]);
	// }

	// forn(i, m) {
	// 	int my = max(with[i], without[i]);
	// 	int corr = brut(a[i], b[i]);
	// 	if  (my != corr) {
	// 		printf("n = %d\n", n);
	// 		forn(i, n) {
	// 			printf("%d ", h[i]);
	// 		}
	// 		puts("");
	// 		printf("pos=%d, nval=%d, my=%d, corr=%d\n", a[i], b[i], my, corr);
	// 		exit(0);
	// 	}
	// }

	forn(i, m) {
		printf("%d\n", max(with[i], without[i]));
	}
}

int main() {
#ifdef DEBUG
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	// while (1) {
	// 	n = rand() % 5 + 1;
	// 	forn(i, n) h[i] = rand() % 10;
	// 	m = rand() % 5 + 1;
	// 	forn(i, m) {
	// 		a[i] = rand() % n;
	// 		b[i] = rand() % 10;
	// 	}
	// 	solve();
	// }

	while (read()) {
		solve();
	}

	return 0;
}