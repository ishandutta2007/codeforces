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

const int MAXN = 1e5 + 10;

int n, m;
int bounty, increase, damage;
int max_health[MAXN];
int start_health[MAXN];
int regen[MAXN];
vii events[MAXN];

bool read() {
	if  (scanf("%d%d", &n, &m) < 2) {
		return 0;
	}
	forn(i, n) {
		events[i].clear();
	}
	scanf("%d%d%d", &bounty, &increase, &damage);
	forn(i, n) {
		scanf("%d%d%d", &max_health[i], &start_health[i], &regen[i]);
	}
	forn(i, m) {
		int t, e, h;
		scanf("%d%d%d", &t, &e, &h);
		--e;
		events[e].pb(mp(t, h));
	}
	return 1;
}

const ll INF = 1e18;

ll solve() {
	forn(i, n) {
		events[i].pb(mp(0, start_health[i]));
		sort(all(events[i]));
	}

	vector<pll> segs;
	forn(i, n) {
		const int mx = max_health[i];
		const int per_sec = regen[i];

		forn(j, sz(events[i])) {
			const pii event = events[i][j];
			const int now = event.snd;

			if  (per_sec == 0) {
				if  (now > damage) {
					continue;
				}
				if  (j + 1 < sz(events[i])) {
					segs.pb(mp(event.fst, events[i][j + 1].fst - 1));
				} else {
					segs.pb(mp(event.fst, INF));
				}
				continue;
			}

			if  (mx <= damage) {
				if  (j + 1 < sz(events[i])) {
					segs.pb(mp(event.fst, events[i][j + 1].fst - 1));
				} else {
					segs.pb(mp(event.fst, INF));
				}
				continue;
			}

			ll first_t = (damage * 1ll - now + (per_sec)) / per_sec + event.fst;
			if  (j + 1 < sz(events[i]) && first_t >= events[i][j + 1].fst) {
				first_t = events[i][j + 1].fst;
			}
			if  (now > damage) {
				first_t = event.fst;
			}

			const ll l = event.fst;
			const ll r = first_t - 1;
			if  (l <= r) {
				segs.pb(mp(l, r));
			}
		}
	}

	vector<pair<ll, int>> es;
	for (const auto& seg : segs) {
		es.pb(mp(seg.fst, +1));
		es.pb(mp(seg.snd + 1, -1));
		if  (seg.fst <= seg.snd) {
			es.pb(mp(seg.snd, 0));
		} else {
			assert(0);
		}
	}
	sort(all(es));

	ll ans = 0;
	int bal = 0;
	for (int i = 0, j = 0; i < sz(es); i = j) {
		while (j < sz(es) && es[i].fst == es[j].fst) {
			bal += es[j].snd;
			++j;
		}

		const ll t = es[i].fst;
		const int cnt = bal;

		assert(cnt >= 0);
		assert(cnt <= n);

		if  (t >= INF && increase > 0) {
			return -1;
		}

		ans = max(ans, bounty * 1ll * cnt + t * cnt * increase);
	}

	return ans;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		printf("%lld\n", solve());
	}

#ifdef LOCAL
	eprintf("Time: %.10f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}