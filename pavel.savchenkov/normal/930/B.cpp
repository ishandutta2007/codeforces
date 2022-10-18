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

const int MAXN = 5e3 + 10;

int n;
char s[MAXN];

bool read() {
	scanf("%s\n", s);
	n = strlen(s);
	return 1;
}

const int A = 26;

int cnt[A][A][MAXN];

void solve() {
	memset (cnt, 0, sizeof cnt);
	forn(i, n) {
		forn(j, n) {
			if  (i != j) {
				int d = j - i;
				if  (d < 0) {
					d += n;
				}
				++cnt[s[i] - 'a'][s[j] - 'a'][d];
			}
		}
	}

	ld ans = 0;
	forn(i, n) {
		const int ch = s[i] - 'a';
		ld best = 0;
		for (int d = 1; d < n; ++d) {
			int all = 0;
			int good = 0;
			forn(c, A) {
				const int cur_cnt = cnt[ch][c][d];
				all += cur_cnt;
				good += cur_cnt == 1;
			}
			ld cur_prob = good * 1.0 / all;
			best = max(best, cur_prob);
		}
		ans += best;
	}
	ans /= n;

	printf("%.10f\n", (double) ans);
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	forn(it, 1) {
		assert(read());

		solve();
	}

#ifdef LOCAL
	eprintf("Time: %.10f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}