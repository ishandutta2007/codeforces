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

const int MAXN = 2e5 + 10;

int need;
int h, m;

bool read() {
	if  (scanf("%d", &need) < 1) {
		return false;
	}
	scanf("%d:%d", &h, &m);
	return true;
}

void solve() {
	int ans = 10;
	int H = -1;
	int M = -1;
	for (int hh = 0; hh < 24; ++hh) {
		for (int mm = 0; mm < 60; ++mm) {
			if  (need == 12 && !(1 <= hh && hh <= 12)) {
				continue;
			}
			int cur = (hh / 10) != (h / 10);
			cur += (hh % 10) != (h % 10);
			cur += (mm / 10) != (m / 10);
			cur += (mm % 10) != (m % 10);
			if  (cur < ans) {
				ans = cur;
				H = hh;
				M = mm;
			}
		}
	}
	// printf("ans = %d\n", ans);
	printf("%02d:%02d\n", H, M);
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