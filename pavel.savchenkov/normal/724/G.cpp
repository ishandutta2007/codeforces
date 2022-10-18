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
const int MOD = 1e9 + 7;

void add(int& x, int y) {
	((x += y) >= MOD) && (x -= MOD);
}

int mul(int x, int y) {
	return x * 1ll * y % MOD;
}

int n, m;
vector<pair<int, ll>> g[MAXN];

bool read() {
	if  (scanf("%d%d", &n, &m) < 2) {
		return false;
	}
	forn(i, n) {
		g[i].clear();
	}
	forn(i, m) {
		int a, b;
		ll c;
		scanf("%d%d%lld", &a, &b, &c);
		--a;
		--b;
		g[a].pb(mp(b, c));
		g[b].pb(mp(a, c));
	}
	return true;
}

bool bit(ll mask, int i) {
	return (mask >> i) & 1;
}

ll pref[MAXN];
bool was[MAXN];

void dfs(int v, int p, ll pr, vll& vals, vi& vs) {
	pref[v] = pr;
	was[v] = true;
	vs.pb(v);
	for (const auto& e : g[v]) {
		int to = e.fst;
		if (to == p) {
			continue;
		}
		ll c = e.snd;
		if  (was[to]) {
			vals.pb(pref[to] ^ pref[v] ^ c);
			continue;
		}
		dfs(to, v, pr ^ c, vals, vs);
	}
}

int mpow(int a, int p) {
	int res = 1;
	for (; p > 0; p >>= 1, a = mul(a, a)) {
		if  (p & 1) {
			res = mul(res, a);
		}
	}
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
	return mul(fact[n], mul(inv_fact[n - k], inv_fact[k]));
}

pair<vi, vi> get_mask(vll a) {
	// for (auto x : a) {
	// 	printf("%lld ", x);
	// }
	// puts("");
	vi cnt0(64, 0);
	vi cnt1(64, 0);
	int rank = 0;
	for (int row = 0, col = 0; row < 64 && col < sz(a); ++row) {
		for (int i = col + 1; i < sz(a); ++i) {
			if  (bit(a[i], row)) {
				swap(a[i], a[col]);
				break;
			}
		}
		if  (!bit(a[col], row)) {
			continue;
		}
		++rank;
		for (int i = col + 1; i < sz(a); ++i) {
			if  (bit(a[i], row)) {
				a[i] ^= a[col];
			}
		}
		forn(j, 64) {
			if  (bit(a[col], j)) {
				++cnt1[j];
			} else {
				++cnt0[j];
			}
		}
		++col;
	}
	vi mask0(64, 0);
	vi mask1(64, 0);
	forn(i, 64) {
		for (int c1 = 1; c1 <= cnt1[i]; c1 += 2) {
			add(mask1[i], (1ll << cnt0[i]) % MOD * 1ll * C(cnt1[i], c1) % MOD);
		}
		for (int c1 = 0; c1 <= cnt1[i]; c1 += 2) {
			add(mask0[i], (1ll << cnt0[i]) % MOD * 1ll * C(cnt1[i], c1) % MOD);
		}
	}
	return mp(mask0, mask1);
}

int solve_comp(int r) {
	vll vals;
	vi vs;
	dfs(r, -1, 0, vals, vs);
	sort(all(vals));
	vals.resize(unique(all(vals)) - vals.begin());
	// {
	// 	puts("vals:");
	// 	for (auto vv : vals) {
	// 		printf("%lld ", vv);
	// 	}
	// 	puts("");
	// }
	vi mask0, mask1;
	tie(mask0, mask1) = get_mask(vals);

	// printf("masks:\n");
	// forn(i, 10) {
	// 	printf("cnt: %d %d\n", mask0[i], mask1[i]);
	// }

	// printf("r=%d\n", r);
	// {
	// 	printf("prefs:\n");
	// 	for (int v : vs) {
	// 		printf("pref[%d] = %lld\n", v, pref[v]);
	// 	}
	// 	puts("");
	// }

	map<ll, int> cnt_pref;
	vll prefs;
	for (int v : vs) {
		prefs.pb(pref[v]);
		++cnt_pref[pref[v]];
	}
	sort(all(prefs));
	// prefs.resize(unique(all(prefs)) - prefs.begin());

	vvi cnt_bit(64, vi(2, 0));
	for (const auto& p : prefs) {
		forn(i, 64) {
			++cnt_bit[i][bit(p, i)];
		} 
	}

	// forn(i, 10) {
	// 	printf("cnt_bit: %d %d\n", cnt_bit[i][0], cnt_bit[i][1]);
	// }

	int ans = 0;
	for (int v : vs) {
		{
			auto p = pref[v];
			forn(i, 64) {
				--cnt_bit[i][bit(p, i)];
			}
		}
		// ---------

		forn(i, 64) {
			auto p = pref[v];
			forn(other, 2) {
				int b = bit(p, i) ^ other;
				int cnt_b = cnt_bit[i][other];
				forn(basis, 2) {
					int B = b ^ basis;
					if  (!B) {
						continue;
					}
					int cnt_B = mul(cnt_b, basis ? mask1[i] : mask0[i]);
					add(ans, mul(cnt_B, (1ll << i) % MOD));
				}
			}
		}

		// // ----------
		{
			auto p = pref[v];
			forn(i, 64) {
				++cnt_bit[i][bit(p, i)];
			}
		}
	}

	return ans;
}

int solve() {
	memset (was, false, sizeof was);
	int ans = 0;
	forn(i, n) {
		if  (!was[i]) {
			int cur = solve_comp(i);
			add(ans, cur);
			// printf("cur ans = %d\n", cur);
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
		printf("%d\n", mul(solve(), mpow(2, MOD - 2)));
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}