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

string read_s() {
	static char s[MAXN];
	scanf("%s\n", s);
	return s;
}

string t, p;
int a[MAXN];

bool read() {
	t = read_s();
	p = read_s();
	forn(i, sz(t)) {
		scanf("%d", &a[i]);
		--a[i];
	}
	return 1;
}

bool used[MAXN];

bool can(int pref) {
	assert(pref <= sz(t));
	memset (used, 0, sizeof used);
	forn(i, pref) {
		used[a[i]] = 1;
	}

	int j = 0;
	for (int i = 0; i < sz(t) && j < sz(p); ++i) {
		if  (used[i]) {
			continue;
		}
		if  (p[j] == t[i]) {
			++j;
		}
	}
	return j == sz(p);
}

int solve() {
	int L = 0;
	int R = sz(t) + 1;
	while (L != R - 1) {
		int M = (L + R) / 2;
		if  (can(M)) {
			L = M;
		} else {
			R = M;
		}
	}
	return L;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		printf("%d\n", solve());

		break;
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}