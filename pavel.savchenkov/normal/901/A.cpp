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

int h;
vi a;

bool read() {
	if  (scanf("%d", &h) < 1) {
		return 0;
	}
	a.resize(h + 1);
	forn(i, h + 1) {
		scanf("%d", &a[i]);
	}
	return 1;
}

bool solve() {
	vvi vers(h + 1);
	int ptr = 0;
	forn(i, h + 1) {
		forn(it, a[i]) {
			vers[i].pb(ptr++);
		}
	}

	int good_layer = -1;
	forn(i, h) {
		if  (a[i] > 1 && a[i + 1] > 1) {
			good_layer = i;
		}
	}
	if  (good_layer == -1) {
		return 0;
	}
	assert(good_layer > 0);

	puts("ambiguous");
	forn(it, 2) {
		forn(i, h + 1) {
			forn(cnt, sz(vers[i])) {
				if  (!i) {
					printf("0 ");
					continue;
				}
				int par = vers[i - 1].front();
				if  (it && i - 1 == good_layer && cnt == 1) {
					par = vers[i - 1][1];
				}
				printf("%d ", par + 1);
			}
		}
		puts("");
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
			puts("perfect");
		}
	}

#ifdef LOCAL
	eprintf("Time: %.10f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}