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

const int MAXN = 2e5 + 10;

int p[MAXN];
int b[MAXN];
int n;

bool read() {
	if  (scanf("%d", &n) < 1) {
		return 0;
	}
	forn(i, n) {
		scanf("%d", &p[i]);
		--p[i];
	}
	forn(i, n) {
		scanf("%d", &b[i]);
	}
	return 1;
}

bool used[MAXN];

int solve() {
	int cycles = 0;
	memset (used, 0, sizeof used);
	forn(i, n) {
		if  (!used[i]) {
			++cycles;
			int j = i;
			while (!used[j]) {
				used[j] = 1;
				j = p[j];
			}
		}
	}

	int s = accumulate(b, b + n, 0);

	int ans = cycles - (cycles == 1);
	if  (s % 2 == 0) {
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