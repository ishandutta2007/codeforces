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

using namespace std;

#define pb push_back
#define fst first
#define snd second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define next jskdfksdhfjkdsjksdjkgf
#define prev koeuigrihjdkjdfj
#define hash kjfdkljkdhgjdkfhgurehg
#define all(C) begin(C), end(C)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector <int> > vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

#define FILE_NAME "a"

const int MAXV = 1e5 + 10;
const int MAXN = 1e6 + 10;

int gcd(int a, int b) {
	return b ? gcd(a % b, b) : a;
} 

bool pr[MAXV];
vi primes;

void precalc() {
	memset (pr, true, sizeof pr);
	for (int i = 2; i < MAXV; ++i) {
		if  (pr[i]) {
			primes.pb(i);
			for (int j = i + i; j < MAXV; j += i) {
				pr[j] = false;
			}
		}
	}
}

int a[MAXN];
int n, A, b;

bool read() {
	if  (scanf("%d%d%d", &n, &A, &b) < 3) {
		return false;
	}
	forn(i, n) {
		scanf("%d", &a[i]);
	}
	return true;
}

vi gen_primes(int x) {
	vi res;
	for (int i = 0; i < sz(primes) && primes[i] * primes[i] <= x; ++i) {
		int p = primes[i];
		if  (x % p == 0) {
			res.pb(p);
			x /= p;
			while (x % p == 0) {
				x /= p;
			}
		}
	}
	if  (x > 1) {
		res.pb(x);
	}
	return res;
}

vi gen(int x) {
	vi ps;
	for (int d = -1; d <= 1; ++d) {
		int v = x + d;
		vi cur_p = gen_primes(v);
		for (int t : cur_p) ps.pb(t);
	}
	sort(all(ps));
	ps.resize(unique(all(ps)) - ps.begin());
	return ps;
}

const ll INF = 1e18;

ll solve(int p) {
	vll dp(3, INF);
	dp[0] = 0;
	forn(i, n) {
		dp[2] = min(dp[2], dp[1]);
		vll ndp(3, INF);
		int x = a[i] % p;
		// leave
		if  (x == 1 || x == p - 1) {
			ndp[0] = min(ndp[0], dp[0] + b);
			ndp[2] = min(ndp[2], min(dp[2], dp[0]) + b);
		}
		if  (x == 0) {
			ndp[0] = min(ndp[0], dp[0]);
			ndp[2] = min(ndp[2], min(dp[2], dp[0]));
		}
		// del
		if  (i > 0) {
			ndp[1] = min(ndp[1], min(dp[0], dp[1]) + A);
		}
		dp.swap(ndp);
	}
	return *min_element(all(dp));
}

ll solve() {
	ll ans = b * 1ll * n;
	vi ps = gen(a[0]);
	for (int p : ps) {
		ll cur = solve(p);
		ans = min(ans, cur);
	}
	reverse(a, a + n);
	ps = gen(a[0]);
	for (int p : ps) {
		ll cur = solve(p);
		ans = min(ans, cur);
	}
	return ans;
}

int main() {
#ifdef DEBUG
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	precalc();

	while (read()) {
		cout << solve() << '\n';
	}

	return 0;
}