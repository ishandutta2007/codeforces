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

const int MAXN = 2e5 + 10;

int n;
vi g[MAXN];
int ch[MAXN];

bool read() {
	if  (scanf("%d", &n) < 1) {
		return 0;
	}
	forn(i, n) {
		g[i].clear();
	}
	forn(i, n - 1) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		g[a].pb(b);
		g[b].pb(a);
	}
	scanf("\n");
	static char s[MAXN];
	scanf("%s\n", s);
	forn(i, n) {
		ch[i] = s[i] - 'a';
	}
	return 1;
}

const int A = 't' - 'a' + 1;

namespace Arr {
	const int MAX = 1 << A;

	int val[MAX];
	int when[MAX];
	int timer;

	void init() {
		memset (when, -1, sizeof when);
		memset (val, 0, sizeof val);
		timer = 0;
	}

	inline int get(int i) {
		const int res = when[i] == timer ? val[i] : 0;
		// eprintf("get(%d) = %d\n", i, res);
		return res;
	}

	inline void set(int i, int nval) {
		// eprintf("val[%d] := %d\n", i, nval);
		when[i] = timer;
		val[i] = nval;
	}

	inline void add(int i, int aux) {
		// eprintf("val[%d] += %d\n", i, aux);
		int old = get(i);
		set(i, old + aux);
	}

	void clear() {
		// eprintf("CLEAR\n");
		++timer;
	}
};

int sz[MAXN];
bool used[MAXN];

void dfs_sz(int v, int p) {
	sz[v] = 1;
	for (int to : g[v]) {
		if  (used[to] || to == p) {
			continue;
		}
		dfs_sz(to, v);
		sz[v] += sz[to];
	}
}

int get_root(int v) {
	dfs_sz(v, -1);

	const int S = sz[v];
	int p = -1;
	while (1) {
		int mx_to = -1;
		for (int to : g[v]) {
			if  (used[to] || to == p) {
				continue;
			}
			if  (mx_to == -1 || sz[to] > sz[mx_to]) {
				mx_to = to;
			}
		}
		if  (mx_to == -1 || sz[mx_to] * 2 <= S) {
			return v;
		}
		p = v;
		v = mx_to;
	}
	assert(0);
	return -1;
}

int mask[MAXN];
ll ans[MAXN];

void dfs_mask(int v, int p, int cur_mask) {
	mask[v] = cur_mask ^ (1 << ch[v]);
	for (int to : g[v]) {
		if  (used[to] || to == p) {
			continue;
		}
		dfs_mask(to, v, cur_mask ^ (1 << ch[v]));
	}
}

void dfs_add(int v, int p, int coef) {
	Arr::add(mask[v], coef);

	for (int to : g[v]) {
		if  (used[to] || to == p) {
			continue;
		}
		dfs_add(to, v, coef);
	}
}

ll dfs_ans(int v, int p, int cur_mask) {
	cur_mask ^= 1 << ch[v];

	ll cur = 0;
	forn(i, A) {
		int want = cur_mask ^ (1 << i);
		ll cur_get = Arr::get(want);
		// eprintf("cur_get = %lld\n", cur_get);
		cur += cur_get;
	}
	cur += Arr::get(cur_mask);

	ll sum = 0;
	for (int to : g[v]) {
		if  (used[to] || to == p) {
			continue;
		}
		sum += dfs_ans(to, v, cur_mask);
	}

	sum += cur;

	ans[v] += sum;

	return sum;
}

void solve(int some) {
	int root = get_root(some);

	vi sons;
	for (int to : g[root]) {
		if  (!used[to]) {
			sons.pb(to);
		}
	}

	for (int to : sons) {
		dfs_mask(to, root, 0);
	}

	Arr::clear();
	for (int to : sons) {
		dfs_add(to, root, +1);
	}
	ll sum = 0;
	for (int to : sons) {
		dfs_add(to, root, -1);
		sum += dfs_ans(to, root, 1 << ch[root]);
		dfs_add(to, root, +1);
	}
	assert(sum % 2 == 0);
	ans[root] += sum / 2;

	Arr::clear();
	Arr::set(0, 1);
	sum = 0;
	for (int to : sons) {
		sum += dfs_ans(to, root, 1 << ch[root]);
	}
	ans[root] += sum;
	++ans[root];

	used[root] = 1;
	for (int to : sons) {
		solve(to);
	}
}

void solve() {
	forn(i, n) {
		ans[i] = 0;
		mask[i] = 0;
		used[i] = 0;
	}
	solve(0);
	forn(i, n) {
		printf("%lld ", ans[i]);
	}
	printf("\n");
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	Arr::init();

	while (read()) {
		solve();

		// break;
	}

#ifdef LOCAL
	eprintf("Time: %.10f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}