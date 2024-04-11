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


int n;
vi p;
vi a;
vi b;

bool read() {
	if  (scanf("%d", &n) < 1) {
		return 0;
	}
	p.resize(n);
	forn(i, n) {
		scanf("%d", &p[i]);
	}
	a.resize(n);
	forn(i, n) {
		scanf("%d", &a[i]);
		--a[i];
	}
	b.resize(n);
	forn(i, n) {
		scanf("%d", &b[i]);
		--b[i];
	}
	return 1;
}

set<pii> byA[3];
set<pii> byB[3];

void solve() {
	forn(i, 3) {
		byA[i].clear();
		byB[i].clear();
	}

	forn(i, n) {
		byA[a[i]].insert(mp(p[i], i));
		byB[b[i]].insert(mp(p[i], i));
	}

	int m;
	scanf("%d", &m);
	forn(it, m) {
		int c;
		scanf("%d", &c);
		--c;

		int best = -1;
		if  (!byA[c].empty()) {
			best = byA[c].begin()->snd;
		}
		if  (!byB[c].empty()) {
			int cur = byB[c].begin()->snd;
			if  (best == -1 || p[cur] < p[best]) {
				best = cur;
			}
		}

		if  (best != -1) {
			byA[a[best]].erase(mp(p[best], best));
			byB[b[best]].erase(mp(p[best], best));
			
			best = p[best];
		}

		printf("%d ", best);
	}
	puts("");
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		solve();
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}