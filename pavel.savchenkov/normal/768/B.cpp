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


ll n, l, r;

bool read() {
	if  (!(cin >> n >> l >> r)) {
		return 0;
	}
	return 1;
}

ll len(ll x) {
	if  (x <= 1) {
		return 1;
	}
	return 1 + 2 * len(x / 2);
}

map<pair<pll, ll>, ll> mem;

ll get(ll x, ll l, ll r) {
	l = max(l, 0ll);
	ll L = len(x);
	r = min(r, L - 1);
	if  (l > r) {
		return 0;
	}

	if  (x <= 1) {
		return x == 1 && l <= 0 && 0 <= r;
	}

	pair<pll, ll> C{{x, l}, r};
	if  (mem.count(C)) {
		return mem[C];
	}

	assert(L > 1);
	assert(L & 1);
	ll mid = L / 2;
	return (mem[C] = (get(x / 2, l, r) + (x % 2 == 1 && l <= mid && mid <= r) + get(x / 2, l - (mid + 1), r - (mid + 1))));
}

ll solve() {
	--l;
	--r;
	return get(n, l, r);
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