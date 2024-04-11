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

const int MAXN = 1e5 + 10;

int n, m;
int d[MAXN];
int a[MAXN];

bool read() {
	if  (scanf("%d%d", &n, &m) < 2) {
		return false;
	}
	forn(i, n) {
		scanf("%d", &d[i]);
		--d[i];
	}
	forn(i, m) {
		scanf("%d", &a[i]);
	}
	return true;
}

bool was[MAXN];

bool can(int last) {
	assert(0 <= last && last < n);
	memset (was, false, sizeof was);
	int need = 0;
	for (int i = last; i >= 0; --i) {
		if  (d[i] == -1) {
			need = max(0, need - 1);
			continue;
		}
		if  (!was[d[i]]) {
			need += a[d[i]];
			was[d[i]] = true;
			continue;
		}
		need = max(0, need - 1);
	}
	forn(i, m) {
		if  (!was[i]) {
			return 0;
		}
	}
	return need == 0;
}

int solve() {
	int L = -1;
	int R = n;
	while (L != R - 1) {
		int M = (L + R) / 2;
		if  (can(M)) {
			R = M;
		} else {
			L = M;
		}
	}
	if  (R == n) {
		return -1;
	}
	return R + 1;
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