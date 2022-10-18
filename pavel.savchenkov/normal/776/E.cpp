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

const int MOD = 1e9 + 7;

ll n, k;

bool read() {
	if  (scanf("%lld%lld", &n, &k) < 2) {
		return 0;
	}
	return 1;
}

ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
} 

vll get_divs(ll n) {
	vll res;
	for (ll x = 1; x * x <= n; ++x) {
		if  (n % x == 0) {
			res.pb(x);
			if  (x * x < n) {
				res.pb(n / x);
			}
		}
	}
	return res;
}

map<ll, ll> F;
ll f(ll n) {
	if  (n == 1) {
		return 1;
	}

	if  (F.count(n)) {
		return F[n];
	}

	// ll ans = 0;
	// for (ll x = 1; x < n; ++x) {
	// 	ll y = n - x;
	// 	if  (gcd(x, y) == 1) {
	// 		++ans;
	// 	}
	// }

	ll ans = n - 1;
	vll divs = get_divs(n);
	for (ll d : divs) {
		if  (1 < d && d < n) {
			ans -= f(d);
		}
	}

	// printf("f[%lld] = %lld\n", n, ans);
	// static int it = 0;
	// cout << ++it << endl;
	return (F[n] = ans);
}

map<ll, ll> G;
ll g(ll n) {
	if  (G.count(n)) {
		return G[n];
	}

	ll ans = 0;
	for (ll d = 1; d <= n; ++d) {
		if  (n % d == 0) {
			ans += f(n / d);
		}
	}

	return (G[n] = ans);
}

void solve() {
	// for (ll n = 1; n <= 20; ++n) {
	// 	cout << "g[" << n << "] = " << g(n) << endl;
	// }

	ll cnt = (k + 1) / 2;

	// printf("k=%lld, cnt=%lld\n", k, cnt);

	ll ans = n;
	while (ans > 1 && cnt > 0) {
		--cnt;
		ans = f(ans);
		// printf("get\n");
	}
	printf("%d\n", int(ans % MOD));
	return;

	for (ll n = 1; n <= 100; ++n) {
		printf("n = %lld\n", n);
		printf("f=%lld, ff=%lld, fff=%lld\n\n", f(n), f(f(n)), f(f(f(n))));
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