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


const int MAXN = 2e5 + 10;
const int MOD = 1e9 + 7;

int mul(int x, int y) {
	return x * 1ll * y % MOD;
}

void add(int& x, int y) {
	((x += y) >= MOD) && (x -= MOD);
}

int mpow(int a, int p) {
	int res = 1;
	for (; p > 0; a = mul(a, a), p /= 2)
		if  (p & 1)
			res = mul(res, a);
	return res;
}

int fact[MAXN];
int inv_fact[MAXN];

void precalc() {
	fact[0] = 1;
	for (int i = 1; i < MAXN; ++i) {
		fact[i] = mul(fact[i - 1], i);
	}

	forn(i, MAXN) {
		inv_fact[i] = mpow(fact[i], MOD - 2);
	}
}

int C(int n, int k) {
	return mul(fact[n], mul(inv_fact[k], inv_fact[n - k]));
}

int l[MAXN];
int r[MAXN];
int n, k;

bool read() {
	if  (scanf("%d%d", &n, &k) < 2) {
		return false;
	}
	forn(i, n) {
		scanf("%d%d", &l[i], &r[i]);
	}
	return true;
}

struct Event {
	int aux;
	int x;

	bool operator < (const Event& e) const {
		return x < e.x;
	}
};
	

int solve() {
	vector<Event> es;
	forn(i, n) {
		es.pb(Event{+1, l[i]});
		es.pb(Event{-1, r[i] + 1});
	}

	sort(all(es));
	int bal = 0;
	int ans = 0;
	for (int i = 0, j; i + 1 < sz(es); i = j) {
		j = i;
		while (es[i].x == es[j].x) {
			bal += es[j].aux;
			++j;
		}

		if  (j == sz(es)) {
			break;
		}

		int len_x = es[j].x - es[i].x;
		// printf("bal = %d, len_x = %d\n", bal, len_x);
		if  (bal >= k) {
			add(ans, mul(len_x, C(bal, k)));
		}
	}

	return ans;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	precalc();

	while (read()) {
		printf("%d\n", solve());
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}