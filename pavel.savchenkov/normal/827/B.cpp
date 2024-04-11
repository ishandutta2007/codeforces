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

bool read() {
	if  (scanf("%d%d", &n, &k) < 2) {
		return 0;
	}
	return 1;
}



void solve() {
	vii es;
	vi depth(n, 0);
	vi last(k);
	forn(i, k) {
		last[i] = i;
	}
	int ptr = 0;
	for (int v = k; v < n - 1; ++v) {
		es.pb(mp(last[ptr], v));
		depth[v] = depth[last[ptr]] + 1;
		last[ptr] = v;
		ptr = (ptr + 1) % k;
	}
	forn(i, k) {
		es.pb(mp(n - 1, last[i]));
	}

	int mx1 = 0;
	int mx2 = 0;
	forn(i, k) {
		int cur = depth[last[i]];
		if  (cur > mx1) {
			mx2 = mx1;
			mx1 = cur;
		} else if  (cur > mx2) {
			mx2 = cur;
		}
	}

	// eprintf("mx1=%d, mx2=%d\n", mx1, mx2);
	int ans = mx1 + mx2 + 2;
	printf("%d\n", ans);
	for (const auto& e : es) {
		int v, u;
		tie(v, u) = e;
		printf("%d %d\n", v + 1, u + 1);
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