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

#define TEST 0

ll n;
int m;
ll a;
ll d;
vll t;

bool read() {
#if !TEST
	if  (scanf("%lld%d%lld%lld", &n, &m, &a, &d) < 4) {
		return 0;
	}
	t.resize(m);
	forn(i, m) {
		scanf("%lld", &t[i]);
	}
#else
	n = 1 + rand() % 100;
	m = 1 + rand() % 100;
	a = 1 + rand() % 100;
	d = 1 + rand() % 100;
	t.resize(m);
	forn(i, m) {
		t[i] = 1 + rand() % 100;
	}	
#endif
	
	sort(all(t));
	t.resize(unique(all(t)) - t.begin());
	m = sz(t);

	return 1;
}

ll cnt_div(ll l, ll r) {
	if  (l > r) {
		return 0;
	}
	assert(l >= 0);

	if  (l == 0) {
		return r / a;
	}

	return (r / a) - ((l - 1) / a);
}

ll div_after(ll T, ll a) {
	if  (T % a == 0) {
		return T + a;
	}
	T += (a - (T % a));
	assert(T % a == 0);
	return T;
}

ll solve() {
	const ll block = (d / a) + 1;

	// eprintf("block = %lld\n", block);

	ll T = 0;
	ll ans = 0;
	for (int i = 0; i < m; ) {
		assert(T <= t[i]);

		ll cnt = cnt_div(T + 1, min(t[i], n * a));

		// eprintf("cnt = %lld\n", cnt);

		ans += cnt / block;

		ll start = -1;
		if  (cnt % block == 0) {
			start = t[i];

			if  (cnt > 0) {
				ll start2 = t[i] - t[i] % a;
				start2  -= (block - 1) * a;
				if  (n * a < t[i]) {
					start2 = (n - block + 1) * a;
				}
				assert(start2 <= n * a);
				if  (start2 + d >= t[i] && start2 > 0) {
					start = start2;
				} else {
					++ans;
				}
			} else {
				++ans;
			}
		} else {
			start = t[i] - t[i] % a;
			start = min(start, n * a);
			start -= ((cnt % block) - 1) * a;

			if  (cnt > 0) {
				start = max(start, div_after(T, a));
			}

			if  (start + d >= t[i] && start > 0 && cnt > 0) {
				++ans;
			} else {
				++ans;
				++ans;
				start = t[i];
			}
		}

		// eprintf("i=%d, T=%lld, ans=%lld, start=%lld\n", i, T, ans, start);

		const ll end = start + d;
		while (i < m && t[i] <= end) {
			++i;
		}

		if  (i == m) {
			cnt = cnt_div(end + 1, n * 1ll * a);
			// eprintf("cnt in the end = [%lld, %lld] -> %lld\n", end + 1, n * 1ll * a, cnt);
			ans += (cnt + block - 1) / block;
		} else {
			T = end;
		}
	}

	return ans;
}

ll brut() {
	vll ts = t;
	for (ll i = 1; i <= n; ++i) {
		ts.pb(i * a);
	}

	sort(all(ts));
	ts.resize(unique(all(ts)) - ts.begin());

	ll ans = 0;
	for (int i = 0, j = 0; i < sz(ts); i = j) {
		while (j < sz(ts) && ts[j] - ts[i] <= d) {
			++j;
		}
		++ans;
	}
	return ans;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

#if TEST
	while (1) {
		read();

		ll my = solve();

		ll br = brut();

		if  (my != br) {
			printf("n=%lld, m=%d, a=%lld, d=%lld\n", n, m, a, d);
			forn(i, m) {
				printf("%lld ", t[i]);
			}
			printf("\n");
			printf("my=%lld, brut=%lld\n", my, br);
			return 0;
		}

		printf("OK n=%lld, m=%d, a=%lld\n", n, m, a);
	}

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