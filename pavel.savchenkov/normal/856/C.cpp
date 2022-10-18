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
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define all(C) begin(C), end(C)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;

#ifdef LOCAL
#define eprintf(args...) fprintf(stderr, args), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define FILE_NAME "a"

const int MOD = 998244353;

void add(int& x, int y) {
	((x += y) >= MOD) && (x -= MOD);
}

int mul(int x, int y) {
	return x * 1ll * y % MOD;
}

const int M = 11;

void addM(int& x, int y) {
	((x += y) >= M) && (x -= M);
}

void subM(int& x, int y) {
	addM(x, -y + M);
}

vi repr(int a) {
	vi res;
	while (a) {
		res.pb(a % 10);
		a /= 10;
	}
	assert(!res.empty());
	reverse(all(res));
	return res;
}

pii convert(int a) {
	vi digs = repr(a);

	pii res;
	res.fst = sz(digs) & 1;

	forn(i, sz(digs)) {
		if  (i & 1) {
			subM(res.snd, digs[i]);
		} else {
			addM(res.snd, digs[i]);
		}
	}

	return res;
}

int n;
vi odd;
vi even;

bool read() {
	if  (scanf("%d", &n) < 1) {
		return 0;
	}
	odd.clear();
	even.clear();
	forn(i, n) {
		int a;
		scanf("%d", &a);
		auto conv = convert(a);
		if  (conv.fst) {
			odd.pb(conv.snd);
		} else {
			even.pb(conv.snd);
		}
	}
	return 1;
}

vi calc1() {
	const int all_even_poses = sz(odd) / 2;
	const int all_odd_poses = sz(odd) - all_even_poses;

	vvi dp(all_even_poses + 1, vi(M, 0));
	dp[0][0] = 1;
	forn(i, sz(odd) + 1) {
		vvi ndp(all_even_poses + 1, vi(M, 0));

		forn(used_even, all_even_poses + 1) {
			const int used_odd = i - used_even;
			forn(rem, M) {
				const int cur_dp = dp[used_even][rem];
				if  (!cur_dp) {
					continue;
				}
				assert(used_odd >= 0);
				assert(used_odd <= all_odd_poses);

				// eprintf("i = %d, used_even = %d, used_odd = %d, rem = %d, cur_dp = %d\n", i, used_even, used_odd, rem, cur_dp);

				if  (i == sz(odd)) {
					continue;
				}

				// put to even
				if  (used_even < all_even_poses) {
					int nrem = rem;
					addM(nrem, odd[i]);
					assert(0 <= nrem && nrem < M);
					add(ndp[used_even + 1][nrem], mul(cur_dp, all_even_poses - used_even));
				}

				// put to odd
				if  (used_odd < all_odd_poses) {
					int nrem = rem;
					subM(nrem, odd[i]);
					assert(0 <= nrem && nrem < M);
					add(ndp[used_even][nrem], mul(cur_dp, all_odd_poses - used_odd));
				}
			}
		}

		if  (i == sz(odd)) {
			break;
		}

		dp.swap(ndp);
	}

	return dp[all_even_poses];
}

int calc2(const vi& dyn1) {
	const int max_places = sz(odd) + sz(even) + 1;

	vvi dp(max_places + 1, vi(M, 0));
	forn(rem, M) {
		dp[sz(odd) / 2 + 1][rem] = dyn1[rem];
	}

	forn(i, sz(even)) {
		const int cur_places = sz(odd) + i + 1;
		vvi ndp(max_places + 1, vi(M, 0));

		forn(even_places, max_places + 1) {
			const int odd_places = cur_places - even_places;

			forn(rem, M) {
				const int cur_dp = dp[even_places][rem];
				if  (!cur_dp) {
					continue;
				}

				// eprintf("i = %d, even_places = %d, rem = %d, odd_places = %d\n", i, even_places, rem, odd_places);

				assert(even_places > 0);
				assert(odd_places >= 0);

				// to even place
				if  (even_places) {
					int nrem = rem;
					addM(nrem, even[i]);
					add(ndp[even_places + 1][nrem], mul(cur_dp, even_places));
				}

				// to odd place
				{
					int nrem = rem;
					subM(nrem, even[i]);
					add(ndp[even_places][nrem], mul(cur_dp, odd_places));
				}
			}
		}
	
		dp.swap(ndp);
	}

	int ans = 0;
	forn(i, sz(dp)) {
		add(ans, dp[i][0]);
	}

	return ans;
}

int solve() {
	// eprintf("even:\n");
	// for (int e : even) {
	// 	eprintf("%d ", e);
	// }
	// eprintf("\n");

	// eprintf("odd:\n");
	// for (int o : odd) {
	// 	eprintf("%d ", o);
	// }
	// eprintf("\n");

	vi dyn1 = calc1();

	// eprintf("dyn1:\n");
	// forn(i, sz(dyn1)) {
	// 	eprintf("%d -> %d\n", i, dyn1[i]);
	// }

	int ans = calc2(dyn1);

	return ans;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	forn(t, T) {
		assert(read());
		printf("%d\n", solve());
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}