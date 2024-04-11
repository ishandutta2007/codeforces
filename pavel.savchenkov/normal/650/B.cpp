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

const int MAXN = 5e5 + 10;

bool turn[MAXN];
int sum[MAXN];
char s[MAXN];
int n, a, b, T;

bool read() {
	if  (scanf("%d%d%d%d\n", &n, &a, &b, &T) < 4) {
		return false;
	}
	gets(s);
	return true;
}

int get_sum(int l, int r) {
	return sum[r + 1] - sum[l];
}

int solve1() {
	forn(i, n) {
		turn[i] = (s[i] == 'w');
	}

	sum[0] = 0;
	forn(i, n) {
		sum[i + 1] = sum[i] + (turn[i] ? 1 : 0);
	}

	int ans = 0;
	forn(i, n) {
		ll have = i * 1ll * a + (i + 1) + b * 1ll * get_sum(0, i);
		if  (have > T) {
			break;
		}
		ans = max(ans, i + 1);

		int L = 0;
		int R = n - i;
		while (L != R - 1) {
			int len = (L + R) / 2;
			ll cur_have = have + (i + 1) * 1ll * a;
			cur_have += len;
			cur_have += (len - 1) * 1ll * a;
			cur_have += b * 1ll * get_sum(n - len, n - 1);
			if  (cur_have <= T) {
				L = len;
				ans = max(ans, (i + 1) + len);
			} else {
				R = len;
			}
		}
	}

	return ans;
}

int solve() {
	int ans = solve1();
	reverse(s + 1, s + n);
	return max(ans, solve1());
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