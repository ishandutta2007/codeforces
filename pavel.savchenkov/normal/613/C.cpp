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

using namespace std;

#define pb push_back
#define fst first
#define snd second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define next jskdfksdhfjkdsjksdjkgf
#define prev koeuigrihjdkjdfj
#define hash kjfdkljkdhgjdkfhgurehg
#define all(C) begin(C), end(C)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector <int> > vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

#define FILE_NAME "a"

const int MAXA = 26;
const int MAXN = 1e5 + 10;

int A;
int cnt[MAXA];
char s[MAXN];

void precalc() {

}

bool read() {
	if  (scanf("%d", &A) < 1) {
		return false;
	}
	forn(i, A) {
		assert(scanf("%d", &cnt[i]));
	}
	return true;
}

bool can_pal(const vi& cnt) {
	int cnt_odd = 0;
	forn(c, A) {
		cnt_odd += (cnt[c] & 1);
	}
	return cnt_odd <= 1;
}

void solve() {
	int n = 0;
	forn(c, A) {
		n += cnt[c];
	}

	int best_len = n + 1;
	for (int len = 1; len <= n; ++len) {
		if  (n % len != 0) {
			continue;
		}

		int blocks = n / len;

		vi cur_cnt(A, 0);
		bool ok = true;
		forn(c, A) {
			if  (cnt[c] % blocks != 0) {
				ok = false;
				break;
			}
			cur_cnt[c] = cnt[c] / blocks;
		}

		if  (!ok) {
			continue;
		}

		if  (blocks % 2 == 0) {
			best_len = min(best_len, len);
		}

		if  (can_pal(cur_cnt)) {
			best_len = min(best_len, len);
		}
	}

	if  (best_len == n + 1) {
		puts("0");
		n = 0;
		forn(c, A) forn(i, cnt[c]) s[n++] = 'a' + c;
		s[n] = 0;
		puts(s);
		return;
	}

	printf("%d\n", n / best_len);
	int blocks = n / best_len;
	vi cur_cnt(A, 0);
	forn(c, A) {
		assert(cnt[c] % blocks == 0);
		cur_cnt[c] = cnt[c] / blocks;
	}

	if  (blocks % 2 == 0) {
		n = 0;
		forn(b, blocks) {
			if  (b & 1) {
				forn(c, A) forn(i, cur_cnt[c]) s[n++] = 'a' + c;
			} else {
				ford(c, A) forn(i, cur_cnt[c]) s[n++] = 'a' + c;
			}
		}
		s[n] = 0;
	} else {
		forn(b, blocks) {
			int l = b * best_len;
			int r = l + best_len - 1;
			forn(c, A) {
				forn(i, cur_cnt[c] / 2) {
					s[l] = s[r] = 'a' + c;
					++l;
					--r;
				}
				if  (cur_cnt[c] & 1) {
					s[(l + r) / 2] = 'a' + c;
				}
			}
		}
	}
	puts(s);
}

int main() {
#ifdef DEBUG
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif
	
	while (read()) {
		solve();
	}

	return 0;
}