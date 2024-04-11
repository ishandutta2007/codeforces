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

const ll INF = 2e18;

int n, m;
int x, y;
ll k;

bool read() {
	if  (scanf("%d%d", &n, &m) < 2) {
		return 0;
	}
	scanf("%lld", &k);
	scanf("%d%d", &x, &y);
	--x;
	--y;
	return 1;
}

ll get(int i, int j, ll k) {
	ll in_pref = n * m + max(0, (n - 2)) * m;
	ll pref = k / in_pref;
	k -= pref * in_pref;

	assert(k < in_pref);

	ll res = (i * m + j + 1) <= k;
	if  (k > n * m && i > 0 && i + 1 < n && n > 2) {
		res += ((n - i - 2) * m + j + 1) <= k - n * m;
	}

	res += (0 < i && i + 1 < n) ? pref * 2 : pref;

	return res;
}

ll mx;
ll mn;

void check(int i, int j) {
	if  (!(0 <= i && i < n && 0 <= j && j < m)) {
		return;
	}
	ll cur = get(i, j, k);
	mx = max(mx, cur);
	mn = min(mn, cur);
}

void solve() {
	mx = -INF;
	mn = INF;

	check(0, 0);
	check(1, 0);
	check(n - 1, 0);
	check(n - 2, 0);

	check(0, m - 1);
	check(1, m - 1);
	check(n - 1, m - 1);
	check(n - 2, m - 1);

	cout << mx << " ";
	cout << mn << " ";
	cout << get(x, y, k) << endl;
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