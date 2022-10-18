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

const int MAXN = 1e3 + 10;

int n, m;
char s[MAXN][MAXN];

bool read() {
	if  (scanf("%d%d\n", &n, &m) < 2) {
		return 0;
	}
	forn(i, n) {
		scanf("%s\n", s[i]);
	}
	return 1;
}

bool dp[10][MAXN][MAXN];
int ti, tj;
int si, sj;

void calc(int k) {
	forn(i, n) {
		for (int l = 0, r = 0; l < m; l = r) {
			r = l + 1;
			if  (s[i][l] == '*') {
				continue;
			}
			while (r < m && s[i][r] == '.') {
				++r;
			}

			bool ok = 0;
			for (int j = l; j < r; ++j) {
				ok |= dp[k - 1][i][j];
			} 
			for (int j = l; j < r; ++j) {
				dp[k][i][j] |= ok;
			}
		}
	}

	forn(j, m) {
		for (int l = 0, r = 0; l < n; l = r) {
			r = l + 1;
			if  (s[l][j] == '*') {
				continue;
			}
			while (r < n && s[r][j] == '.') {
				++r;
			}

			bool ok = 0;
			for (int i = l; i < r; ++i) {
				ok |= dp[k - 1][i][j];
			} 
			for (int i = l; i < r; ++i) {
				dp[k][i][j] |= ok;
			}
		}
	}
}

bool solve() {
	memset (dp, 0, sizeof dp);

	ti = tj = -1;
	si = sj = -1;
	forn(i, n) forn(j, m) {
		if  (s[i][j] == 'T') {
			ti = i;
			tj = j;
			s[i][j] = '.';
		} else if  (s[i][j] == 'S') {
			si = i;
			sj = j;
			s[i][j] = '.';
		}
	}
	assert(ti != -1);
	assert(tj != -1);
	assert(si != -1);
	assert(sj != -1);

	dp[0][ti][tj] = 1;
	for (int k = 1; k <= 3; ++k) {
		calc(k);

		// printf("k=%d\n", k);
		// forn(i, n) {
		// 	forn(j, m) {
		// 		printf("%d ", dp[k][i][j]);
		// 	}
		// 	puts("");
		// }
		// puts("");
	}

	return dp[3][si][sj];
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		puts(solve() ? "YES" : "NO");
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}