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
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;

#define FILE_NAME "a"

const int N = 4;

char a[N][N];

bool read() {
	forn(i, N) {
		scanf("%s\n", a[i]);
	}
	return 1;
}

bool check() {
	// hor
	forn(i, N) forn(j, N) {
		int cnt = 0;
		for (int jj = j; jj < j + N - 1 && jj < N; ++jj) {
			cnt += a[i][jj] == 'x';
		}
		if  (cnt == N - 1) {
			return 1;
		}
	}

	// ver
	forn(i, N) forn(j, N) {
		int cnt = 0;
		for (int ii = i; ii < i + N - 1 && ii < N; ++ii) {
			cnt += a[ii][j] == 'x';
		}
		if  (cnt == N - 1) {
			return 1;
		}
	}

	// diag 1
	forn(i, N) forn(j, N) {
		int cnt = 0;
		for (int ii = i, jj = j; ii < i + N - 1 && ii < N && jj < j + N - 1 && jj < N; ++ii, ++jj) {
			cnt += a[ii][jj] == 'x';
		}
		if  (cnt == N - 1) {
			return 1;
		}
	}

	// diag
	forn(i, N) forn(j, N) {
		int cnt = 0;
		for (int ii = i, jj = j; ii < i + N - 1 && ii < N && jj >= j - N + 2 && jj >= 0; ++ii, --jj) {
			cnt += a[ii][jj] == 'x';
		}
		if  (cnt == N - 1) {
			return 1;
		}
	}

	return 0;
}

bool solve() {
	forn(i, N) forn(j, N) {
		if  (a[i][j] == '.') {
			a[i][j] = 'x';
			if  (check()) {
				return 1;
			}
			a[i][j] = '.';
		}
	}
	return 0;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif


	while (read()) {
		puts(solve() ? "YES" : "NO");

		break;
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}