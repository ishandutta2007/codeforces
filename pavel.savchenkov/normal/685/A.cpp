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


const int MAXN = 1e5 + 10;
const int B = 7;

vi convert(int n) {
	vi res;
	while (n) {
		res.pb(n % B);
		n /= B;
	}
	if  (res.empty()) {
		res.pb(0);
	} 
	reverse(all(res));
	return res;
}

int dp[40][2][(1 << B) + 5];

vi calc(int n) {
	vi nn = convert(n);

	// for (int d : nn) {
	// 	printf("%d ", d);
	// }
	// puts("");

	memset (dp, 0, sizeof dp);
	dp[0][1][0] = 1;
	forn(i, sz(nn)) forn(eq, 2) forn(mask, 1 << B) {
		int cur_dp = dp[i][eq][mask];
		if  (!cur_dp) {
			continue;
		}
		forn(nxt, B) {
			if  (eq && nxt > nn[i]) {
				continue;
			}
			if  (mask & (1 << nxt)) {
				continue;
			}
			int neq = eq && (nxt == nn[i]);
			int nmask = mask | (1 << nxt);
			dp[i + 1][neq][nmask] += cur_dp;
		}
	}

	vi res(1 << B, 0);
	forn(mask, 1 << B) forn(eq, 2) {
		res[mask] += dp[sz(nn)][eq][mask];
		// if  (res[mask]) {
		// 	cout << "res[" << bitset<B>(mask) << "] = " << res[mask] << endl;
		// }
	}

	return res;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;

	vi dp_n = calc(n - 1);
	vi dp_m = calc(m - 1);

	ll ans = 0;
	forn(mask_n, 1 << B) forn(mask_m, 1 << B) {
		if  ((mask_n & mask_m) == 0) {
			ans += dp_n[mask_n] * 1ll * dp_m[mask_m];
		}	
	}

	cout << ans << endl;

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}