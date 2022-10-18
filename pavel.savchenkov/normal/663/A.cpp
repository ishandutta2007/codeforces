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

int op[MAXN];
ll mx[MAXN];
ll mn[MAXN];
int len;
int n;
int ans[MAXN];

void read() {
	len = 0;
	char c;
	op[len++] = 1;
	while ((c = getchar()) != '=') {
		if  (c == '+') {
			op[len++] = 1;
		} else if  (c == '-') {
			op[len++] = -1;
		}
	}
	scanf("%d", &n);
}

void restore(int pos, int val) {
	if  (!pos) {
		return;
	}

	assert(mn[pos] <= val && val <= mx[pos]);
	if  (op[pos - 1] == 1) {
		// mn[pos - 1] <= val - x <= mx[pos - 1]
		// l <= val - x <= r
		// l <= val - x => x <= val - l
		// val - x <= r => val - r <= x
		ll l = mn[pos - 1];
		ll r = mx[pos - 1];
		ll rx = val - l;
		ll lx = val - r;
		lx = max(lx, 1ll);
		rx = min(rx, n * 1ll);
		assert(lx <= rx);
		ans[pos - 1] = lx;
		restore(pos - 1, val - lx);
	} else {
		// mn[pos - 1] <= val + x <= mx[pos - 1]
		// l <= val + x <= r
		// l <= val + x => l - val <= x
		// val + x <= r => x <= r - val
		ll l = mn[pos - 1];
		ll r = mx[pos - 1];
		ll rx = r - val;
		ll lx = l - val;
		lx = max(lx, 1ll);
		rx = min(rx, n * 1ll);
		assert(lx <= rx);
		ans[pos - 1] = lx;	
		restore(pos - 1, val + lx);
	}
}

int main() {
#ifdef DEBUG
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	read();

	mn[0] = mx[0] = 0;
	forn(i, len) {
		mn[i + 1] = mn[i];
		mx[i + 1] = mx[i];
		if  (op[i] == 1) {
			mn[i + 1] += 1;
			mx[i + 1] += n;
		} else {
			mn[i + 1] -= n;
			mx[i + 1] -= 1;
		}
	}

	if  (!(mn[len] <= n && n <= mx[len])) {
		puts("Impossible");
		return 0;
	}

	puts("Possible");

	restore(len, n);

	forn(i, len) {
		if  (i) {
			if  (op[i] == 1) {
				printf(" + ");
			} else {
				printf(" - ");
			}
		}
		printf("%d", ans[i]);
	}
	printf(" = %d\n", n);

	return 0;
}