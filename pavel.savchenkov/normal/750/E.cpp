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

const int MAXN = 2e5 + 10;
const int INF = 1e9;

int n, q;
vi s;

bool read() {
	if  (scanf("%d%d\n", &n, &q) < 2) {
		return 0;
	}
	static char S[MAXN];
	scanf("%s\n", S);
	assert((int) strlen(S) == n);
	s.resize(n);
	forn(i, n) {
		s[i] = S[i] - '0';
	}
	return 1;
}

void remin(int& x, int y) {
	if  (x > y) {
		x = y;
	}
}

const vi bad = {2, 0, 1, 6};
const int N = 4;

struct Node {
	int dp[N][N];

	Node() {
		forn(i, N) forn(j, N) dp[i][j] = INF;
		forn(i, N) dp[i][i] = 0;
	}

	Node(int val) {
		forn(i, N) forn(j, N) dp[i][j] = INF;
		forn(was, N) {
			// del
			remin(dp[was][was], 1);
			
			// not del
			if  (bad[was] != val) {
				remin(dp[was][was], 0);
			} else {
				if  (was + 1 < N) {
					remin(dp[was][was + 1], 0);
				}
			}
		}

		// printf("val = %d\n", val);
		// print();
	}

	void print() const {
		forn(i, N) forn(j, N) {
			printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
		}	
	}
};

Node merge(const Node& left, const Node& right) {
	Node res;
	forn(i, N) forn(j, N) res.dp[i][j] = INF;
	forn(was, N) for (int will = was; will < N; ++will) {
		for (int mid = was; mid <= will; ++mid) {
			remin(res.dp[was][will], left.dp[was][mid] + right.dp[mid][will]);
		}
	}

	return res;
}

struct SegmTree {
	vector<Node> t;
	int sz;

	SegmTree() {}

	SegmTree(const vi& a) {
		sz = 1;
		while (sz < sz(a)) sz *= 2;

		// forn(i, sz(a)) {
		// 	printf("%d ", a[i]);
		// 	puts("");
		// }

		t.resize(sz * 2);
		for (int v = sz; v < 2 * sz; ++v) {
			if  (v - sz < sz(a)) {
				t[v] = Node(a[v - sz]);
			} else {
				t[v] = Node(3);
			}
		}
		for (int v = sz - 1; v > 0; --v) {
			t[v] = merge(t[v * 2], t[v * 2 + 1]);
		}
	}

	Node ask(int v, int tl, int tr, int l, int r) {
		l = max(l, tl);
		r = min(r, tr);

		if  (l > r) {
			return Node();
		}

		if  (l == tl && r == tr) {
			return t[v];
		}

		int tm = (tl + tr) >> 1;
		return merge(ask(v * 2, tl, tm, l, r), ask(v * 2 + 1, tm + 1, tr, l, r));
	}

	int ask(int l, int r) {
		auto res = ask(1, 0, sz - 1, l, r);
		// res.print();
		return res.dp[0][3];
	}
};

vi pos[20];
SegmTree T;

void precalc() {
	forn(i, 20) {
		pos[i].clear();
	}
	forn(i, n) {
		pos[s[i]].pb(i);
	}

	T = SegmTree(s);
}

int last_pos(int l, int r, int val) {
	int p = upper_bound(all(pos[val]), r) - pos[val].begin();
	if  (p == 0) {
		return -1;
	}
	--p;
	if  (pos[val][p] < l) {
		return -1;
	}
	return pos[val][p];
}

int get_cnt(int l, int r, int val) {
	return upper_bound(all(pos[val]), r) - lower_bound(all(pos[val]), l);
}

int solve(int l, int r) {
	int p7 = last_pos(l, r, 7);
	if  (p7 == -1) {
		return -1;
	}

	int ans = get_cnt(p7 + 1, r, 6);

	int ans2 = T.ask(l, p7 - 1);
	if (ans2 >= INF) {
		return -1;
	}
	return ans + ans2;
}

void solve() {
	precalc();

	forn(it, q) {
		int l, r;
		scanf("%d%d\n", &l, &r);
		--l;
		--r;
		printf("%d\n", solve(l, r));
	}
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	// Node v = merge(Node(2), Node(0));
	// Node u = merge(Node(1), Node(6));

	// Node vu = merge(v, u);

	// vu.print();

	// Node res = merge(vu, Node(6));

	// merge(res, Node()).print();
	// return 0;

	while (read()) {
		solve();
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}