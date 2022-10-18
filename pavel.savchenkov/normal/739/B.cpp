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
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
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

const int MAXN = 4e5 + 10;

int n;
int a[MAXN];
vii g[MAXN];

bool read() {
	if  (scanf("%d", &n) < 1) {
		return 0;
	}
	forn(i, n) {
		scanf("%d", &a[i]);
	}
	forn(i, n) {
		g[i].clear();
	}
	forn(i, n - 1) {
		int p, w;
		scanf("%d%d", &p, &w);
		--p;
		g[p].pb(mp(i + 1, w));
	}
	return 1;
}

struct FenwTree {
	vi t;

	FenwTree(int n = 0) {
		t.assign(n, 0);
	}

	int get(int r) {
		int res = 0;
		for (int i = r; i >= 0; i &= i + 1, --i) {
			res += t[i];
		}
		return res;
	}

	// int get(int l, int r) {
	// 	return get(r) - get(l - 1);
	// }

	void upd(int pos, int val) {
		for (int i = pos; i < sz(t); i |= i + 1) {
			t[i] += val;
		}
	}
};

ll pref[MAXN];
vll vals;
int tin[MAXN];
int timer;
int left[MAXN];
int right[MAXN];
vi order;

void dfs(int v, int p, ll cur) {
	tin[v] = timer++;
	order.pb(v);
	left[v] = tin[v] + 1;
	pref[v] = cur;
	for (const auto& e : g[v]) {
		int to = e.fst;
		if  (to != p) {
			dfs(to, v, cur + e.snd);
		}
	}
	right[v] = timer - 1;
}

struct Event {
	int id;
	ll upper;
	int coef;
};

vector<Event> es[MAXN];
int ans[MAXN];

void solve() {
	order.clear();
	timer = 0;
	dfs(0, -1, 0);

	forn(v, n) {
		assert(order[tin[v]] == v);
	}

	vals.clear();
	forn(i, n) {
		vals.pb(pref[i] - a[i]);
	}
	sort(all(vals));
	vals.resize(unique(all(vals)) - vals.begin());

	forn(i, sz(order) + 1) {
		es[i].clear();
	}

	forn(v, n) {
		if  (left[v] <= right[v]) {
			es[left[v]].pb(Event{v, pref[v], -1});
			es[right[v] + 1].pb(Event{v, pref[v], +1});
		}
	}

	memset (ans, 0, sizeof ans);
	FenwTree T(sz(vals));
	forn(i, sz(order) + 1) {
		for (const auto& e : es[i]) {
			int pos = upper_bound(all(vals), e.upper) - vals.begin();
			--pos;
			if  (pos >= 0) {
				ans[e.id] += e.coef * T.get(pos);
			}
		}
		if  (i < sz(order)) {
			ll val = pref[order[i]] - a[order[i]];
			int pos = lower_bound(all(vals), val) - vals.begin();
			assert(pos < sz(vals) && vals[pos] == val);
			T.upd(pos, +1);
		}
	}

	forn(i, n) {
		printf("%d ", ans[i]);
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