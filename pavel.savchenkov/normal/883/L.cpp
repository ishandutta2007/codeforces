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

int n, k, m;
vi x;

bool read() {
	if  (scanf("%d%d%d", &n, &k, &m) < 3) {
		return 0;
	}
	x.resize(k);
	forn(i, k) {
		scanf("%d", &x[i]);
		--x[i];
	}
	return 1;
}

struct Wait {
	ll t;
	int id;
	int pos;

	bool operator < (const Wait& w) const {
		return mp(mp(t, id), pos) < mp(mp(w.t, w.id), w.pos);
	}

	bool operator != (const Wait& w) const {
		return mp(mp(t, id), pos) != mp(mp(w.t, w.id), w.pos);
	}

	void print() const {
		eprintf("t=%lld, id=%d, pos=%d\n", t, id, pos);
	}
};

const Wait INFW{ll(1e18), int(1e9), int(1e9)};

struct SegmTree {
	vector<Wait> t;
	vector<set<Wait>> s;
	int sz;

	SegmTree(int n = 0) {
		sz = 1;
		while (sz < n) sz *= 2;

		t.assign(sz * 2, INFW);
		s.resize(sz * 2);
	}

	void insert(const Wait& w) {
		int v = sz + w.pos;

		// eprintf("insert:\n");
		// w.print();

		s[v].insert(w);
		t[v] = *s[v].begin();
		while (v > 1) {
			v >>= 1;
			t[v] = min(t[v * 2], t[v * 2 + 1]);
		}
	}

	void erase(const Wait& w) {
		// eprintf("erase:\n");
		// w.print();

		int v = sz + w.pos;
		s[v].erase(w);
		t[v] = s[v].empty() ? INFW : *s[v].begin();
		while (v > 1) {
			v >>= 1;
			t[v] = min(t[v * 2], t[v * 2 + 1]);
		}
	}

	Wait get_min(int l, int r) {
		l = max(l, 0);
		r = min(r, sz - 1);

		// eprintf("get_min [%d, %d]: ", l, r);

		l += sz;
		r += sz;
		Wait res = INFW;
		while (l <= r) {
			res = min(res, t[l]);
			res = min(res, t[r]);
			l = (l + 1) >> 1;
			r = (r - 1) >> 1;
		}

		// res.print();

		return res;
	}
};

SegmTree T;
multiset<int> poses;

void insert(const Wait& w) {
	T.insert(w);
	poses.insert(w.pos);
}

void erase(const Wait& w) {
	T.erase(w);
	poses.erase(poses.find(w.pos));
}

const int INF = 1e9;

void solve() {
	poses.clear();
	T = SegmTree(n);
	forn(i, k) {
		insert(Wait{0ll, i, x[i]});
	}

	set<Wait> events;
	forn(i, m) {
		ll t;
		int a, b;
		scanf("%lld%d%d", &t, &a, &b);
		--a;
		--b;

		while (!events.empty() && events.begin()->t <= t) {
			const auto mn = *events.begin();
			events.erase(events.begin());
			insert(mn);
		}

		ll tt = t;
		if  (poses.empty()) {
			assert(!events.empty());
			tt = events.begin()->t;
		}

		// eprintf("t=%lld, a=%d, b=%d,  aux=%lld\n", t, a, b, aux);

		while (!events.empty() && events.begin()->t <= tt) {
			const auto mn = *events.begin();
			events.erase(events.begin());
			insert(mn);
		}

		int left = INF;
		{
			auto it = poses.upper_bound(a);
			if  (it != poses.begin()) {
				--it;
				left = a - *it;
			}
		}

		int right = INF;
		{
			auto it = poses.upper_bound(a);
			if  (it != poses.end()) {
				right = *it - a;
			}
		}

		const int dist = min(left, right);
		assert(dist < INF);

		Wait best = T.get_min(a - dist, a + dist);
		assert(best != INFW);

		// best.print();

		erase(best);	

		ll start = max(best.t, t);
		printf("%d %lld\n", best.id + 1, start + abs(a - best.pos) - t);

		Wait nw{start + abs(a - best.pos) + abs(a - b), best.id, b};
		events.insert(nw);
	}
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		solve();

		// break;
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}