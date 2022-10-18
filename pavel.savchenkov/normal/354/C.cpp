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


const int MAXN = 1e6 + 10;

bool have[MAXN];
int prev[MAXN];
int n, k;

bool read() {
	if  (scanf("%d%d", &n, &k) < 2) {
		return false;
	}
	memset (have, 0, sizeof have);
	forn(i, n) {
		int a;
		scanf("%d", &a);
		have[a] = true;
	}
	return true;
}

int solve() {
	memset (prev, -1, sizeof prev);
	int last = -1;
	forn(i, MAXN) {
		prev[i] = last;
		if  (have[i]) {
			last = i;
		}
	}

	int mn = MAXN;
	forn(i, MAXN) {
		if  (have[i]) {
			mn = i;
			break;
		}
	}

	for (int g = mn; g > 0; --g) {
		bool ok = true;
		for (int i = 2 * g; i < MAXN; i += g) {
			int j = i - g;
			int num = prev[i];
			if  (num - k > j) {
				ok = false;
				break;
			}
		}
		int i = (MAXN - 1);
		int j = i - (i % g);
		int num = prev[i];
		if  (num - k > j) {
			ok = false;
		}

		if  (ok) {
			return g;
		}
	}

	assert(false);
	return -1;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		printf("%d\n", solve());
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}