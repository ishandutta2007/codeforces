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
vll p;
vector<char> color;

bool read() {
	if  (scanf("%d", &n) < 1) {
		return 0;
	}
	p.resize(n);
	color.resize(n);
	forn(i, n) {
		scanf("%lld %c\n", &p[i], &color[i]);
	}
	return 1;
}

const ll INF = 2e9;

ll solveSeg(const ll l, const ll r, const vll& red, const vll& blue) {
	if  (l <= -INF && r >= INF) {
		ll ans = 0;
		if  (!red.empty()) {
			ans += red.back() - red.front();
		}
		if  (!blue.empty()) {
			ans += blue.back() - blue.front();
		}
		return ans;
	}

	if  (l <= -INF) {
		ll ans = 0;
		if  (!red.empty()) {
			ans += r - red.front();
		}
		if  (!blue.empty()) {
			ans += r - blue.front();
		}
		return ans;
	}

	if  (r >= INF) {
		ll ans = 0;
		if  (!red.empty()) {
			ans += red.back() - l;
		}
		if  (!blue.empty()) {
			ans += blue.back() - l;
		}
		return ans;
	}

	ll ans_full = r - l;
	if  (sz(red) == 1) {
		ans_full += min(red[0] - l, r - red[0]);
	} else if  (sz(red) > 1) {
		ll mx = 0;
		forn(i, sz(red) - 1) {
			mx = max(mx, red[i + 1] - red[i]);
		}
		mx = max(mx, red[0] - l);
		mx = max(mx, r - red.back());
		ans_full += r - l - mx;
	}
	if  (sz(blue) == 1) {
		ans_full += min(blue[0] - l, r - blue[0]);
	} else if  (sz(blue) > 1) {
		ll mx = 0;
		forn(i, sz(blue) - 1) {
			mx = max(mx, blue[i + 1] - blue[i]);
		}
		mx = max(mx, blue[0] - l);
		mx = max(mx, r - blue.back());
		ans_full += r - l - mx;
	}

	if  (red.empty() || blue.empty()) {
		return ans_full;
	}

	return min(ans_full, 2 * (r - l));
}

ll solve() {
	ll ans = 0;

	vll red;
	vll blue;
	int prev = -1;
	forn(i, n) {
		if  (color[i] == 'G') {
			const ll l = prev == -1 ? -INF : p[prev];
			const ll r = p[i];
			ans += solveSeg(l, r, red, blue);
			red.clear();
			blue.clear();
			prev = i;
		} else {
			if  (color[i] == 'B') {
				blue.pb(p[i]);
			} else {
				assert(color[i] == 'R');
				red.pb(p[i]);
			}
		}
	}

	if  (!red.empty() || !blue.empty()) {
		const ll l = prev == -1 ? -INF : p[prev];
		const ll r = INF;
		ans += solveSeg(l, r, red, blue);
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
	eprintf("Time: %.10f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}