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
const int INF = 1e9;

int n;
int a[MAXN];

bool read() {
	if  (scanf("%d", &n) < 1) {
		return false;
	}
	forn(i, n) {
		scanf("%d", &a[i]);
		--a[i];
	}
	return true;
}

int dp[MAXN];
int Q[MAXN];
int ql, qr;

void solve() {
	forn(i, n) {
		dp[i] = INF;
	}
	dp[0] = 0;
	ql = qr = 0;
	Q[qr++] = 0;
	while (ql != qr) {
		int v = Q[ql++];
		if  (v > 0 && dp[v - 1] > dp[v] + 1) {
			dp[v - 1] = dp[v] + 1;
			Q[qr++] = v - 1;
		}
		if  (v + 1 < n && dp[v + 1] > dp[v] + 1) {
			dp[v + 1] = dp[v] + 1;
			Q[qr++] = v + 1;
		}
		if  (dp[a[v]] > dp[v] + 1) {
			dp[a[v]] = dp[v] + 1;
			Q[qr++] = a[v];
		}
	}

	forn(i, n) {
		printf("%d ", dp[i]);
	}
	puts("");
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		solve();
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}