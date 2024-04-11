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

struct Query {
	int l1, r1;
	int l2, r2;
	int w;

	void read() {
		int t;
		scanf("%d", &t);
		if  (t == 1) {
			int v, u;
			scanf("%d%d%d", &v, &u, &w);
			--v;
			--u;
			l1 = r1 = v;
			l2 = r2 = u;
		} else {
			int v, l, r;
			scanf("%d%d%d%d", &v, &l, &r, &w);
			--v;
			--l;
			--r;
			if  (t == 2) {
				l1 = r1 = v;
				l2 = l;
				r2 = r;
			} else {
				l1 = l;
				r1 = r;
				l2 = r2 = v;
			}
		}
	}
};

const int MAXN = 1e5 + 10;

int n, q, s;
vector<Query> qs;

bool read() {
	if  (scanf("%d%d%d", &n, &q, &s) < 3) {
		return 0;
	}
	--s;
	qs.resize(q);
	forn(i, q) {
		qs[i].read();
	}
	return 1;
}

int sz;

vii g[9 * MAXN];

void addE(int v, int to, int w) {
	g[v].pb(mp(to, w));
}

void build_up(int v, int tl, int tr) {
	if  (tl == tr) {
		addE(2 * sz + 2 * sz + tl, v, 0);
		return;
	}

	int tm = (tl + tr) >> 1;

	addE(v * 2, v, 0);
	addE(v * 2 + 1, v, 0);

	build_up(v * 2, tl, tm);
	build_up(v * 2 + 1, tm + 1, tr);
}

void build_down(int v, int tl, int tr) {
	if  (tl == tr) {
		addE(2 * sz + v, 2 * sz + 2 * sz + tl, 0);
		return;
	}

	int off = 2 * sz;
	int tm = (tl + tr) >> 1;

	addE(off + v, off + v * 2, 0);
	addE(off + v, off + v * 2 + 1, 0);

	build_down(v * 2, tl, tm);
	build_down(v * 2 + 1, tm + 1, tr);
}

void get_nodes(int v, int tl, int tr, int l, int r, vi& vs) {
	l = max(l, tl);
	r = min(r, tr);

	if  (l > r) {
		return;
	}

	if  (l == tl && r == tr) {
		vs.pb(v);
		return;
	}

	int tm = (tl + tr) >> 1;
	get_nodes(v * 2, tl, tm, l, r, vs);
	get_nodes(v * 2 + 1, tm + 1, tr, l, r, vs);
}

const ll INF = 1e18;

ll dist[9 * MAXN];

struct cmp {
	bool operator()(int i, int j) const {
		return mp(dist[i], i) < mp(dist[j], j);
	}
};

void calc_from(int s) {
	forn(i, 9 * MAXN) {
		dist[i] = INF;
	}

	set<int, cmp> S;
	dist[s] = 0;
	S.insert(s);
	while (!S.empty()) {
		int v = *S.begin();
		S.erase(S.begin());
		// printf("v=%d, dist=%lld\n", v, dist[v]);
		// forn(x, 6 * n) {
		// 	printf("dist[%d]=%lld, ", x, dist[x]);
		// }
		// puts("");
		for (const auto& e : g[v]) {
			int to = e.fst;
			// printf("v=%d, to=%d, dist_to=%lld\n", v, to, dist[to]);
			if  (dist[v] + e.snd < dist[to]) {
				S.erase(to);
				dist[to] = dist[v] + e.snd;
				S.insert(to);
				// printf("insert %d\n", to);
			}
		}
	}
}

void solve() {
	forn(i, 9 * MAXN) {
		g[i].clear();
	}

	sz = 1;
	while (sz < n) sz *= 2;

	build_up(1, 0, sz - 1);
	build_down(1, 0, sz - 1);

	// printf("sz=%d\n", sz);

	// forn(v, 6 * n) {
	// 	for (auto e : g[v]) {
	// 		printf("%d -> %d w=%d\n", v, e.fst, e.snd);
	// 	}
	// }

	for (const auto& q : qs) {
		vi from;
		get_nodes(1, 0, sz - 1, q.l1, q.r1, from);

		vi to;
		get_nodes(1, 0, sz - 1, q.l2, q.r2, to);

		for (int fr : from) for (int t : to) {
			addE(fr, 2 * sz + t, q.w);
		}
	}
	
	calc_from(2 * sz + 2 * sz + s);

	forn(v, n) {
		ll res = dist[2 * sz + 2 * sz + v];
		if  (res >= INF) {
			res = -1;
		}
		printf("%lld ", res);
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