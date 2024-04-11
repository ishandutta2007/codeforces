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


const int MAXN = 1e6 + 10;

int cnt[MAXN];
int n, k;

bool read() {
	if  (scanf("%d%d", &n, &k) < 2) {
		return false;
	}
	memset (cnt, 0, sizeof cnt);
	forn(i, n) {
		int c;
		scanf("%d", &c);
		++cnt[c];
	}
	return true;
}

bool pr[MAXN];

int deg(int x, int p) {
	int ans = 0;
	while (x % p == 0) {
		x /= p;
		++ans;
	}
	return ans;
}

void precalc() {
	memset (pr, true, sizeof pr);
	for (int i = 2; i < MAXN; ++i) {
		if  (pr[i]) {
			for (int j = i + i; j < MAXN; j += i) {
				pr[j] = false;
			}
		}
	}
}

int max_deg[MAXN];

bool solve() {
	memset (max_deg, 0, sizeof max_deg);
	for (int p = 2; p < MAXN; ++p) {
		if  (!pr[p]) {
			continue;
		} 
		for (int c = p; c < MAXN; c += p) {
			if  (cnt[c]) {
				max_deg[p] = max(max_deg[p], deg(c, p));
			}
		}
	}

	for (int p = 2; p <= k; ++p) {
		if  (!pr[p]) {
			continue;
		}
		int d = deg(k, p);
		if  (d > max_deg[p]) {
			return false;
		}
	}

	return true;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	precalc();

	while (read()) {
		puts(solve() ? "Yes" : "No");
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}