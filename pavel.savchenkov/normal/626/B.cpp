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

int cnt[3];

bool read() {
	int n;
	if  (scanf("%d\n", &n) < 1) {
		return false;
	}
	string s;
	getline(cin, s);
	memset (cnt, 0, sizeof cnt);
	for (char c : s) {
		if  (c == 'B') cnt[0]++;
		if  (c == 'G') cnt[1]++;
		if  (c == 'R') cnt[2]++;
	}
	return true;
}

const int MAXN = 3 * 200 + 4;

bool dp[MAXN][MAXN][MAXN];

void solve() {
	memset (dp, 0, sizeof dp);
	dp[cnt[0]][cnt[1]][cnt[2]] = 1;
	for (int s = MAXN - 1; s >= 0; --s) {
		for (int c1 = MAXN - 1; c1 >= 0; --c1) {
			for (int c2 = MAXN - 1; c2 >= 0; --c2) {
				int c3 = s - c2 - c1;
				if  (c3 < 0 || !dp[c1][c2][c3]) {
					continue;
				}
				if  (c1 >= 2) {
					dp[c1 - 1][c2][c3] = 1;
				} 
				if  (c2 >= 2) {
					dp[c1][c2 - 1][c3] = 1;
				}
				if  (c3 >= 2) {
					dp[c1][c2][c3 - 1] = 1;
				}
				if  (c1 && c2) {
					dp[c1 - 1][c2 - 1][c3 + 1] = 1;
				}
				if  (c1 && c3) {
					dp[c1 - 1][c2 + 1][c3 - 1] = 1;
				}
				if  (c2 && c3) {
					dp[c1 + 1][c2 - 1][c3 - 1] = 1;
				}
			}
		}
	}

	string ans;
	if  (dp[1][0][0]) {
		ans += "B";
	}
	if  (dp[0][1][0]) {
		ans += "G";
	}
	if  (dp[0][0][1]) {
		ans += "R";
	}
	sort(all(ans));
	cout << ans << endl;
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