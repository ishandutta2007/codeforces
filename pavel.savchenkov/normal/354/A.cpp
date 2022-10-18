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
const int INF = 2e9 + 10;

int w[MAXN];
int l, r;
int ql, qr;
int n;

bool read() {
	if  (scanf("%d", &n) < 1) {
		return false;
	}
	scanf("%d%d%d%d", &l, &r, &ql, &qr);
	forn(i, n) {
		scanf("%d", &w[i]);
	}
	return true;
}

int get(int cl, int cr, int ql, int qr) {
	if  (cl < cr) {
		swap(cl, cr);
		swap(ql, qr);
	}
	return ql * max(0, cl - cr - 1);
}

int solve() {
	int ans = INF;

	int left = 0;
	int right = accumulate(w, w + n, 0);
	int cnt_left = 0;
	int cnt_right = n;
	forn(i, n) {
		ans = min(ans, get(cnt_left, cnt_right, ql, qr) + left * l + right * r);
		
		++cnt_left;
		--cnt_right;
		left += w[i];
		right -= w[i];
	}

	ans = min(ans, get(cnt_left, cnt_right, ql, qr) + left * l + right * r);

	return ans;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		printf("%d\n", solve());
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}