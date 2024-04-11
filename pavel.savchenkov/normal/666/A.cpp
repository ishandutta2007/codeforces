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


const int MAXN = 1e5 + 10;

const int lens[2] = {2, 3};

char s[MAXN];
int n;
bool dp[MAXN][2];

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	gets(s);
	n = strlen(s);

	memset (dp, false, sizeof dp);
	forn(i, 2) {
		dp[n][i] = false;
	}
	vector<string> res;
	ford(i, n) {
		if  (i <= 4) {
			break;
		}
		forn(c1, 2) {
			int l = i;
			int r = l + lens[c1] - 1;
			if  (r == n - 1) {
				dp[i][c1] = true;
				res.pb(string(s + l, s + r + 1));
			}
			forn(c2, 2) {
				int L = r + 1;
				int R = L + lens[c2] - 1;
				if  (R >= n) {
					continue;
				}
				if  (!dp[L][c2]) {
					continue;
				}
				if  (c1 == c2 && string(s + l, s + r + 1) == string(s + L, s + R + 1)) {
					continue;
				}
				res.pb(string(s + l, s + r + 1));
				dp[i][c1] = true;
			}
		}
	}

	sort(all(res));
	res.resize(unique(all(res)) - res.begin());
	printf("%d\n", sz(res));
	for (const auto& r : res) {
		printf("%s\n", r.data());
	}

	return 0;
}
//