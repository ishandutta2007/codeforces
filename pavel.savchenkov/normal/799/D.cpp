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

#define FILE_NAME "a"


int a, b, h, w, n;
vi q;

bool read() {
	if  (scanf("%d%d%d%d%d", &a, &b, &h, &w, &n) < 5) {
		return 0;
	}
	q.resize(n);
	forn(i, n) {
		scanf("%d", &q[i]);
	}
	return 1;
}

const int INF = 1e9;
const ll INF_LL = 1e18;

ll mult(ll a, ll b) {
	if  (!a || !b) {
		return 0;
	}
	if  (a >= INF_LL || b >= INF_LL) {
		return INF_LL;
	}
	if  (a >= INF_LL / b) {
		return INF_LL;
	}
	return min(INF_LL, a * b);
}

vll gen_prod(const vi& q, const vi& ids) {
	vll res;
	forn(mask, 1 << sz(ids)) {
		ll cur = 1;
		forn(i, sz(ids)) {
			if (mask & (1 << i)) {
				cur = mult(cur, q[ids[i]]);
			}
		}
		res.pb(cur);
	}
	sort(all(res));
	return res;
}

bool can(int h, int w, int a, int b, const vi& q, int pref) {
	if  (h >= a && w >= b) {
		return 1;
	}

	if  (pref >= 18 * 2) {
		return 1;
	}

	ll P = 1;
	forn(i, pref) {
		P = mult(P, q[i]);
	}

	if  (P >= INF_LL) {
		return 1;
	}

	const ll low = (a + (h - 1)) / h;


	vi left;
	vi right;
	int mid = pref / 2;
	forn(i, pref) {
		if  (i <= mid) {
			left.pb(i);
		} else {
			right.pb(i);
		}
	}

	ll LEFT = 1;
	for (int i : left) {
		LEFT = mult(LEFT, q[i]);
	}
	if  (LEFT >= INF_LL) {
		return 1;
	}

	ll RIGHT = 1;
	for (int i : right) {
		RIGHT = mult(RIGHT, q[i]);
	}

	auto left_prod = gen_prod(q, left);
	auto right_prod = gen_prod(q, right);

	for (const auto& L : left_prod) {
		// L * R >= low
		ll low_R = (low + (L - 1)) / L;

		int pos = lower_bound(all(right_prod), low_R) - right_prod.begin();
		if  (pos < sz(right_prod)) {
			ll R = right_prod[pos];

			assert(mult(h, mult(L, R)) >= a);

			ll L2 = LEFT / L;
			ll R2 = RIGHT / R;

			if  (mult(w, mult(L2, R2)) >= b) {
				return 1;
			}
		}
	}

	return 0;
}

int solve(int h, int w, int a, int b, const vi& q) {
	int L = -1;
	int R = sz(q) + 1;
	while (L != R - 1) {
		int M = (L + R) >> 1;
		if  (can(h, w, a, b, q, M)) {
			R = M;
		} else {
			L = M;
		}
	}
	if  (R == sz(q) + 1) {
		return INF;
	}
	return R;
}

int solve() {
	sort(all(q));
	reverse(all(q));

	int ans = INF;
	ans = min(ans, solve(h, w, a, b, q));
	ans = min(ans, solve(w, h, a, b, q));
	if  (ans >= INF) {
		ans = -1;
	}
	return ans;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		cout << solve() << endl;
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}