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
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef vector <vector <int> > vvi;
typedef vector <pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

#define FILE_NAME "a"

const ll INF = 2e18;

ll mul(ll a, ll b) {
	ll c = a * b;
	if  (!c) return 0;
	if  (a >= INF || b >= INF) return INF;
	if  (c / a != b || c >= INF) return INF;
	return c;
}

ll add(ll a, ll b) {
	return a + b >= INF ? INF : a + b;
}

ll sum(ll n) {
	if  (n < 1) return 0;
	if  (n & 1) {
		return mul((n + 1) / 2, n);
	} else {
		return mul(n / 2, n + 1);
	}
}

ll get_first(ll k) {
	return add(mul(6, sum(k - 2)), 1);
}

pll solve(ll n) {
	if  (n == 0) {
		return mp(0, 0);
	}

	// [2, INF]
	ll L = 1;
	ll R = 1e10;
	while (L != R - 1) {
		ll M = (L + R) / 2;
		if  (get_first(M) <= n) {
			L = M;
		} else {
			R = M;
		}
	}

	ll k = L;
	n -= get_first(k);

	ll x = (k - 1) * 2;
	ll y = 0;
	--x;
	y += 2;

	if  (n <= k - 2) {
		x -= n;
		y += 2 * n;
	} else if  (n <= 2 * k - 3) {
		x -= k - 2;
		y += 2 * (k - 2);
		
		ll cnt = n - (k - 2);
		x -= 2 * cnt;
	} else if  (n <= 3 * k - 4) {
		x -= k - 2;
		y += 2 * (k - 2);
		
		x -= 2 * (k - 1);
		
		ll cnt = n - (2 * k - 3);
		x -= cnt;
		y -= 2 * cnt;
	} else if  (n <= 4 * k - 5) {
		x -= k - 2;
		y += 2 * (k - 2);

		x -= 2 * (k - 1);

		x -= k - 1;
		y -= 2 * (k - 1);

		ll cnt = n - (3 * k - 4);
		x += cnt;
		y -= 2 * cnt;
	} else if  (n <= 5 * k - 6) {
		x -= k - 2;
		y += 2 * (k - 2);

		x -= 2 * (k - 1);

		x -= k - 1;
		y -= 2 * (k - 1);

		x += k - 1;
		y -= 2 * (k - 1);

		ll cnt = n - (4 * k - 5);
		x += 2 * cnt;
	} else {
		assert(n <= 6 * k - 7);

		x -= k - 2;
		y += 2 * (k - 2);

		x -= 2 * (k - 1);

		x -= k - 1;
		y -= 2 * (k - 1);

		x += k - 1;
		y -= 2 * (k - 1);

		x += 2 * (k - 1);

		ll cnt = n - (5 * k - 6);
		x += cnt;
		y += 2 * cnt;
	}

	return mp(x, y);
}

int main() {
#ifdef DEBUG
	freopen(FILE_NAME ".in", "r", stdin);
//	freopen(FILE_NAME ".out", "w", stdout);
#endif
	
	ll n;
	cin >> n;
	auto res = solve(n);
	cout << res.fst << " " << res.snd << endl;
	return 0;

	for (ll n = 0; n <= 20; ++n) {
		auto res = solve(n);
		cout << res.fst << " " << res.snd << endl;
	}

	return 0;
}