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
#define image(C) sort(all(C)), C.resize(unique(all(C)) - C.begin());

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

const int MAXN = 5e5 + 10;

int n, m;
vi diags[MAXN];

void add_diag(int a, int b) {
	diags[a].pb(b);
	diags[b].pb(a);
}

bool read() {
	if  (scanf("%d%d", &n, &m) < 2) {
		return 0;
	}
	forn(i, n) {
		diags[i].clear();
	}
	forn(i, m) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		add_diag(a, b);
	}
	forn(i, n) {
		int nxt = (i + 1) % n;
		add_diag(i, nxt);
		int prv = (i - 1 + n) % n;
		add_diag(i, prv);
	}
	forn(i, n) {
		image(diags[i]);
	}
	return 1;
}

vi g[MAXN];
vvi cycles;
map<pii, set<int>> in_cycles;
set<pii> was_right;

int dist_cw(int a, int b) {
	// a + x == b
	return (b - a + n) % n;
}

bool have_diag(int a, int b) {
	int pos = lower_bound(all(diags[a]), b) - diags[a].begin();
	return pos < sz(diags[a]) && diags[a][pos] == b;
}

vi get_right_cycle(int a, int b) {
	if  (dist_cw(b, a) == 1) {
		return {};
	}
	
	if  (was_right.count(mp(a, b))) {
		return {};
	}

	bool first = true;
	was_right.insert(mp(a, b));
	vi res;
	res.pb(a);
	res.pb(b);
	while (1) {
		if  (dist_cw(b, a) == 1) {
			was_right.insert(mp(b, a));
			break;
		}
		int pos = lower_bound(all(diags[b]), a) - diags[b].begin();
		if  (first) {
			assert(diags[b][pos] == a);
		} else {
			if  (have_diag(b, a)) {
				break;
			}
		}
		first = 0;
		
		pos = (pos - 1 + sz(diags[b])) % sz(diags[b]);
		int c = diags[b][pos];

		// printf("right: a=%d, b=%d, c=%d\n", a, b, c);

		if  (dist_cw(b, c) + dist_cw(c, a) == dist_cw(b, a)) {
			assert(!was_right.count(mp(b, c)));
			was_right.insert(mp(b, c));
			res.pb(c);
			b = c;
		} else {
			assert(0);
		}
	}

	return res;
}

int ans[MAXN];
int sz[MAXN];
bool was[MAXN];
int N;

void dfs_sz(int v, int p) {
	sz[v] = 1;
	for (int to : g[v]) {
		if  (was[to] || to == p) {
			continue;
		}
		dfs_sz(to, v);
		sz[v] += sz[to];
	}
}

int dfs_root(int v, int p, int s) {
	int mx_to = -1;
	for (int to : g[v]) {
		if  (was[to] || to == p) {
			continue;
		}
		if  (mx_to == -1 || sz[to] > sz[mx_to]) {
			mx_to = to;
		}
	}
	if  (mx_to == -1) {
		return v;
	}
	if  (sz[mx_to] * 2 <= s) {
		return v;
	}
	return dfs_root(mx_to, v, s);
}

int get_root(int v) {
	dfs_sz(v, -1);
	return dfs_root(v, -1, sz[v]);
}

void paint(int v, int ptr) {
	int r = get_root(v);
	ans[r] = ptr;
	was[r] = 1;
	for (int to : g[r]) {
		if  (!was[to]) {
			paint(to, ptr + 1);
		}
	}
}

void paint() {
	N = sz(cycles);
	int E = 0;
	forn(i, N) {
		E += sz(g[i]);
	}
	assert(E % 2 == 0);
	E /= 2;
	assert(E == N - 1);
	memset (was, 0, sizeof was);
	paint(0, 0);
}

void solve() {
	cycles.clear();
	in_cycles.clear();
	was_right.clear();

	// printf("diags:\n");
	// forn(a, n) {
	// 	for (int b : diags[a]) {
	// 		printf("%d -> %d\n", a, b);
	// 	}
	// }
	// puts("");

	forn(a, n) {
		for (int b : diags[a]) {
			if  (a > b) {
				continue;
			}
			vi c = get_right_cycle(a, b);
			if  (!c.empty()) {
				cycles.pb(c);
			}
		}
	} 
	image(cycles);

	// printf("cycles:\n");
	// for (auto c : cycles) {
	// 	for (int x : c) {
	// 		printf("%d ", x);
	// 	}
	// 	puts("");
	// }

	forn(i, sz(cycles)) {
		g[i].clear();
	}
	forn(i, sz(cycles)) {
		const vi& cycle = cycles[i];
		forn(j, sz(cycle)) {
			int a = cycle[j];
			int b = cycle[(j + 1) % sz(cycle)];
			in_cycles[mp(a, b)].insert(i);
			in_cycles[mp(b, a)].insert(i);
		}
	}

	forn(a, n) for (int b : diags[a]) {
		vi who(all(in_cycles[mp(a, b)]));
		assert(sz(who) <= 2);
		forn(i, sz(who)) forn(j, i) {
			int A = who[i];
			int B = who[j];
			g[A].pb(B);
			g[B].pb(A);
		}
	}

	forn(i, sz(cycles)) {
		image(g[i]);
	}

	// printf("N=%d:\n", sz(cycles));
	// forn(i, sz(cycles)) {
	// 	for (int j : g[i]) {
	// 		printf("%d -> %d\n", i, j);
	// 	}
	// }

	paint();

	forn(i, sz(cycles)) {
		sort(all(cycles[i]));
		reverse(all(cycles[i]));
	}
	vi perm(sz(cycles));
	forn(i, sz(perm)) {
		perm[i] = i;
	}
	sort(all(perm), [](int i, int j) {
		const vi& A = cycles[i];
		const vi& B = cycles[j];
		forn(ii, min(sz(A), sz(B))) {
			if  (A[ii] != B[ii]) {
				return A[ii] < B[ii];
			}
		}
		return sz(A) < sz(B);
	});

	// printf("cycles after:\n");
	// forn(i, sz(cycles)) {
	// 	int j = perm[i];
	// 	for (int x : cycles[j]) {
	// 		printf("%d ", x);
	// 	}
	// 	puts("");
	// }

	forn(i, sz(cycles)) {
		printf("%d ", ans[perm[i]] + 1);
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