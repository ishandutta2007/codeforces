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

#define FILE_NAME "a"


int n, m;
vvi g;

bool read() {
	if  (scanf("%d%d", &n, &m) < 2) {
		return 0;
	}
	g.clear();
	g.resize(n, vi(m, 0));
	forn(i, n) {
		forn(j, m) {
			scanf("%d", &g[i][j]);
		}
	}
	return 1;
}

const int INF = 1e9;

bool solve() {
	int best_sum = INF;
	vi best_rows;
	vi best_cols;

	for (int row0 = 0; row0 <= g[0][0]; ++row0) {
		vi rows(n, 0);
		vi cols(m, 0);

		rows[0] = row0;
		forn(j, m) {
			cols[j] = g[0][j] - rows[0];
		}

		for (int i = 1; i < n; ++i) {
			forn(j, m) {
				rows[i] = g[i][j] - cols[j];
			}
		}

		bool bad = 0;
		forn(i, n) forn(j, m) {
			if  (g[i][j] != rows[i] + cols[j]) {
				bad = 1;
				break;
			}
			if  (rows[i] < 0 || cols[j] < 0) {
				bad = 1;
				break;
			}
		}

		if  (bad) {
			continue;
		}

		int sum = accumulate(all(rows), 0) + accumulate(all(cols), 0);
		if  (sum < best_sum) {
			best_sum = sum;
			best_rows = rows;
			best_cols = cols;
		}
	}

	if  (best_sum >= INF) {
		return 0;
	}

	printf("%d\n", best_sum);
	forn(i, n) {
		forn(it, best_rows[i]) {
			printf("row %d\n", i + 1);
		}
	}
	forn(j, m) {
		forn(it, best_cols[j]) {
			printf("col %d\n", j + 1);
		}
	}
	return 1;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		if  (!solve()) {
			puts("-1");
		}
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}