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

struct Query {
	int t, l, r;

	void read() {
		scanf("%d%d%d", &t, &l, &r);
		--l;
		--r;
	}
};

int n;
vi s;
vi m;
vi per_sec;
vector<Query> qs;

bool read() {
	if  (scanf("%d", &n) < 1) {
		return 0;
	}
	s.resize(n);
	m.resize(n);
	per_sec.resize(n);
	forn(i, n) {
		scanf("%d%d%d", &s[i], &m[i], &per_sec[i]);
	}
	int cnt_q;
	scanf("%d", &cnt_q);
	qs.resize(cnt_q);
	forn(i, cnt_q) {
		qs[i].read();
	}
	return 1;
}

bool by_ratio(int i, int j) {
	if  (per_sec[i] == 0) {
		return 0;
	}
	if  (per_sec[j] == 0) {
		return 1;
	}
	return (m[i] / per_sec[i]) < (m[j] / per_sec[j]);
}

struct SegmTree {
	vector<vi> t;
	vector<vll> pref_per_sec;
	vector<vll> pref_m;
	int sz;

	SegmTree() {}

	SegmTree(int n) {
		sz = 1;
		while (sz < n) sz *= 2;

		t.resize(sz * 2);
		pref_per_sec.resize(sz * 2);
		pref_m.resize(sz * 2);

		forn(i, n) {
			t[sz + i].pb(i);
		}
		for (int v = sz - 1; v > 0; --v) {
			t[v].resize(sz(t[v * 2]) + sz(t[v * 2 + 1]));
			merge(all(t[v * 2]), all(t[v * 2 + 1]), t[v].begin());
		}

		for (int v = 1; v < 2 * sz; ++v) {
			sort(all(t[v]), by_ratio);

			auto calc_pref = [&](vll& pref, const vi& func) {
				pref.assign(sz(t[v]) + 1, 0);
				forn(i, sz(t[v])) {
					pref[i + 1] = pref[i] + func[t[v][i]];
				}
			};

			calc_pref(pref_per_sec[v], per_sec);
			calc_pref(pref_m[v], m);
		}
	}

	ll sum_per_sec(int v, int l, int r) {
		if  (l > r) {
			return 0;
		}
		return pref_per_sec[v].at(r + 1) - pref_per_sec[v].at(l);
	}

	ll sum_m(int v, int l, int r) {
		if  (l > r) {
			return 0;
		}
		return pref_m[v].at(r + 1) - pref_m[v].at(l);
	}

	ll ask(int v, int tl, int tr, int l, int r, int dt) {
		l = max(l, tl);
		r = min(r, tr);

		if  (l > r) {
			return 0;
		}

		if  (l == tl && r == tr) {
			int L = -1;
			int R = sz(t[v]);
			while (L != R - 1) {
				const int M = (L + R) / 2;
				const int id = t[v][M];
				bool is_greater = 0;
				if  (per_sec[id] == 0) {
					is_greater = 0;
				} else if  (dt <= m[id] / per_sec[id]) {
					is_greater = 0;
				} else {
					is_greater = 1;
				}
				// eprintf("id=%d, is_greater=%d\n", id, is_greater);
				if  (is_greater) {
					L = M;
				} else {
					R = M;
				}
			}

			ll ans = 0;
			ans += dt * sum_per_sec(v, L + 1, sz(t[v]) - 1);
			ans += sum_m(v, 0, L);

			// eprintf("sz(t[v]) = %d, [0, %d], dt=%d\n", sz(t[v]), L, dt);
			// eprintf("v=%d:\n", v);
			// forn(i, sz(t[v])) {
			// 	eprintf("%d ", t[v][i]);
			// }
			// eprintf("\n");
			return ans;
		}	

		int tm = (tl + tr) >> 1;
		ll ans = ask(v * 2, tl, tm, l, r, dt);
		ans += ask(v * 2 + 1, tm + 1, tr, l, r, dt);

		return ans;
	}

	ll ask(int l, int r, int dt) {
		assert(dt > 0);
		return ask(1, 0, sz - 1, l, r, dt);
	}
};

struct Seg {
	int t, l, r;

	bool operator < (const Seg& s) const {
		return mp(r, l) < mp(s.r, s.l);
	}
};

void solve() {
	SegmTree T(n);

	set<int> alive;
	{
		vi to_alive(n);
		iota(all(to_alive), 0);
		alive = set<int>(all(to_alive));
	}

	set<Seg> segs;

	for (const auto& q : qs) {
		ll ans = 0;

		while (1) {
			auto it = alive.lower_bound(q.l);
			if  (it == alive.end() || *it > q.r) {
				break;
			}
			const int i = *it;
			alive.erase(it);
			ans += min(m[i] * 1ll, s[i] + q.t * 1ll * per_sec[i]);
		}

		while (1) {
			auto it = segs.lower_bound(Seg{-1, -1, q.l});

			if (it == segs.end()) {
				break;
			}
			const auto seg = *it;
			if  (seg.l > q.r) {
				break;
			}
			segs.erase(it);

			if  (seg.l < q.l) {
				segs.insert(Seg{seg.t, seg.l, q.l - 1});
				segs.insert(Seg{seg.t, q.l, seg.r});
				continue;
			}

			if  (seg.r > q.r) {
				segs.insert(Seg{seg.t, seg.l, q.r});
				segs.insert(Seg{seg.t, q.r + 1, seg.r});
				continue;
			}

			ans += T.ask(seg.l, seg.r, q.t - seg.t);
		}

		segs.insert(Seg{q.t, q.l, q.r});
	
		printf("%lld\n", ans);
	}
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
	eprintf("Time: %.10f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}