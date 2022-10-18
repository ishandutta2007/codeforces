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

const int MAXN = 30 + 10;
const int A = 26;

char s[A + 2];

bool read() {
	gets(s);
	return 1;
}

char ans[2][A + 1];

bool solve() {
	forn(i, A + 1) forn(j, i) {
		if (s[j] == s[i]) {
			rotate(s, s + j, s + A + 1);
			break;
		}
	} 

	if  (s[1] == s[0]) {
		return 0;
	}

	int dist = -1;
	for (int i = 1; i < A + 1; ++i) {
		if  (s[i] == s[0]) {
			dist = i - 1;
			break;
		}
	} 
	assert(dist != -1);

	// puts(s);

	int col = dist / 2;
	// printf("dist = %d, col = %d\n", dist, col);

	ans[0][col] = s[0];
	int ptr = 1;
	if  (dist & 1) {
		ford(i, col) {
			ans[0][i] = s[ptr++];
		}
		forn(i, col + 1) {
			ans[1][i] = s[ptr++];
		}
		for (int i = col; i < A / 2; ++i) {
			ans[0][i] = s[ptr++];
		}
		for (int i = A / 2 - 1; i > col; --i) {
			ans[1][i] = s[ptr++];
		}
	} else {
		ford(i, col) {
			ans[0][i] = s[ptr++];
		}
		forn(i, col) {
			ans[1][i] = s[ptr++];
		}
		for (int i = col; i < A / 2; ++i) {
			ans[0][i] = s[ptr++];
		}
		for (int i = A / 2 - 1; i >= col; --i) {
			ans[1][i] = s[ptr++];
		}
	}	
	assert(ptr == A + 1);
	assert(ans[0][col] == s[0]);

	forn(c, 2) {
		ans[c][A] = 0;
		puts(ans[c]);
	}

	return 1;

	return 1;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		if  (!solve()) {
			puts("Impossible");
		}

		break;
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}