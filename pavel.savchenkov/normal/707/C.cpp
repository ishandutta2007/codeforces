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
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
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

const int MAX = 1e6;

bool check(ll a, ll b, ll c) {
	if  (a * a + b * b == c * c && 1 <= a && 1 <= b && 1 <= c) {
		return true;
	}
	return false;
}

void solve(ll n) {
	for (ll d = 0; d < MAX; ++d) {
		ll L = 0;
		ll R = n + 1;
		while (L != R - 1) {
			ll M = (L + R) / 2;
			if  (M * M + (M + d) * (M + d) > n * n) {
				R = M;
			} else {
				L = M;
			}
		}
		if  (check(L, L + d, n) && L > 0) {
			cout << L << " " << L + d << endl;
			return;
		}
	}

	for (ll x = 1; x < MAX && x < n; ++x) {
		ll y = sqrt(n * n - x * x + 0.5);
		if  (y * y == n * n - x * x) {
			cout << x << " " << y << endl;
			return;
		}
	}

	for (ll x = n - 1; x > 0 && x > n - MAX; --x) {
		ll y = sqrt(n * n - x * x + 0.5);
		if  (y * y == n * n - x * x) {
			cout << x << " " << y << endl;
			return;
		}
	}

	vll divs;
	for (ll x = 1; x * x <= n; ++x) {
		if  (n % x == 0) {
			divs.pb(x);
			if  (x * x < n) {
				divs.pb(n / x);
			}
		}
	}

	vll ndivs;
	for (auto d : divs) for (auto d2 : divs) {
		ndivs.pb(d * d2);
	}

	sort(all(ndivs));
	ndivs.resize(unique(all(ndivs)) - ndivs.begin());

	for (ll d : ndivs) {
		ll d2 = n * n / d;
		ll x = (d + d2) / 2;
		if  (2 * x != d + d2) {
			continue;
		}
		ll y = d2 - x;
		if  (!check(n, y, x)) {
			continue;
		}
		cout << x << " " << y << endl;
		return;
	}

	cout << "-1" << endl;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	int n;
	cin >> n;
	solve(n);

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}