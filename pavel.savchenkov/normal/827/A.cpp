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

#define TEST 0

const int MAXN = 2e6 + 10;

int n;

bool read() {
#if TEST
	n = 10;
	return 1;
#else
	if  (scanf("%d\n", &n) < 1) {
		return 0;
	}
	return 1;
#endif
}

set<int> fr;
char ans[MAXN];

void solve() {
	memset (ans, 0, sizeof ans);

	vi all;
	forn(i, MAXN) {
		all.pb(i);
	}
	fr = set<int>(all(all));
	forn(iter, n) {
		static char t[MAXN];
		int k;
#if !TEST
		scanf("%s %d", t, &k);
#else
		int len = rand() % (MAXN / 2 / n);
		forn(i, len) {
			t[i] = 'a' + rand() % 26;
		}
		t[len] = 0;
		k = rand() % (MAXN / 2 / n);
#endif

		const int len_t = strlen(t);

		forn(i, k) {
			int pos;
#if !TEST
			scanf("%d", &pos);
			--pos;
#else
			pos = rand() % (MAXN / 2);
#endif

			// eprintf("t = %s, pos = %d\n", t, pos);

			const int start = pos;
			while (1) {
				auto it = fr.lower_bound(pos);
				if  (it == fr.end() || *it - start + 1 > len_t) {
					break;
				}
				pos = *it;
				fr.erase(pos);
				ans[pos] = t[pos - start];
				++pos;
			}
		}
#if !TEST
		scanf("\n");
#endif
	}

	int len = 0;
	forn(i, MAXN) {
		if  (ans[i]) {
			len = i + 1;
		}
	}
	eprintf("len = %d\n", len);
	forn(i, len) {
		if  (!ans[i]) {
			ans[i] = 'a';
		}
	}
	puts(ans);
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