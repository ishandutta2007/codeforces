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
#include <tuple>

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

int n, m;
vector<vii> g;

bool read() {
	if  (scanf("%d%d", &n, &m) < 2) {
		return 0;
	}
	g.clear();
	g.resize(n);
	forn(i, m) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		g[a].pb(mp(b, i));
		g[b].pb(mp(a, i));
	}
	return 1;
}

vi tin;
int timer;
vector<tuple<int, int, int>> ans;
vi used;

void add(int v, const pii& e1, const pii& e2) {
	// eprintf("use id1=%d, id2=%d\n", e1.snd + 1, e2.snd + 1);

	assert(!used[e1.snd]);
	assert(!used[e2.snd]);
	used[e1.snd] = used[e2.snd] = 1;
	ans.pb(make_tuple(e1.fst, v, e2.fst));
}

void dfs(int v, int id_p, int p) {
	tin[v] = timer++;

	// eprintf("v = %d\n", v + 1);

	vii up;
	vii down;

	if  (p != -1) {
		down.pb(mp(p, id_p));
	}

	for (const auto& e : g[v]) {
		int to, id;
		tie(to, id) = e;
		if  (to == p) {
			continue;
		}
		if  (tin[to] != -1) {
			if  (tin[to] < tin[v]) {
				up.pb(mp(to, id));
			}
			continue;
		}

		dfs(to, id, v);

		if  (!used[id]) {
			down.pb(mp(to, id));
		}
	}

	auto process = [&](vii& vec) {
		while (sz(vec) >= 2) {
			add(v, vec.back(), vec[sz(vec) - 2]);
			vec.pop_back();
			vec.pop_back();
		}
	};

	process(up);

	if  (down.empty()) {
		return;
	}

	if  (!up.empty()) {
		assert(sz(up) == 1);
		add(v, down.back(), up.back());
		up.clear();
		down.pop_back();
	}

	process(down);

	if  (!down.empty() && p != -1) {
		assert(down.front().snd == id_p);
	}
}

void solve() {
	ans.clear();
	tin.assign(n, -1);
	used.assign(m, 0);
	timer = 0;

	forn(v, n) {
		if  (tin[v] == -1) {
			dfs(v, -1, -1);
		}
	}

	printf("%d\n", sz(ans));
	for (const auto& it : ans) {
		printf("%d %d %d\n", get<0>(it) + 1, get<1>(it) + 1, get<2>(it) + 1);
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