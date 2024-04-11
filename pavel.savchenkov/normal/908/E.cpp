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

const int MAXM = 1e3 + 10;
const int MOD = 1e9 + 7;

void add(int& x, int y) {
	((x += y) >= MOD) && (x -= MOD);
}

int mul(int x, int y) {
	return x * 1ll * y % MOD;
}

bitset<MAXM> readBitset() {
	string s;
	getline(cin, s);
	bitset<MAXM> b;
	forn(i, sz(s)) {
		if  (s[i] == '1') {
			b.set(i);
		}
	}
	return b;
}

int m, n;
vector<bitset<MAXM>> a;

bool read() {
	if  (scanf("%d%d\n", &m, &n) < 2) {
		return 0;
	}
	a.resize(n);
	forn(i, n) {
		a[i] = readBitset();
	}
	return 1;
}

struct DSU {
	vi par;

	DSU(int n = 0) {
		par.assign(n, -1);
	}

	int get(int x) {
		return par[x] < 0 ? x : par[x] = get(par[x]);
	}

	bool unite(int x, int y) {
		x = get(x);
		y = get(y);
		if  (x == y) {
			return 0;
		}
		if  (-par[x] < -par[y]) {
			swap(x, y);
		}
		par[x] += par[y];
		par[y] = x;
		return 1;
	}
};

int solve() {
	DSU dsu(m);
	forn(i, m) {
		bitset<MAXM> and_with;
		forn(j, m) {
			and_with.set(j);
		} 
		for (const auto& b : a) {
			if  (b[i]) {
				and_with &= b;
			} else {
				and_with &= ~b;
			}
		}

		assert(and_with[i]);
		forn(j, m) {
			if  (and_with[j]) {
				dsu.unite(i, j);
			}
		}
	}

	vi sizes;
	forn(i, m) {
		if  (dsu.get(i) == i) {
			sizes.pb(-dsu.par[i]);
		}
	}
	sort(all(sizes));
	assert(accumulate(all(sizes), 0) == m);

	eprintf("sizes:\n");
	forn(i, sz(sizes)) {
		eprintf("%d ", sizes[i]);
	}
	eprintf("\n");

	vi color(m + 1, -1);
	int ptr = 0;
	forn(i, sz(sizes)) {
		for (int j = ptr; j < ptr + sizes[i]; ++j) {
			color[j] = i;
		}
		ptr += sizes[i];
	}
	assert(ptr == m);

	static int dp[MAXM][MAXM];
	memset (dp, 0, sizeof dp);
	dp[0][0] = 1;
	forn(i, m) {
		forn(cnt, m + 1) {
			const int cur_dp = dp[i][cnt];
			if  (!cur_dp) {
				continue;
			}

			const bool same = color[i] == color[i + 1];

			// make new set
			add(dp[i + 1][same ? (cnt + 1) : 0], cur_dp);

			// attach to old set
			add(dp[i + 1][same ? cnt : 0], mul(cur_dp, cnt));
		}
	}

	return dp[m][0];
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
	eprintf("Time: %.10f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}