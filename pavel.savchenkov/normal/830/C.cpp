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

#define assert(x) void(x)

int n;
ll k;
vi a;

bool read() {
#if TEST
	n = 1 + rand() % 10;
	k = 1 + rand() % 1000;
	a.resize(n);
	forn(i, n) {
		a[i] = 1 + rand() % 20;
	}
	return 1;
#else
	if  (scanf("%d%lld", &n, &k) < 2) {
		return 0;
	}
	a.resize(n);
	forn(i, n) {
		scanf("%d", &a[i]);
	}
	return 1;
#endif
}

ll get_min_d(ll x, ll val) {
	if  (val == 0) {
		return x + 1;
	}
	assert(val > 0);
	ll upper = x / val;
	ll lower = (x + val) / (val + 1);
	if  (x % (val + 1) == 0) {
		lower = x / (val + 1) + 1;
	}
	assert(lower <= upper);
	return lower;
}

vll get_ds(ll x) {
	vll res;
	res.pb(1);
	while (1) {
		ll d = res.back();
		ll val = x / d;
		// eprintf("d = %lld\n", d);
		ll next_val = min(val - 1, x / (d + 1));

		ll next_d = get_min_d(x, next_val);
		res.pb(next_d);

		if  (next_val == 0) {
			break;
		}
	}
	res.pb(ll(1e12 + 10));

	for (int d = 1; d * d <= x; ++d) {
		if  (x % d == 0) {
			res.pb(x / d);
			res.pb(x / d + 1);
			res.pb(x);
			res.pb(x + 1);
		}
	}

	return res;
}

ll solve() {
	vll ds;
	for (int x : a) {
		vll cur = get_ds(x);
		for (ll d : cur) {
			ds.pb(d);
		}
	}

	sort(all(ds));
	ds.resize(unique(all(ds)) - ds.begin());

	ll ans = 1;
	forn(i, sz(ds) - 1) {
		ll lower = ds[i];
		ll upper = ds[i + 1];

		ll coef_d = 0;
		ll coef = 0;
		for (int x : a) {
			if  (lower > x) {
				coef_d += 1;
				coef += - x;
			} else if  (x % lower != 0) {
				assert(x / lower == x / (upper - 1));
				coef_d += 1 + x / lower;
				coef -= x;
			} else {
				assert(lower == upper - 1);
			}
		}

		assert(coef_d >= 0);

		if  (coef_d == 0) {
			if  (coef <= k) {
				ans = max(ans, upper - 1);
			}
			continue;
		}

		// eprintf("check [%lld, %lld)\n", lower, upper);
		// eprintf("coef_d=%lld, coef=%lld\n", coef_d, coef);

		// d * coef_d + coef <= k
		// d <= (k - coef) / coef_d
		// k - coef > 0
		assert(k - coef > 0);
		assert(coef_d > 0);
		ll max_d = (k - coef) / coef_d;
		if  (max_d >= upper) {
			ans = max(ans, upper - 1);
		} else if  (max_d >= lower) {
			ans = max(ans, max_d);
		} else {
			// eprintf("skip\n");
		}
	}

	return ans;
}

ll brut() {
	ll ans = 1;
	for (ll d = 1; d <= 1000000; ++d) {
		ll cur = 0;
		for (int x : a) {
			if  (x % d == 0) {
				continue;
			}
			if  (d > x) {
				cur += d - x;
				continue;
			}
			cur += d - (x % d);
		}
		if  (cur <= k) {
			ans = max(ans, d);
		}
	}
	return ans;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

#if TEST
	while (read()) {
		ll my = solve();

		ll br = brut();

		if  (my != br) {
			printf("my=%lld, br=%lld\n", my, br);
			exit(0);
		} else {
			printf("OK %lld == %lld\n", my, br);
		}
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