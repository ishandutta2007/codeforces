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
const int MAX = 3e6 + 10;

int cnt[MAX];
int a[MAXN];
ll ans[MAX];
int n;

bool read() {
	if  (scanf("%d", &n) < 1) {
		return false;
	}
	// n = rand() % 20 + 2;
	// forn(i, n) {
	// 	a[i] = MAX - 100 + rand() % 3;
	// 	if  (rand() & 1) {
	// 		a[i] = rand() % 10 + 20;
	// 	}
	// }

	memset (cnt, 0, sizeof cnt);
	forn(i, n) {
		scanf("%d", &a[i]);
		++cnt[a[i]];
	}
	return true;
}

ll brut(int p) {
	ll res = 0;
	forn(x, n) forn(y, n) {
		if  (x != y && a[x] * 1ll * a[y] >= p) {
			++res;
		}
	}
	return res;
}

void solve() {
	memset (ans, 0, sizeof ans);
	for (int i = 1; i < MAX; ++i) {
		for (int j = 1; j * i < MAX && j <= i; ++j) {
			ll cur = cnt[i] * 1ll * cnt[j] * 2;
			if  (i == j) {
				cur = cnt[i] * 1ll * (cnt[i] - 1);
			}
			ans[j * i] += cur;
		}
	}

	sort(a, a + n);

	forn(i, n) {
		int j = lower_bound(a, a + n, (MAX + a[i] - 1) / a[i]) - a;
		j = max(j, i + 1);
		if  (j < n) {
			assert(a[i] * 1ll * a[j] >= MAX);
			ans[MAX - 1] += (n - j) * 2;
		}
	}

	ford(p, MAX - 1) {
		ans[p] += ans[p + 1];
	}

	// printf("a:\n");
	// forn(i, n) {
	// 	printf("%d ", a[i]);
	// }
	// puts("");

	int m;
	scanf("%d", &m);
	forn(i, m) {
		int p;
		scanf("%d", &p);
		// p = rand() % MAX + 1;
		// printf("p = %d\n", p);
		// printf("brut = %lld, my = %lld\n", brut(p), ans[p]);
		// assert(ans[p] == brut(p));
		printf("%lld\n", ans[p]);
	}
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