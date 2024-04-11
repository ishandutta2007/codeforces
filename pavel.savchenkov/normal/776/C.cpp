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

const int MAXN = 1e5 + 10;

int n, k;
int a[MAXN];

bool read() {
	if  (scanf("%d%d", &n, &k) < 2) {
		return 0;
	}
	forn(i, n) {
		scanf("%d", &a[i]);
	}
	return 1;
}

ll get(ll s) {
	map<ll, int> cnt;
	++cnt[0];
	ll pref = 0;
	ll ans = 0;
	forn(i, n) {
		pref += a[i];
		
		ll need = pref - s;
		ans += cnt[need];

		++cnt[pref];
	}

	return ans;
}

void solve() {
	ll ans = 0;
	ll cur = 1;
	for (int it = 0; ; ++it) {
		ans += get(cur);

		if  (abs(cur * k) > ll(1e16)) {
			break;
		}
		cur *= k;
		if  (k == 1 && it == 0) {
			break;
		}
		if  (k == -1 && it == 1) {
			break;
		}
	}

	printf("%lld\n", ans);
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