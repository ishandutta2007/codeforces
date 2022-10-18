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


const int MAXN = 5e5 + 10;
const int MAXC = 1e7 + 10;
const int MOD = 1e9 + 7;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

void add(int& x, int y) {
	((x += y) >= MOD) && (x -= MOD);
}

int mul(int x, int y) {
	return x * 1ll * y % MOD;
}

int pow2[MAXN];

int lp[MAXC];
vi pr;
int mu[MAXC];

void precalc() {
	memset (lp, -1, sizeof lp);
	lp[1] = 1;
	for (int x = 2; x < MAXC; ++x) {
		if  (lp[x] == -1) {
			lp[x] = x; 
			pr.pb(x);
		}
		for (int i = 0; i < sz(pr) && pr[i] <= lp[x] && pr[i] * x < MAXC; ++i) {
			lp[pr[i] * x] = pr[i];
		}
	}

	pow2[0] = 1;
	for (int i = 1; i < MAXN; ++i) {
		pow2[i] = mul(2, pow2[i - 1]);
	}

	mu[1] = 1; // ?
	for (int x = 2; x < MAXC; ++x) {
		int y = x;
		bool sq_free = true;
		int primes = 0;
		while (y > 1) {
			if  ((y / lp[y]) % lp[y] == 0) {
				sq_free = false;
				break;
			}
			y /= lp[y];
			++primes;
		}
		if  (!sq_free) {
			mu[x] = 0;
			continue;
		}
		if  (primes & 1) {
			mu[x] = -1;
		} else {
			mu[x] = +1;
		}
	}
}

int cnt[MAXC];
int cnt_up[MAXC];
int cnt_up_divs[MAXC];
int a[MAXN];
int n;

bool read() {
	if  (scanf("%d", &n) < 1) {
		return false;
	}
	forn(i, n) {
		scanf("%d", &a[i]);
	}
	return true;
}

int brut_with1() {
	int ans = 0;
	forn(mask, 1 << n) {
		int g = 0;
		forn(i, n) {
			if  (mask & (1 << i)) {
				g = gcd(g, a[i]);
			}
		}
		ans += (g == 1);
	}
	return ans;
}

int subsets_with1;

vi get_ps(int x) {
	vi ps;
	while (x > 1) {
		int p = lp[x];
		ps.pb(p);
		while (x % p == 0) {
			x /= p;
		}
	}
	return ps;
}

int solve(int x) {
	int all_with1 = subsets_with1;

	int without_me_with1 = all_with1;
	vi ps = get_ps(x); 
	forn(mask, 1 << sz(ps)) {
		int d = 1;
		forn(i, sz(ps)) {
			if  (mask & (1 << i)) {
				d *= ps[i];
			}
		}

		assert(mu[d]);

		add(without_me_with1, -mul(cnt_up[d], mu[d]) + MOD);
		int new_cnt_up_divs = cnt_up_divs[d] - 1;
		int new_cnt_up = pow2[new_cnt_up_divs];
		add(new_cnt_up, -1 + MOD);
		add(without_me_with1, mul(new_cnt_up, mu[d]));
	}

	int all = pow2[n];
	add(all, -all_with1 + MOD);
	
	int all_without = pow2[n - 1];
	add(all_without, -without_me_with1 + MOD);

	int with_me_with1 = all_with1;
	add(with_me_with1, -without_me_with1 + MOD);

	int res = with_me_with1;
	add(res, -without_me_with1 + MOD);
	return res;
}

int solve() {
	memset (cnt, 0, sizeof cnt);
	forn(i, n) {
		++cnt[a[i]];
	}

	for (int d = 1; d < MAXC; ++d) {
		cnt_up[d] = 0;
		for (int x = d; x < MAXC; x += d) {
			cnt_up[d] += cnt[x];
		}
		cnt_up_divs[d] = cnt_up[d];
		cnt_up[d] = pow2[cnt_up[d]];
		add(cnt_up[d], -1 + MOD);
	}

	// int with1 = 0;
	// for (int d = 1; d < MAXC; ++d) {
	// 	if  (!mu[d]) {
	// 		continue;
	// 	}
	// 	int Mu = (mu[d] == 1) ? 1 : (-1 + MOD);
	// 	add(with1, mul(cnt_up[d], Mu));
	// }
	// printf("my with1 = %d\n", with1);
	// printf("brut with1 = %d\n", brut_with1());
	// return 0;

	subsets_with1 = 0;
	for (int d = 1; d < MAXC; ++d) {
		if  (!mu[d]) {
			continue;
		}
		if  (mu[d] < 0) mu[d] += MOD;
		add(subsets_with1, mul(cnt_up[d], mu[d]));
	}

	int ans = 0;
	forn(i, n) {
		add(ans, solve(a[i]));
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