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

const int MAXN = 1e5 + 10;
const int INF = 1.5e9;

#define TEST 0

int n;
int a[MAXN];

bool read() {
#if TEST
	n = 1e5;
	forn(i, n) {
		a[i] = rand() % int(1e9);
	}
	return 1;
#endif

	if  (scanf("%d", &n) < 1) {
		return 0;
	}
	forn(i, n) {
		scanf("%d", &a[i]);
	}
	return 1;
}

const int K = 290;
const int B = MAXN / K + 5;

struct Block {
	vii vals;
	int l, r;

	Block() {}

	Block(int l, int r) : l(l), r(r) {
		for (int i = l; i <= r; ++i) {
			vals.pb(mp(a[i], i));
		}
		sort(all(vals));
	}

	int get_best(const Block& other) const {
		int ans = INF;

		auto upd = [&](const int& i, const int& j) {
			ans = min(ans, abs(vals[i].fst - other.vals[j].fst));
		};

		int i = 0;
		int j = 0;
		while (i < sz(vals) && j < sz(other.vals)) {
			upd(i, j);
			if (i < sz(vals) && (j == sz(other.vals) || vals[i].fst < other.vals[j].fst)) {
				++i;
			} else {
				++j;
			}
		}

		return ans;
	}

	int get_best(const Block& other, int L, int R) const {
		int ans = INF;

		auto upd = [&](const int& i, const int& j) {
			ans = min(ans, abs(vals[i].fst - other.vals[j].fst));
		};

		int i = 0;
		int j = 0;
		int pi = -1;
		int pj = -1;
		while (i < sz(vals) || j < sz(other.vals)) {
			while (i < sz(vals) && !(L <= vals[i].snd && vals[i].snd <= R)) {
				++i;
			}
			while (j < sz(other.vals) && !(L <= other.vals[j].snd && other.vals[j].snd <= R)) {
				++j;
			}
			if  (pi != -1 && pi != i && i < sz(vals)) {
				ans = min(ans, vals[i].fst - vals[pi].fst);
				// assert(ans >= 0);
			}
			pi = i;
			if  (pj != -1 && pj != j && j < sz(other.vals)) {
				ans = min(ans, other.vals[j].fst - other.vals[pj].fst);
				// printf("%d %d\n", other.vals[j].fst, other.vals[pj].fst);
				// assert(ans >= 0);
			}
			pj = j;
			if  (i < sz(vals) && j < sz(other.vals)) {
				upd(i, j);
			}
			if (i < sz(vals) && (j == sz(other.vals) || vals[i].fst < other.vals[j].fst)) {
				++i;
			} else {
				++j;
			}
		}

		return ans;
	}

	int get_ans(int L, int R) {
		int ans = INF;
		int prev = -1;
		for (const auto& val : vals) {
			int v, pos;
			tie(v, pos) = val;
			if  (L <= pos && pos <= R) {
				if  (prev != -1) {
					ans = min(ans, v - prev);
				}
				prev = v;
			}
		}
		return ans;
	}

	// --------

	int ptr;

	void prepare() {
		ptr = 0;
	}

	int get_best(int val) {
		while (ptr < sz(vals) && vals[ptr].fst < val) {
			++ptr;
		}

		int ans = INF;
		auto upd = [&](int i) {
			if  (0 <= i && i < sz(vals)) {
				ans = min(ans, abs(vals[i].fst - val));
			}
		};
		upd(ptr - 1);
		upd(ptr);
		return ans;
	}

	void print() const {
		printf("[%d, %d]\n", l, r);
		forn(i, sz(vals)) {
			printf("(%d, %d) ", vals[i].fst, vals[i].snd);
		}
		puts("");
		puts("-->");
	}
};

vector<Block> blocks;
int dp_pair[B][B];
int dp_seg[B][B];
int dp_elem[B][MAXN];
int dp_elem_right[B][MAXN];
int dp_elem_left[B][MAXN];

int id_block[MAXN];

void precalc() {
	blocks.clear();
	for (int i = 0; i < n; i += K) {
		int l = i;
		int r = min(n - 1, i + K - 1);
		for (int j = l; j <= r; ++j) {
			id_block[j] = sz(blocks);
		}
		blocks.pb(Block(l, r));
	}

	forn(i, sz(blocks)) {
		forn(j, i) {
			dp_pair[i][j] = blocks[i].get_best(blocks[j]);
		}
		dp_pair[i][i] = blocks[i].get_ans(0, n - 1);
	}


	forn(i, sz(blocks)) {
		dp_seg[i][i] = dp_pair[i][i];
	}
	for (int len = 2; len <= sz(blocks); ++len) {
		forn(i, sz(blocks) - len + 1) {
			int r = i + len - 1;
			dp_seg[i][r] = min(dp_seg[i][r - 1], min(dp_seg[i + 1][r], dp_pair[r][i]));
		}
	}

	// forn(i, sz(blocks)) {
	// 	dp_seg[i][i] = dp_pair[i][i];
	// 	for (int j = i + 1; j < sz(blocks); ++j) {
	// 		dp_seg[i][j] = dp_seg[i][j - 1];
	// 		for (int mid = i; mid <= j; ++mid) {
	// 			dp_seg[i][j] = min(dp_seg[i][j], dp_pair[j][mid]);
	// 		}
	// 	}
	// }


	vii vals;
	forn(i, n) {
		vals.pb(mp(a[i], i));
	}
	sort(all(vals));

	forn(i, sz(blocks)) {
		blocks[i].prepare();
	}
	forn(i, sz(vals)) {
		int val = vals[i].fst;
		int pos = vals[i].snd;
		forn(j, sz(blocks)) {
			dp_elem[j][pos] = blocks[j].get_best(val);
		}
	}


	// elem right
	forn(i, n) {
		int j = 0;
		while (j < sz(blocks) && blocks[j].l <= i) {
			++j;
		}
		if  (j == sz(blocks)) {
			break;
		}
		dp_elem_right[j][i] = dp_elem[j][i];
		for (++j; j < sz(blocks); ++j) {
			dp_elem_right[j][i] = min(dp_elem[j][i], dp_elem_right[j - 1][i]);
		}
	}

	// elem left
	forn(i, n) {
		int j = 0;
		while (j < sz(blocks) && blocks[j].l <= i) {
			++j;
		}
		j -= 2;
		if  (j < 0) {
			continue;
		}
		dp_elem_left[j][i] = dp_elem[j][i];
		for (--j; j >= 0; --j) {
			dp_elem_left[j][i] = min(dp_elem[j][i], dp_elem_left[j + 1][i]);
		}
	}

	// forn(i, sz(blocks)) {
	// 	blocks[i].print();
	// }

	// forn(i, sz(blocks)) {
	// 	forn(j, i + 1) {
	// 		printf("dp_pair[%d][%d] = %d\n", i, j, dp_pair[i][j]);
	// 	} 
	// }

	// forn(i, sz(blocks)) {
	// 	for (int j = i; j < sz(blocks); ++j) {
	// 		printf("dp_seg[%d][%d] = %d\n", i, j, dp_seg[i][j]);
	// 	} 
	// }
}

int get_pref_suff(int l, int r) {
	int i1 = id_block[l];
	int i2 = id_block[r];
	assert(i1 < i2);

	// int ans = min(blocks[i1].get_ans(l, r), blocks[i2].get_ans(l, r));
	int ans = blocks[i1].get_best(blocks[i2], l, r);

	return ans;
}

int solve(int l, int r) {
	if  (id_block[l] == id_block[r]) {
		return blocks[id_block[l]].get_ans(l, r);
	}

	int j1 = 0;
	while (j1 < sz(blocks) && blocks[j1].l <= l) {
		++j1;
	}

	assert(j1 < sz(blocks));

	int j2 = 0;
	while (j2 < sz(blocks) && blocks[j2].r < r) {
		++j2;
	}
	--j2;

	// printf("l=%d, r=%d, j1=%d, j2=%d\n", l, r, j1, j2);

	if  (j1 > j2) {
		return get_pref_suff(l, r);
	}

	int ans = dp_seg[j1][j2];
	for (int i = l; i < blocks[j1].l; ++i) {
		ans = min(ans, dp_elem_right[j2][i]);
	}
	for (int i = blocks[j2].r + 1; i <= r; ++i) {
		ans = min(ans, dp_elem_left[j1][i]);
	}

	return min(ans, get_pref_suff(l, r));
}

int brut(int l, int r) {
	int ans = INF;
	for (int i = l; i <= r; ++i) {
		for (int j = i + 1; j <= r; ++j) {
			ans = min(ans, abs(a[i] - a[j]));
		}
	}
	return ans;
}

void solve() {
#if TEST
	double st = clock() * 1.0 / CLOCKS_PER_SEC;
#endif

	precalc();

#if TEST
	printf("precalc: %.10f\n", clock() * 1.0 / CLOCKS_PER_SEC - st);
#endif

#if TEST
	int m = 3e5;
	forn(it, m) {
		int l = rand() % n;
		int r = rand() % n;
		if  (l > r) {
			swap(l, r);
		}
		int ans = solve(l, r);
		// int br = brut(l, r);

		// if  (ans != br) {
		// 	printf("ans=%d, br=%d, l=%d, r=%d\n", ans, br, l, r);
		// 	exit(0);
		// } else {
		// 	printf("OK %d == %d\n", ans, br);
		// }

		if (it % 10000 == 0) {
			printf("it = %d\n", it);
		}
	}
	return;
#else
	int m;
	scanf("%d", &m);
	forn(i, m) {
		int l, r;
		scanf("%d%d", &l, &r);
		--l;
		--r;
		printf("%d\n", solve(l, r));
	}
#endif
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		solve();

		break;
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}