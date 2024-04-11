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

#ifdef LOCAL
#define eprintf(args...) fprintf(stderr, args), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define FILE_NAME "a"

const int MAXN = 1e5 + 10;

int rad, d;
int x[MAXN];
int y[MAXN];
int r[MAXN];
int n;

bool read() {
	if  (scanf("%d%d", &rad, &d) < 2) {
		return 0;
	}
	scanf("%d", &n);
	forn(i, n) {
		scanf("%d%d%d", &x[i], &y[i], &r[i]);
	}
	return 1;
}

int solve() {
	int ans = 0;
	forn(i, n) {
		const int d2 = x[i] * x[i] + y[i] * y[i];
		if  (d2 < (rad - d + r[i]) * (rad - d + r[i])) {
			continue;
		}
		// printf("x=%d, y=%d, r=%d\n", x[i], y[i], r[i]);
		if  (d2 > (rad - r[i]) * (rad - r[i])) {
			continue;
		}
		if  (r[i] * 2 > d) {
			continue;
		}
		++ans;
	}
	return ans;
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