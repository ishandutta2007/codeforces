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

int n, m, r, k;

bool read() {
	if  (scanf("%d%d%d%d", &n, &m, &r, &k) < 4) {
		return 0;
	}
	return 1;
}

ld solve() {
	vi f;
	for (int i = 1; i <= n; ++i) {
		const int l = max(1, i - r + 1);
		const int R = min(i, n - r + 1);
		f.pb(max(0, R - l + 1));
	}

	vi g;
	for (int j = 1; j <= m; ++j) {
		const int l = max(1, j - r + 1);
		const int R = min(j, m - r + 1);
		g.pb(max(0, R - l + 1));
	}

	sort(all(f));
	sort(all(g));

	auto Item = [&](int i, int j) -> pair<ll, pii> {
		return mp(f[i] * 1ll * g[j], mp(i, j));
	};

	// eprintf("f:\n");
	// forn(i, sz(f)) {
	// 	eprintf("%d ", f[i]);
	// }
	// eprintf("\n");
	// eprintf("g:\n");
	// forn(i, sz(g)) {
	// 	eprintf("%d ", g[i]);
	// }
	// eprintf("\n");

	set<pii> was;
	vll ans;
	set<pair<ll, pii>> S;
	S.insert(Item(sz(f) - 1, sz(g) - 1));
	was.insert(mp(sz(f) - 1, sz(g) - 1));
	while (sz(ans) < k) {
		assert(!S.empty());

		const pii mx_pos = S.rbegin()->snd;
		int i, j;
		tie(i, j) = mx_pos;
		S.erase(*S.rbegin());

		assert(was.count(mp(i, j)));
		ans.pb(Item(i, j).fst);

		if  (i - 1 >= 0 && !was.count(mp(i - 1, j))) {
			was.insert(mp(i - 1, j));
			S.insert(Item(i - 1, j));
		}

		if  (j - 1 >= 0 && !was.count(mp(i, j - 1))) {
			was.insert(mp(i, j - 1));
			S.insert(Item(i, j - 1));
		}
	}

	ld result = 0;
	const ll whole = (n - r + 1) * 1ll * (m - r + 1);
	for (const auto& cnt : ans) {
		// eprintf("cnt = %lld, whole = %lld\n", cnt, whole);
		ld cur = ld(cnt) / whole;
		result += cur;
	}

	return result;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		printf("%.10f\n", (double) solve());
	}

#ifdef LOCAL
	eprintf("Time: %.10f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}