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

#define set set________

const int MAXN = 3e5 + 10;
const int A = 26;
const int INF = 1e9;

ull mpow(ull x, ull p) {
	ull res = 1;
	for (; p > 0; p >>= 1, x = x * x) {
		if  (p & 1) {
			res = res * x;
		}
	}
	return res;
}

ull inv(ull x) {
	assert(x & 1);
	ull y = mpow(x, (1ull << 63) - 1);
	assert(x * y == 1);
	return y;
}

struct Set {
	unordered_set<ull> S;
	ull coef;
	ull coef_inv;

	Set() : coef(1) {
		coef_inv = inv(coef);
	}

	void add(ull x) {
		assert(x & 1);
		x = x * coef_inv;
		assert(x & 1);
		S.insert(x);
	}

	void mult(ull x) {
		assert(x & 1);
		coef = coef * x;
		coef_inv = inv(coef);
	}

	bool have(ull x) const {
		return S.count(x * coef_inv);
	}

	int size() const {
		return sz(S);
	}

	vector<ull> get_all() const {
		vector<ull> res(all(S));
		for (auto& x : res) {
			assert(x & 1);
			x = x * coef;
			assert(x & 1);
		}
		return res;
	}
};

int n;
vector<pii> g[MAXN];

bool read() {
	if  (scanf("%d", &n) < 1) {
		return 0;
	}
	forn(i, n) {
		g[i].clear();
	}
	forn(it, n - 1) {
		int u, v;
		char c;
		scanf("%d%d %c\n", &u, &v, &c);
		--u;
		--v;
		g[u].pb(mp(v, c - 'a'));
	}
	return 1;
}

ull mrand() {
	ull res = rand() * 1ull * RAND_MAX;
	res += rand();
	return res;
}

ull coef_depth[MAXN];
ull coef_ch[A];

void precalc() {
	forn(i, MAXN) {
		coef_depth[i] = mrand();
		if  (coef_depth[i] % 2 == 1) {
			--coef_depth[i];
		}
	}
	forn(i, A) {
		coef_ch[i] = mrand();
		if  (coef_ch[i] % 2 == 0) {
			++coef_ch[i];
		}
	}
}

Set* set[MAXN];
int ans[MAXN];
int aux_ans[MAXN];

void dfs(int v, int pos) {
	for (const auto& e : g[v]) {
		int to, ch;
		tie(to, ch) = e;
		dfs(to, pos + 1);
		assert(set[to]);
		// printf("sz(set(%d)) = %d\n", to + 1, set[to]->size());
	}

	// printf("dfs in v=%d\n", v + 1);

	if  (g[v].empty()) {
		set[v] = new Set();
		set[v]->add(1);
		aux_ans[pos] += 1;
		return;
	}

	aux_ans[pos + 1] += 1;

	sort(all(g[v]), [&](const pii& e1, const pii& e2) { return set[e1.fst]->size() < set[e2.fst]->size(); });

	set[v] = set[g[v].back().fst];

	Set aux;
	ans[pos] += set[v]->size();
	forn(i, sz(g[v]) - 1) {
		int to, ch;
		tie(to, ch) = g[v][i];

		auto cur_all = set[to]->get_all();
		for (const auto& cur : cur_all) {
			if  (aux.have(cur) || set[v]->have(cur)) {
				continue;
			}
			aux.add(cur);
			ans[pos] += 1;
		}
	}

	set[v]->mult(coef_ch[g[v].back().snd] + coef_depth[pos]);
	forn(i, sz(g[v]) - 1) {
		int to, ch;
		tie(to, ch) = g[v][i];

		set[to]->mult(coef_ch[ch] + coef_depth[pos]);
		auto cur_all = set[to]->get_all();
		for (const auto& cur : cur_all) {
			set[v]->add(cur);
		}		
	}
	set[v]->add(1);
}

void solve() {
	forn(v, n) {
		delete set[v];
	}

	vi was_in(n, 0);
	forn(v, n) {
		for (const auto& e : g[v]) {
			was_in[e.fst] = 1;
		}
	}
	int root = -1;
	forn(v, n) {
		if  (!was_in[v]) {
			root = v;
			break;
		}
	}
	assert(root != -1);

	memset (aux_ans, 0, sizeof aux_ans);
	memset (ans, 0, sizeof ans);
	dfs(root, 0);

	int pref = 0;
	forn(p, n + 1) {
		pref += aux_ans[p];
		ans[p] += pref;
	}

	int best_p = -1;
	int mn = INF;
	forn(p, n + 1) {
		// printf("ans[p=%d] = %d\n", p + 1, ans[p]);
		if  (ans[p] < mn) {
			best_p = p;
			mn = ans[p];
		}
	}

	printf("%d\n%d\n", mn, best_p + 1);
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	precalc();

	while (read()) {
		solve();
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}