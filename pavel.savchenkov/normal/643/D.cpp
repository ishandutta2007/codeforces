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

#define pb push_back
#define fst first
#define snd second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define next jskdfksdhfjkdsjksdjkgf
#define prev koeuigrihjdkjdfj
#define hash kjfdkljkdhgjdkfhgurehg
#define all(C) begin(C), end(C)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector <int> > vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

#define FILE_NAME "a"


const int MAXN = 1e5 + 10;
const ll INF = 1e18;

ll t[MAXN];
int f[MAXN];
int n, q;

struct Query {
	int t, i, j;

	bool read() {
		if  (scanf("%d", &t) < 1) {
			return false;
		}
		if  (t == 1) {
			scanf("%d%d", &i, &j);
			--i;
			--j;
		} else if  (t == 2) {
			scanf("%d", &i);
			--i;
		} else {
			assert(t == 3);
		}
		return true;
	}
};

Query qs[MAXN];

bool read() {
	if  (scanf("%d%d", &n, &q) < 2) {
		return false;
	}
	forn(i, n) {
		scanf("%lld", &t[i]);
	}
	forn(i, n) {
		scanf("%d", &f[i]);
		--f[i];
	}
	forn(i, q) {
		assert(qs[i].read());
	}
	return true;
}

bool mark0[MAXN];
bool mark1[MAXN];
vi marked0;
vi marked1;

ll ans[MAXN];
int deg[MAXN];
bool is_cand[MAXN];
vi cands;

ll me(int v) {
	return t[v] - (deg[v] + 1) * (t[v] / (deg[v] + 2));
}

bool outside[MAXN];
vi who_link[MAXN];
ll cur_ans[MAXN];

void go(int l, int r) {
	forn(i, n) {
		mark0[i] = false; 
	}
	marked0.clear();

	for (int i = l; i < r; ++i) {
		if  (qs[i].t == 1) {
			int v = qs[i].i;
			int to = qs[i].j;
			int old_to = f[v];
			marked0.pb(v);
			marked0.pb(to);
			marked0.pb(old_to);
		}
	}
	sort(all(marked0));
	marked0.resize(unique(all(marked0)) - marked0.begin());
	for (int x : marked0) {
		mark0[x] = true;
	}

	// calc ans
	forn(i, n) {
		deg[i] = 0;
	}
	forn(i, n) {
		++deg[f[i]];
	}
	forn(i, n) {
		ans[i] = me(i);
	}
	forn(i, n) {
		ans[i] += t[f[i]] / (deg[f[i]] + 2);
		ans[f[i]] += t[i] / (deg[i] + 2);
	}

	// not change nodes
	forn(i, n) {
		outside[i] = true;
	}
	forn(i, n) {
		if  (mark0[i]) {
			outside[i] = false;
			outside[f[i]] = false;
		}
		if  (mark0[f[i]]) {
			outside[i] = false;
		}
	}

	ll max_outside = -1;
	ll min_outside = INF;
	forn(i, n) {
		if  (outside[i]) {
			max_outside = max(max_outside, ans[i]);
			min_outside = min(min_outside, ans[i]);
		}
	}

	// mark1
	forn(i, n) {
		mark1[i] = false;
	}
	marked1.clear();
	forn(i, n) {
		if  (mark0[i] && !mark0[f[i]]) {
			marked1.pb(f[i]);
		}
	}
	sort(all(marked1));
	marked1.resize(unique(all(marked1)) - marked1.begin());
	for (int x : marked1) {
		mark1[x] = true;
	}

	// who link to marked
	for (int x : marked0) {
		who_link[x].clear();
	}
	forn(i, n) {
		if  (mark0[i] || mark1[i]) {
			continue;
		}
		if  (!mark0[f[i]]) {
			continue;
		}
		who_link[f[i]].pb(i);
	} 

	// to best for min max queries
	cands.clear();
	for (int x : marked0) {
		if  (who_link[x].empty()) {
			continue;
		}
		int mn = -1;
		ll mn_val = INF;
		int mx = -1;
		ll mx_val = -1;
		forn(i, sz(who_link[x])) {
			int v = who_link[x][i];
			ll cur_val = ans[v] - (t[x] / (deg[x] + 2));
			if  (cur_val > mx_val) {
				mx_val = cur_val;
				mx = v;
			}
			if  (cur_val < mn_val) {
				mn_val = cur_val;
				mn = v;
			}
 		}
 		assert(mx != -1);
 		cands.pb(mx);
 		assert(mn != -1);
 		cands.pb(mn);
	}
	sort(all(cands));
	cands.resize(unique(all(cands)) - cands.begin());
	forn(i, n) {
		is_cand[i] = false;
	}
	for (int x : cands) {
		is_cand[x] = true;
	}

	forn(i, n) {
		if  (mark0[f[i]]) {
			ans[i] -= t[f[i]] / (deg[f[i]] + 2);
		}
		if  (mark0[i]) {
			ans[f[i]] -= t[i] / (deg[i] + 2);
		}
		ans[i] -= me(i);
	}

	// printf("mark0:\n");
	// for (int x : marked0) {
	// 	printf("%d ", x + 1);
	// } 
	// puts("");

	// printf("ans:\n");
	// forn(i, n) {
	// 	printf("ans[%d]=%lld ", i + 1, ans[i]);
	// }
	// puts("");

	vi all_marked;
	for (int x : marked0) {
		all_marked.pb(x);
	}
	for (int x : marked1) {
		all_marked.pb(x);
	}
	for (int x : cands) {
		all_marked.pb(x);
	}
	sort(all(all_marked));
	all_marked.resize(unique(all(all_marked)) - all_marked.begin());

	for (int i = l; i < r; ++i) {
		if  (qs[i].t == 1) {
			int v = qs[i].i;
			int to = qs[i].j;
			assert(v != to);
			assert(f[v] != to);
			assert(mark0[v]);
			assert(mark0[f[v]]);
			assert(mark0[to]);
			--deg[f[v]];
			f[v] = to;
			++deg[f[v]];
		} else if  (qs[i].t == 2) {
			int v = qs[i].i;
			ll cur_val = ans[v];
			for (int x : marked0) {
				if  (f[x] == v || f[v] == x) {
					cur_val += t[x] / (deg[x] + 2);
					// printf("val[%d] += from %d,t=%lld,deg=%d\n", v + 1, x + 1, t[x], deg[x]);
				}
			}
			// printf("cur_val=%lld, me=%lld\n", cur_val, me(v));
			printf("%lld\n", cur_val + me(v));
		} else {
			assert(qs[i].t == 3);
			ll mn = min_outside;
			ll mx = max_outside;
			for (int x : all_marked) {
				cur_ans[x] = ans[x];
			}
			for (int x : all_marked) {
				if  (mark0[x]) {
					cur_ans[f[x]] += t[x] / (deg[x] + 2);
				}
				if  (mark0[f[x]]) {
					cur_ans[x] += t[f[x]] / (deg[f[x]] + 2);
				}
			}
			for (int x : all_marked) {
				mn = min(mn, cur_ans[x] + me(x));
				mx = max(mx, cur_ans[x] + me(x));
			}
			printf("%lld %lld\n", mn, mx);
		}
	}
}

const int K = 250;

void solve() {
	for (int l = 0; l < q; ) {
		int r = l;
		int cnt = 0;
		while (r < q && cnt < K) {
			cnt += (qs[r].t == 1);
			++r;
		}
		go(l, r);
		l = r;
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

	return 0;
}