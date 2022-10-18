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

ll solve(ll s, ll x) {
	ll S = s;
	ll X = x;
	int ways = 0;
	int hb = -1;
	forn(i, 60) {
		if  (x & (1ll << i)) {
			++ways;
			s -= 1ll << i;
			hb = i;
		}
	}
	if  (s < 0) {
		// printf("s < 0\n");
		return 0;
	}
	if  (hb == -1) {
		if  (s % 2 == 0) return 1;
		return 0;
	}
	forn(i, 60) {
		if  (!(x & (1ll << i))) {
			int bit = i + 1;
			if  (s & (1ll << bit)) {
				s -= 1ll << bit;
			}
		}
	}
	if  (s == 0) {
		ll ans = 1ll << ways;
		if  (X + 0 == S) {
			ans -= 2;
		}
		return ans;
	}
	return 0;
}

int main() {
#ifdef DEBUG
	// freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	ll s, x;
	cin >> s >> x;
	cout << solve(s, x) << endl;

	return 0;
}