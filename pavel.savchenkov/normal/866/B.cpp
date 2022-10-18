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

struct Person {
	ll s, a, b;

	void read() {
		scanf("%lld%lld%lld", &s, &a, &b);
	}

	int cost() const {
		return a - b;
	}

	bool operator < (const Person& p) const {
		return cost() > p.cost();
	}
};

int n, s;
vector<Person> ps;

bool read() {
	if  (scanf("%d%d", &n, &s) < 2) {
		return 0;
	}
	ps.resize(n);
	forn(i, n) {
		ps[i].read();
	}
	return 1;
}

ll check(ll cnt) {
	// eprintf("check cnt = %lld\n", cnt);

	ll ans = 0;

	ll all = 0;
	forn(i, sz(ps)) {
		all += ps[i].s;
	}

	ll tail = (s - all % s) % s;

	ll good = cnt * s;

	if  (good >= all) {
		tail = 0;
	}

	ll got = 0;
	forn(i, sz(ps)) {
		ll now = good - got;
		if  (now < 0) {
			break;
		}

		if  (ps[i].cost() < 0 && tail > 0) {
			ll sw = min(now, tail);
			good -= sw;
			tail = 0;

			now = min(good - got, ps[i].s);;
		}
		if  (now < 0) {
			break;
		}
		now = min(now, ps[i].s);

		ans += now * ps[i].cost();

		got += now;
	}
	return ans;
}

ll solve() {
	sort(all(ps));

	ll got = 0;
	forn(i, sz(ps)) {
		if  (ps[i].cost() < 0) {
			break;
		}
		got += ps[i].s;
	}

	ll sum_b = 0;
	forn(i, sz(ps)) {
		sum_b += ps[i].b * 1ll * ps[i].s;
	}

	ll ans = 0;
	for (ll cnt = max(0ll, got / s - 10); cnt <= got / s + 10; ++cnt) {
		ans = max(ans, check(cnt));
	}

	// ans = max(ans, check(0) + sum_b);
	return ans + sum_b;
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