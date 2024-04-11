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
string s;

bool read() {
	if  (!getline(cin, s)) {
		return 0;
	}
	return 1;
}

int id(char c) {
	const string C = "RBYG";
	int res = find(all(C), c) - C.begin();
	assert(res < sz(C));
	return res;
}

bool was[4];

void solve() {
	vi perm(4);
	iota(all(perm), 0);
	do {
		vi cur;
		for (int c : perm) {
			cur.pb(c);
		}
		forn(___, sz(s) - 4) {
			memset (was, 0, sizeof was);
			forn(it, 3) {
				was[cur[sz(cur) - 1 - it]] = 1;
			}
			forn(c, 4) {
				if  (!was[c]) {
					cur.pb(c);
					break;
				}
			}
		}

		bool ok = 1;
		forn(i, sz(cur)) {
			if  (s[i] != '!') {
				if  (cur[i] != id(s[i])) {
					ok = 0;
					break;
				}
			}
		}
		if  (ok) {
			vi cnt(4, 0);
			forn(i, sz(cur)) {
				if  (s[i] == '!') {
					++cnt[cur[i]];
				}
			}
			forn(i, 4) {
				printf("%d ", cnt[i]);
			}
			puts("");
			return;
		}
	} while (next_permutation(all(perm)));

	assert(0);
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		solve();

		break;
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}