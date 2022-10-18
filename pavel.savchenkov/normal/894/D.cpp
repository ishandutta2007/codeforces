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

int n, m;
vi len;

bool read() {
	if  (scanf("%d%d", &n, &m) < 2) {
		return 0;
	}
	len.resize(n + 1);
	for (int i = 2; i <= n; ++i) {
		scanf("%d", &len[i]);
	}
	return 1;
}

vvi lens;
vector<vll> sums;

void dfs(int v, vi& cur_lens, int cur_len) {
	if  (v > n) {
		return;
	}
	cur_lens.pb(cur_len);
	for (int to = v * 2; to <= v * 2 + 1; ++to) {
		if  (to > n) {
			continue;
		}
		dfs(to, cur_lens, cur_len + len[to]);
	}
}

void precalc() {
	lens.clear();
	lens.resize(n + 1);
	sums.clear();
	sums.resize(n + 1);
	for (int v = 1; v <= n; ++v) {
		vi cur_lens;
		dfs(v, cur_lens, 0);
		lens[v] = cur_lens;
		sort(all(lens[v]));
		sums[v].assign(sz(lens[v]) + 1, 0);
		forn(i, sz(lens[v])) {
			sums[v][i + 1] = sums[v][i] + lens[v][i];
		}
	}
}

ll get(int v, int h) {
	ll ans = 0;
	int prev = -1;
	while (v) {
		eprintf("v = %d, h = %d, len = %d, ans = %lld\n", v, h, len[v], ans);

		for (int to = v * 2; to <= v * 2 + 1; ++to) {
			if  (to == prev || to > n) {
				continue;
			}
			const int need = h - len[to];
			const int pos = (upper_bound(all(lens[to]), need) - lens[to].begin()) - 1;

			const int cnt = pos + 1;
			if  (cnt) {
				eprintf("sums = %lld, cnt = %d\n", sums[to][pos + 1], cnt);
				ans += need * 1ll * cnt - sums[to][pos + 1];
			}
		}

		if  (0 <= h) {
			ans += h;
		}

		h -= len[v];
		prev = v;
		v /= 2;
	}

	return ans;
}

void solve() {
	precalc();

	forn(it, m) {
		int a, h;
		scanf("%d%d", &a, &h);
		printf("%lld\n", get(a, h));
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