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
typedef vector<vector <int> > vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

#define FILE_NAME "a"

const int MAXN = 2e6 + 10;

int a[2][2];
int n;

bool read() {
	forn(i, 2) forn(j, 2) {
		if  (scanf("%d", &a[i][j]) < 1) {
			return false;
		}
	}
	return true;
}

vector<vll> calc(char s[MAXN]) {
	vector<vll> cnt(2, vll(2));
	vi was(2);
	for (int i = 0; s[i]; ++i) {
		forn(j, 2) {
			cnt[j][s[i] - '0'] += was[j];
		}
		++was[s[i] - '0'];
	}
	return cnt;
}

bool solve() {
	int A = 0;
	while (A * (A - 1) / 2 < a[0][0]) ++A;
	if  (A * (A - 1) / 2 != a[0][0]) {
		return false;
	}

	if  (a[0][0] == 0 && (a[1][0] != 0 || a[0][1] != 0)) {
		A = 1;
	}

	int B = 0;
	while (B * (B - 1) / 2 < a[1][1]) ++B;
	if  (B * (B - 1) / 2 != a[1][1]) {
		return false;
	} 

	if  (a[1][1] == 0 && (a[1][0] != 0 || a[0][1] != 0)) {
		B = 1;
	}

	// printf("A=%d, B=%d\n", A, B);

	if  (B * 1ll * A != a[0][1] + a[1][0]) {
		return false;
	}

	static int b[2][2];
	forn(i, 2) forn(j, 2) b[i][j] = a[i][j];

	vii ps;
	forn(it, B) {
		int need_left = b[0][1];
		int need_right = b[1][0];
		if  (need_left >= A) {
			ps.pb(mp(A, 0));
		} else {
			ps.pb(mp(need_left, A - need_left));
		}
		{
			int x, y;
			tie(x, y) = ps.back();
			b[0][1] -= x;
			b[1][0] -= y;
		}
	}

	sort(all(ps));
	static char s[MAXN];
	int n = 0;
	int was0 = 0;
	int i = 0;
	while (i < sz(ps) || was0 < A) {
		while (i < sz(ps) && ps[i].fst > was0) {
			s[n] = '0';
			++n;
			++was0;
		}
		while (i < sz(ps) && ps[i].fst == was0) {
			s[n] = '1';
			++n;
			++i;
		}
		if  (i == sz(ps)) {
			while (was0 < A) {
				s[n] = '0';
				++n;
				++was0;
			}
		}
	}
	assert(n == A + B);
	if  (n == 0) {
		s[n] = '0';
		++n;
		s[n] = 0;
		puts(s);
		return true;
	}

	auto cnt = calc(s);
	forn(i, 2) forn(j, 2) {
		if  (a[i][j] != cnt[i][j]) {
			return false;
		}
	}

	s[n] = 0;
	puts(s);

	return true;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		if  (!solve()) {
			puts("Impossible");
		}
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}