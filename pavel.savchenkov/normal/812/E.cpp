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


int n;
vi a;
vvi g;

bool read() {
	if  (scanf("%d", &n) < 1) {
		return 0;
	}
	a.resize(n);
	forn(i, n) {
		scanf("%d", &a[i]);
	}
	g.clear();
	g.resize(n);
	for (int i = 1; i < n; ++i) {
		int p;
		scanf("%d", &p);
		--p;
		g[p].pb(i);
	}
	return 1;
}

int dfs(int v, vvi& vals) {
	if  (g[v].empty()) {
		vals.at(0).pb(a[v]);
		return 0;
	}

	int depth = -1;
	for (int to : g[v]) {
		int depth_to = dfs(to, vals);
		if  (depth == -1) {
			depth = depth_to ^ 1;
		} else {
			assert(depth == (depth_to ^ 1));
		}
	}
	assert(depth != -1);

	vals.at(depth).pb(a[v]);

	return depth;
}

ll solve() {
	vvi vals(2);
	dfs(0, vals);

	forn(c, 2) {
		sort(all(vals[c]));
	}

	int xor0 = 0;
	for (int x : vals[0]) {
		xor0 ^= x;
	}

	ll ans = 0;
	if  (xor0 == 0) {
		forn(c, 2) {
			const ll cnt = sz(vals[c]);
			ans += cnt * (cnt - 1) / 2;
		}
	}

	{
		for (int x : vals[0]) {
			const int need = xor0 ^ x;
			int l = lower_bound(all(vals[1]), need) - vals[1].begin();
			int r = upper_bound(all(vals[1]), need) - vals[1].begin();
			ans += r - l;
		}
	}

	return ans;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		printf("%lld\n", solve());
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}