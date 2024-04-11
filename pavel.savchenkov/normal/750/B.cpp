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

const int MAXN = 1e5 + 10;

int n;
int t[MAXN];
string dir[MAXN];

bool read() {
	if  (scanf("%d\n", &n) < 1) {
		return 0;
	}
	forn(i, n) {
		cin >> t[i] >> dir[i];
	}
	return 1;
}

const int LEN = 20000;

bool solve() {
	int y = 0;
	forn(i, n) {
		if  (dir[i] == "East" || dir[i] == "West") {
			if  (y == 0 || y == LEN) {
				return 0;
			}
			continue;
		}
		if  (dir[i] == "South") {
			if  (y == LEN) {
				return 0;
			}
			if  (y + t[i] > LEN) {
				return 0;
			}
			y += t[i];
			continue;
		}
		assert(dir[i] == "North");
		if  (y == 0) {
			return 0;
		}
		if  (y - t[i] < 0) {
			return 0;
		}
		y -= t[i];
	}
	return y == 0;
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