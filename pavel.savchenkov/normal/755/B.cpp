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

const int A = 26;
const ull P = 29;

ull coef[A];

void precalc() {
	forn(c, A) {
		coef[c] = rand() * 1ull * RAND_MAX + rand();
	}
}

ull hs(const string& s) {
	ull h = 0;
	ull p = 1;
	for (const char& c : s) {
		h += p * coef[c - 'a'];
		p *= P;
	}
	return h;
} 

int n, m;
int both;

bool read() {
	if  (scanf("%d%d\n", &n, &m) < 1) {
		return 0;
	}
	static char s[MAXN];
	both = 0;
	set<ull> was;
	forn(i, n) {
		scanf("%s\n", s);
		auto h = hs(s);
		was.insert(h);
	}
	forn(i, m) {
		scanf("%s\n", s);
		auto h = hs(s);
		if  (was.count(h)) {
			++both;
		}
	}
	return 1;
}


bool solve() {
	n -= both;
	m -= both;

	bool sw = 0;
	if  (both & 1) {
		sw = 1;
		swap(n, m);
	}

	if  (n > m) {
		return 1 ^ sw;
	}

	return 0 ^ sw;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	precalc();

	while (read()) {
		puts(solve() ? "YES" : "NO");
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}