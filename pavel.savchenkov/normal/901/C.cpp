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

const int MAXN = 3e5 + 10;

struct Query {
	int l, r;
	int id;

	void read(int i) {
		id = i;
		scanf("%d%d", &l, &r);
		--l;
		--r;
	}
};

struct Edge {
	int a, b;
	int id;

	void read(int i) {
		id = i;
		scanf("%d%d", &a, &b);
		--a;
		--b;
	}

	int to(int v) const {
		assert(v == a || v == b);
		return (a ^ b) ^ v;
	}
};

int n, m;
vector<Edge> g[MAXN];
vector<Query> qs;
vector<Edge> es;

bool read() {
	if  (scanf("%d%d", &n, &m) < 2) {
		return 0;
	}
	forn(i, n) {
		g[i].clear();
	}
	es.resize(m);
	forn(i, m) {
		es[i].read(i);
	}
	for (const auto& e : es) {
		g[e.a].pb(e);
		g[e.b].pb(e);
	}
	int q;
	scanf("%d", &q);
	qs.resize(q);
	forn(i, q) {
		qs[i].read(i);
	}
	return 1;
}

void dfs(int v, int prev, vi& st, vi& col, vvi& cycles) {
	col[v] = 1;
	st.pb(v);
	for (const auto& e : g[v]) {
		int to = e.to(v);
		if  (to == prev) {
			continue;
		}
		if  (col[to] == 1) {
			vi cycle;
			for (int i = sz(st) - 1; i >= 0 && st[i] != to; --i) {
				cycle.pb(st[i]);
			}
			cycle.pb(to);
			cycles.pb(cycle);
		} else if  (col[to] == 0) {
			dfs(to, v, st, col, cycles);
		}
	}
	assert(st.back() == v);
	st.pop_back();
	col[v] = 2;
}

struct FenwTree {
	vll t;

	FenwTree(int n = 0) {
		t.assign(n, 0);
	}

	ll get(int r) {
		ll ans = 0;
		for (int i = r; i >= 0; i &= i + 1, --i) {
			ans += t[i];
		}
		return ans;
	}

	ll get(int l, int r) {
		return get(r) - get(l - 1);
	}

	void upd(int pos, ll val) {
		for (int i = pos; i < sz(t); i |= i + 1) {
			t[i] += val;
		}
	}
};

void solve() {
	vvi cycles;
	vi col(n, 0);
	vi st;
	forn(v, n) {
		if  (col[v] == 0) {
			dfs(v, -1, st, col, cycles);
		}
	}

	vi cnt_cycle(sz(cycles));
	vi id_cycle(n, -1);
	forn(i, sz(cycles)) {
		for (int v : cycles[i]) {
			id_cycle[v] = i;
		}
	}

	{
		eprintf("cycles:\n");
		for (const auto& cycle : cycles) {
			for (const auto& v : cycle) {
				eprintf("%d ", v + 1);
			}
			eprintf("\n");
		}
		eprintf("end cycles ------>\n");
	}

	vi next(n);
	int r = 0;
	forn(l, n) {
		while (r < n) {
			const int c = id_cycle[r];
			if  (c == -1) {
				++r;
				continue;
			}
			if  (cnt_cycle[c] + 1 == sz(cycles[c])) {
				break;
			}
			++cnt_cycle[c];
			++r;
		}

		next[l] = r - 1;
		{
			const int c = id_cycle[l];
			if  (c != -1) {
				assert(cnt_cycle[c] > 0);
				--cnt_cycle[c];
			}
		}
	}	

	{
		eprintf("next:\n");
		forn(v, n) {
			eprintf("%d -> %d\n", v + 1, next[v] + 1);
		}
		eprintf("end next ---->\n");
	}

	vll ans(sz(qs), 0);
	
	vvi who_next(n);
	forn(i, n) {
		who_next[next[i]].pb(i);
	}

	vector<vector<Query>> who_qs_r(n);
	for (const auto& q : qs) {
		who_qs_r[q.r].pb(q);
	}

	// inside
	{
		FenwTree T(n);
		forn(r, n) {
			for (int i : who_next[r]) {
				T.upd(i, r - i + 1);
			}

			for (const auto& q : who_qs_r[r]) {
				ans[q.id] += T.get(q.l, q.r);
			}
		}
	}

	// outside
	{
		FenwTree sum(n);
		FenwTree cnt(n);
		ford(r, n) {
			for (const auto& q : who_qs_r[r]) {
				ll cur = -sum.get(q.l, q.r);
				cur += (r + 1) * cnt.get(q.l, q.r);
				ans[q.id] += cur;
			}

			for (int i : who_next[r]) {
				sum.upd(i, i);
				cnt.upd(i, +1);
			}
		}
	}

	forn(i, sz(qs)) {
		printf("%lld\n", ans[i]);
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