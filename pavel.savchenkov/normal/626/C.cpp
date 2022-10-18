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

int n, m;

bool read() {
	if  (scanf("%d%d", &n, &m) < 2) {
		return false;
	}
	return true;
}

const int MAX = 5e6 + 10;

bool can(int C) {
	int mm = m;
	int nn = n;
	for (int i = C; i > 1 && mm > 0; --i) {
		if  (i % 3 == 0 && i % 2 != 0) {
			--mm;
		}
	}
	for (int i = C; i > 1 && nn > 0; --i) {
		if  (i % 2 == 0 && i % 3 != 0) {
			--nn;
		}
	}
	for (int i = C; i > 1; --i) {
		if  (i % 3 == 0 && i % 2 == 0) {
			if  (nn > 0) {
				--nn;
			} else if  (mm > 0) {
				--mm;
			}
		}
	}
	return (nn == 0 && mm == 0);
}

int solve() {
	int L = 1;
	int R = MAX;
	while (L != R - 1) {
		int M = (L + R) / 2;
		if  (can(M)) {
			R = M;
		} else {
			L = M;
		}
	}
	return R;
}

int main() {
#ifdef DEBUG
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		printf("%d\n", solve());
	}

	return 0;
}