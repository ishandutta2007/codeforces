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


const int MAXN = 1e5 + 10;
const ll INF = 1e18;

string s[MAXN];
string rs[MAXN];
int c[MAXN];
int n;

string reads() {
	static char t[MAXN];
	gets(t);
	return string(t);
}

bool read() {
	if  (scanf("%d", &n) < 1) {
		return false;
	}
	forn(i, n) {
		scanf("%d", &c[i]);
	}
	scanf("\n");
	forn(i, n) {
		s[i] = reads();
	}
	return true;
}

ll dp[MAXN][2];

ll solve() {
	forn(i, n) {
		rs[i] = s[i];
		reverse(all(rs[i]));
	}

	dp[0][0] = 0;
	dp[0][1] = c[0];
	for (int i = 1; i < n; ++i) {
		forn(r, 2) dp[i][r] = INF;
		forn(pr, 2) {
			forn(r, 2) {
				const string& prev = (pr ? rs[i - 1] : s[i - 1]);
				const string& cur = (r ? rs[i] : s[i]);
				if  (prev <= cur) {
					dp[i][r] = min(dp[i][r], dp[i - 1][pr] + (r ? c[i] : 0));
				}
			}
		}
	}

	ll ans = INF;
	forn(r, 2) {
		ans = min(ans, dp[n - 1][r]);
	}

	if  (ans >= INF) {
		return -1;
	}
	return ans;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		cout << solve() << '\n';
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}