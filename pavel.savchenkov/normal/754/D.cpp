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
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;

#define FILE_NAME "a"

const int MAXN = 3e5 + 10;

int n, k;
int l[MAXN];
int r[MAXN];

bool read() {
	if  (scanf("%d%d", &n, &k) < 2) {
		return 0;
	}
	forn(i, n) {
		scanf("%d%d", &l[i], &r[i]);
	}
	return 1;
}

vi ans;
vi by_l;
vi by_r;

struct Event {
	ll x;
	int coef;

	bool operator < (const Event& e) const {
		return x < e.x;
	}
};

bool can(ll len) {
	assert(len >= 0);
	if  (len == 0) {
		return 1;
	}

	vector<Event> es1;
	for (int i : by_l) {
		if  (r[i] - l[i] + 1 < len) {
			continue;
		}
		es1.pb(Event{l[i], +1});
	}

	vector<Event> es2;
	for (int i : by_r) {
		if  (r[i] - l[i] + 1 < len) {
			continue;
		}
		es2.pb(Event{r[i] - len + 2, -1});
	}
	
	vector<Event> es;
	es.resize(sz(es1) + sz(es2));
	merge(all(es1), all(es2), es.begin());

	ll best_x = 0;
	bool was_best = 0;
	int bal = 0;
	for (int i = 0, j = 0; i < sz(es); i = j) {
		while (j < sz(es) && es[i].x == es[j].x) {
			++j;
		}

		for (int z = i; z < j; ++z) {
			bal += es[z].coef;
		}

		if  (bal >= k) {
			was_best = 1;
			best_x = es[i].x;
			break;
		}
	}

	if  (!was_best) {
		return 0;
	}
	ll left = best_x;
	ll right = left + len - 1;
	ans.clear();
	forn(i, n) {
		if  (l[i] <= left && right <= r[i]) {
			ans.pb(i);
		}
	}
	assert(sz(ans) >= k);
	return 1;
}

void precalc() {
	by_r.resize(n);
	iota(all(by_r), 0);
	sort(all(by_r), [&](int i, int j) { return r[i] < r[j]; });

	by_l.resize(n);
	iota(all(by_l), 0);
	sort(all(by_l), [&](int i, int j) { return l[i] < l[j]; });
}

void solve() {
	precalc();

	ll L = -1;
	ll R = 4e9;
	while (L != R - 1) {
		ll M = (L + R) / 2;
		if  (can(M)) {
			L = M;
		} else {
			R = M;
		}
	}

	if  (L <= 0) {
		puts("0");
		forn(i, k) {
			printf("%d ", i + 1);
		}
		puts("");
		return;
	}

	assert(can(L));
	printf("%lld\n", L);
	assert(sz(ans) >= k);
	ans.resize(k);
	for (int i : ans) {
		printf("%d ", i + 1);
	} 
	puts("");
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