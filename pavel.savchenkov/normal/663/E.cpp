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

const int MAXN = (1 << 20) + 10;

int mask[MAXN];
ll cnt[MAXN];
int n, m;

bool read() {
	if  (scanf("%d%d\n", &n, &m) < 2) {
		return false;
	}
	memset (cnt, 0, sizeof cnt);
	memset (mask, 0, sizeof mask);
	forn(i, n) {
		static char s[MAXN];
		gets(s);
		forn(j, m) {
			if  (s[j] == '1') {
				mask[j] ^= 1 << i;
			}
		}
	}
	forn(i, m) {
		++cnt[mask[i]];
	}
	return true;
}

void fft(ll* a, int l, int r) {
	if  (l == r) {
		return;
	}
	int m = (l + r) / 2;
	int half = m + 1 - l;
	fft(a, l, m);
	fft(a, m + 1, r);
	for (int i = l; i <= m; ++i) {
		ll x1 = a[i];
		ll x2 = a[i + half];
		a[i] = x1 - x2;
		a[i + half] = x1 + x2;
	}
}

void fft_inv(ll* a, int l, int r) {
	if  (l == r) {
		return;
	}
	int m = (l + r) / 2;
	int half = m + 1 - l;
	for (int i = l; i <= m; ++i) {
		ll x1 = a[i];
		ll x2 = a[i + half];
		a[i] = (x1 + x2) / 2;
		a[i + half] = (x2 - x1) / 2;
	}
	fft_inv(a, l, m);
	fft_inv(a, m + 1, r);
}

ll cost[MAXN];

int solve() {
	forn(mask, 1 << n) {
		int p = __builtin_popcount(mask);
		cost[mask] = min(p, n - p);
	}

	// forn(mask, 1 << n) {
	// 	cout << bitset<3>(mask) << ", cost = " << cost[mask] << ", cnt = " << cnt[mask] << endl;
	// }

	fft(cnt, 0, (1 << n) - 1);
	fft(cost, 0, (1 << n) - 1);
	forn(i, 1 << n) {
		cost[i] *= cnt[i];
	}
	fft_inv(cost, 0, (1 << n) - 1);

	// forn(i, 1 << n) {
	// 	printf("res[%d] = %d\n", i, (int) cost[i]);
	// }
	return *min_element(cost, cost + (1 << n));
}

int main() {
#ifdef DEBUG
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		printf("%d\n", solve());
	}

	return 0;
}