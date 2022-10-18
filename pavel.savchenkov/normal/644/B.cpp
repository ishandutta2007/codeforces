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

const int MAXN = 2e5 + 10;

int t[MAXN];
int d[MAXN];
int n, b;

bool read() {
	if  (scanf("%d%d", &n, &b) < 2) {
		return false;
	}
	forn(i, n) {
		scanf("%d%d", &t[i], &d[i]);
	}
	return true;
}

int Q[MAXN];
int ql, qr;
int who;

ll ans[MAXN];
ll cur_t;

void do_until(ll lim) {
	if  (who != -1) {
		if  (cur_t + d[who] <= lim) {
			ans[who] = cur_t + d[who];
			cur_t += d[who];
			who = -1;
		} else {
			return;
		}
	}

	while (ql < qr) {
		int i = Q[ql++];
		cur_t = max(cur_t, (ll) t[i]);
		if  (cur_t + d[i] > lim) {
			who = i;
			return;
		}
		ans[i] = cur_t + d[i];
		cur_t += d[i];
		who = -1;
	}
} 

void solve() {
	ql = qr = 0;
	who = -1;
	cur_t = 0;
	forn(i, n) {
		do_until(t[i]);

		if  (qr - ql == b) {
			ans[i] = -1;
			continue;
		}
	
		Q[qr++] = i;
	}

	do_until(1e18);

	forn(i, n) {
		printf("%lld ", ans[i]);
	}
	puts("");
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