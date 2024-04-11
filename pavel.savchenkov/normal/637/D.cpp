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

void NO() {
	puts("IMPOSSIBLE");
	exit(0);
}

int main() {
#ifdef DEBUG
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	int n, m, s, d;
	scanf("%d%d%d%d\n", &n, &m, &s, &d);

	if  (d <= 1) {
		NO();
	}

	vi a(n);
	forn(i, n) {
		scanf("%d", &a[i]);
	}

	a.pb(-1);
	sort(all(a));
	n = sz(a);

	vector<char> can_after(n, true);
	forn(i, n - 1) {
		if  (a[i + 1] - a[i] < 2 + s) {
			can_after[i] = false;
		}
	}

	vector<char> dp(n, false); // dp[i] -- could land after i-th obstacle
	vi prev(n, -1);

	int j = -1;
	dp[0] = can_after[0];
	if  (dp[0]) {
		j = 0;
	}
	// last j | dp[j] = true
	for (int i = 1; i < n; ++i) {
		assert(j < i);
		if  (can_after[i]) {
			int x = a[i] + 1;
			int low_x = x - d;
			if  (j != -1 && (a[j] >= low_x || (a[j] < low_x && a[j + 1] > low_x))) {
				dp[i] = true;
				prev[i] = j;
				j = i;
			}
		}
	}

	if  (!dp[n - 1]) {
		NO();
	}

	vi order;
	int i = n - 1;
	while (i != -1) {
		order.pb(i);
		i = prev[i];
	}
	reverse(all(order));

	assert(order[0] == 0);
	forn(i, sz(order) - 1) {
		int x = a[order[i]] + 1;
		int need_x = a[order[i + 1]] + 1;
		assert(dp[order[i]]);
		assert((a[order[i] + 1] - 1) - x >= s);
		printf("RUN %d\n", (a[order[i] + 1] - 1) - x);
		assert(need_x - (a[order[i] + 1] - 1) <= d);
		printf("JUMP %d\n", need_x - (a[order[i] + 1] - 1));
	}

	int x = a[order.back()] + 1;
	if  (x < m) {
		printf("RUN %d\n", m - x);
	}

	return 0;
}