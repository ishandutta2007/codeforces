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
	vi c;
	for (int x : a) {
		c.pb(x);
	}
	sort(all(c));
	c.resize(unique(all(c)) - c.begin());
	for (int& x : a) {
		x = lower_bound(all(c), x) - c.begin();
	}
	return 1;
}

struct FenwTree {
	vi t;

	FenwTree(int n = 0) {
		t.assign(n, 0);
	}

	int get(int r) {
		int s = 0;
		for (int i = r; i >= 0; i &= i + 1, --i) {
			s += t[i];
		}
		return s;
	}

	int get(int l, int r) {
		return get(r) - get(l - 1);
	}

	void inc(int pos, int val) {
		for (int i = pos; i < sz(t); i |= i + 1) {
			t[i] += val;
		}
	}
};

const int MOD = 1e9 + 7;

void add(int& x, int y) {
	((x += y) >= MOD) && (x -= MOD);
}

int mul(int x, int y) {
	return x * 1ll * y % MOD;
}

struct Node {
	int dp[4][4];

	Node() {
		clear();
		forn(i, 4) {
			dp[i][i] = 1;
		}
	}

	Node(int left, int right) {
		clear();
		forn(i, 4) {
			dp[i][i] = 1;
		}
		dp[0][1] = left;
		dp[1][2] = 1;
		dp[2][3] = right;
	}

	void clear() {
		memset (dp, 0, sizeof dp);
	}

	void print() const {
		forn(l, 4) for (int r = l; r < 4; ++r) {
			if  (dp[l][r]) {
				printf("[%d, %d) -> %d\n", l, r, dp[l][r]);
			}
		}
		puts("-->");
	}
};

Node merge(const Node& left, const Node& right) {
	Node res;
	res.clear();

	forn(l, 4) for (int r = l; r < 4; ++r) {
		for (int m = l; m <= r; ++m) {
			add(res.dp[l][r], mul(left.dp[l][m], right.dp[m][r]));
		}
	}

	// left.print();
	// right.print();
	// res.print();
	// puts("");

	return res;
}

struct SegmTree {
	vector<Node> t;
	vi left;
	vi right;
	int sz;

	SegmTree() {}

	SegmTree(const vi& left, const vi& right) : left(left), right(right) {
		sz = 1;
		while (sz < sz(left)) sz *= 2;

		t.resize(sz * 2);
		forn(it, sz(left)) {
			change(it, 1);
		}
	}

	void upd(int v) {
		t[v] = merge(t[v * 2], t[v * 2 + 1]);
	}

	void change(int v, int tl, int tr, int pos, int new_state) {
		if  (tl == tr) {
			if  (new_state) {
				t[v] = Node(left[tl], right[tl]);
			} else {
				t[v] = Node();
			}
			return;
		}

		int tm = (tl + tr) >> 1;
		if  (pos <= tm) {
			change(v * 2, tl, tm, pos, new_state);
		} else {
			change(v * 2 + 1, tm + 1, tr, pos, new_state);
		}
		upd(v);
	}

	void change(int pos, int new_state) {
		change(1, 0, sz - 1, pos, new_state);
	}

	int get() {
		return t[1].dp[0][3];
	}
};

vector<SegmTree> trees;
vvi poses;

void prepare() {
	poses.clear();
	poses.resize(n);
	forn(i, n) {
		poses[a[i]].pb(i);
	}

	vi left(n);
	FenwTree T(n);
	forn(i, n) {
		left[i] = T.get(a[i]);
		T.inc(a[i], +1);
	}

	vi right(n);
	T = FenwTree(n);
	ford(i, n) {
		right[i] = T.get(a[i]);
		T.inc(a[i], +1);
	}

	trees.resize(n);
	forn(val, n) {
		vi Left;
		vi Right;
		for (int pos : poses[val]) {
			Left.pb(left[pos]);
			Right.pb(right[pos]);
		}

		// printf("val=%d\n", val);
		// for (int x : Left) {
		// 	printf("%d ", x);
		// }
		// puts("");
		// for (int x : Right) {
		// 	printf("%d ", x);
		// }
		// puts("");
		trees[val] = SegmTree(Left, Right);
	}
}

void solve() {
	prepare();

	int ans = 0;
	forn(val, n) {
		add(ans, trees[val].get());
	}

	int m;
	scanf("%d", &m);
	forn(it, m) {
		int t, x;
		scanf("%d%d", &t, &x);
		--x;
		--t;
		int val = a[x];
		int pos = lower_bound(all(poses[val]), x) - poses[val].begin();

		add(ans, -trees[val].get() + MOD);
		trees[val].change(pos, t);
		add(ans, trees[val].get());

		printf("%d\n", ans);
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