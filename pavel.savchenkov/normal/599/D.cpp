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

const ld EPS = 1e-9;
const ll INF = 4e18;

ll mult(ll x, ll y) {
	if  (!x || !y) return 0;
	if  (x >= INF || y >= INF) return INF;
	ll z = x * y;
	if  (z / x == y) return z;
	return INF;
}

ll add(ll x, ll y) {
	return max(-INF, min(x + y, INF));
}

int main() {
//	freopen(FILE_NAME ".in", "r", stdin);
//	freopen(FILE_NAME ".out", "w", stdout);

	ll x;
	cin >> x;

	vector<pll> ans;
	ll sum_sq = 0;
	for (ll n = 1; ; ++n) {
		ll C = n * (n - 1) / 2;
		ll D = add(add(x, -sum_sq), + n * C);
		if  (D < 0) break;
		if  (D % (n * n - C) == 0) {
			ll m = D / (n * n - C);
			if  (n <= m) {
				ans.pb(mp(n, m));
			}
		}
		// m * n * n - m * ()
		sum_sq = add(sum_sq, n * n);
		if  (sum_sq >= INF) {
			break;
		}
	}

	forn(i, sz(ans)) {
		if  (ans[i].fst < ans[i].snd) {
			ans.pb(mp(ans[i].snd, ans[i].fst));
		} else {
			reverse(ans.begin() + i + (ans[i].fst == ans[i].snd), ans.end());
			break;
		}
	}

	printf("%d\n", sz(ans));
	forn(i, sz(ans)) {
		printf("%lld %lld\n", ans[i].fst, ans[i].snd);
	}
	return 0;
}