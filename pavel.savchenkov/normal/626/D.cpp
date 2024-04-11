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

const int MAXN = 2e3 + 10;
const int MAXC = 5e3 + 10;
const ld EPS = 1e-11;

int a[MAXN];
int n;

bool read() {
	if  (scanf("%d", &n) < 1) {
		return false;
	}
	forn(i, n) {
		scanf("%d", &a[i]);
	}
	return true;
}

ld dp0[MAXC];
ld dp1[MAXC * 2];

ld solve() {
	int C = n * (n - 1) / 2;
	memset (dp0, 0, sizeof dp0);
	forn(i, n) forn(j, n) {
		if  (a[i] <= a[j]) {
			continue;
		}
		dp0[a[i] - a[j]] += ld(1) / C;
	}

	memset (dp1, 0, sizeof dp1);
	forn(d, MAXC) {
		if  (dp0[d] < EPS) {
			continue;
		}
		forn(d2, MAXC) {
			if  (dp0[d2] < EPS) {
				continue;
			}
			dp1[d + d2] += dp0[d] * dp0[d2];
		}
	}

	ld ans = 0;
	forn(d, MAXC * 2) {
		forn(d2, MAXC) {
			if  (d + (-d2) < 0) {
				ans += dp1[d] * dp0[d2];
			}
		}
	}

	return ans;
}


int main() {
#ifdef DEBUG
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		printf("%.15f\n", (double) solve());
	}

	return 0;
}