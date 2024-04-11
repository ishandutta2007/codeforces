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
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef vector <vector <int> > vvi;
typedef vector <pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

#define FILE_NAME "a"

const int MAXN = 1e5 + 10;

pii a[MAXN];
ll pref[MAXN];
int n, A, cf, cm;
ll m;

ll sum(int l, int r) {
	if  (l > r) return 0;
	return pref[r + 1] - pref[l];
}

bool read() {
	if  (scanf("%d%d%d%d\n", &n, &A, &cf, &cm) < 4) {
		return false;
	} 
	cin >> m;
	forn(i, n) {
		scanf("%d", &a[i].fst);
		a[i].snd = i;
	}
	return true;
}

void precalc() {
	sort(a, a + n);

	pref[0] = 0;
	forn(i, n) {
		pref[i + 1] = pref[i] + a[i].fst;
	}
}

void solve() {
	precalc();

	ll ans = -1;
	int best_cnt = -1;
	int best_min = -1;
	forn(cnt, n + 1) {
		ll rest = m - (A * 1ll * cnt - sum(n - cnt, n - 1));
		if  (rest < 0) {
			continue;
		}

		int L = -1;
		int R = A + 1;
		while (L != R - 1) {
			int M = (L + R) / 2;
			bool can = false;
			int pos = lower_bound(a, a + n, mp(M, -1)) - a;
			--pos;
			pos = min(pos, n - cnt - 1);
			if  (pos < 0) {
				can = true;
			} else {
				assert(a[pos].fst < M);
				ll spend = M * 1ll * (pos + 1) - sum(0, pos);
				can = spend <= rest;
			}
			if  (can) {
				L = M;
			} else {
				R = M;
			}
		}

		ll cur = cf * 1ll * cnt + cm * 1ll * L;
		if  (cur > ans) {
			ans = cur;
			best_cnt = cnt;
			best_min = L;
		} 
	}

	cout << ans << '\n';
	vi na(n);
	forn(i, n) {
		if  (i >= n - best_cnt) {
			na[a[i].snd] = A;
		} else if  (a[i].fst < best_min) {
			na[a[i].snd] = best_min;
		} else {
			na[a[i].snd] = a[i].fst;
		}
	}
	forn(i, n) {
		printf("%d ", na[i]);
	}
	puts("");
}

int main() {
#ifdef DEBUG
	freopen(FILE_NAME ".in", "r", stdin);
//	freopen(FILE_NAME ".out", "w", stdout);
#endif
	
	while (read()) {
		solve();
	}
	return 0;
}