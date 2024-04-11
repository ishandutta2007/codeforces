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


int n, m, k;
vii both;
vii one[2];
vii rest;

bool read() {
	if  (scanf("%d%d%d", &n, &m, &k) < 3) {
		return 0;
	}
	vi c(n);
	forn(i, n) {
		scanf("%d", &c[i]);
	}
	vector<vector<bool>> like(2, vector<bool>(n, 0));
	forn(it, 2) {
		int cnt;
		scanf("%d", &cnt);
		forn(i, cnt) {
			int pos;
			scanf("%d", &pos);
			--pos;
			like[it][pos] = 1;
		}
	}

	both.clear();
	forn(i, 2) {
		one[i].clear();
	}
	rest.clear();

	int ptr = 0;
	forn(i, n) {
		if  (like[0][i] && like[1][i]) {
			both.pb(mp(c[i], ptr));
		} else if  (like[0][i]) {
			one[0].pb(mp(c[i], ptr));
		} else if  (like[1][i]) {
			one[1].pb(mp(c[i], ptr));
		} else {
			rest.pb(mp(c[i], ptr));
		}
		++ptr;
	}

	sort(all(both));
	forn(it, 2) {
		sort(all(one[it]));
	}
	sort(all(rest));

	return 1;
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

	void inc(int pos, int val) {
		for (int i = pos; i < sz(t); i |= i + 1) {
			t[i] += val;
		}
	}
};

struct SegmTree {
	static const int MAX = 1e8;

	vi t;
	int sz;

	SegmTree(int n = 0) {
		sz = 1;
		while (sz < n) sz *= 2;

		t.assign(sz * 2, 0);
	}

	int get_sum(int v, int tl, int tr, int l, int r) {
		l = max(l, tl);
		r = min(r, tr);

		if  (l > r) {
			return 0;
		}

		if  (l == tl && r == tr) {
			return t[v];
		}

		int tm = (tl + tr) >> 1;
		return get_sum(v * 2, tl, tm, l, r) + get_sum(v * 2 + 1, tm + 1, tr, l, r);
	}

	int get_left_not_less(int v, int tl, int tr, int l, int r, int sum) {
		assert(sum);

		l = max(l, tl);
		r = min(r, tr);

		if  (get_sum(v, tl, tr, l, r) < sum) {
			return MAX;
		}

		if  (tl == tr) {
			return tl;
		}

		int tm = (tl + tr) >> 1;
		int left = get_sum(v * 2, tl, tm, l, r);
		if  (left >= sum) {
			return get_left_not_less(v * 2, tl, tm, l, r, sum);
		}
		return get_left_not_less(v * 2 + 1, tm + 1, tr, l, r, sum - left);
	}

	int get_left_not_less(int l, int r, int sum) {
		if  (!sum) {
			return -1;
		}
		return get_left_not_less(1, 0, sz - 1, l, r, sum);
	}

	void upd(int v, int tl, int tr, int pos, int val) {
		if  (tl == tr) {
			t[v] = val;
			return;
		}

		int tm = (tl + tr) >> 1;
		if  (pos <= tm) { 
			upd(v * 2, tl, tm, pos, val);
		} else {
			upd(v * 2 + 1, tm + 1, tr, pos, val);
		}

		t[v] = t[v * 2] + t[v * 2 + 1];
	}

	void upd(int pos, int val) {
		return upd(1, 0, sz - 1, pos, val);
	}
};

const ll INF = 1e18;

struct Arr {
	vii vals;
	FenwTree sum;
	SegmTree alive;

	Arr() {}

	Arr(const vii& a) : vals(a) {
		sort(all(vals));
		sum = FenwTree(sz(vals));
		alive = SegmTree(sz(vals));
	}

	void make_alive(pii val) {
		int pos = lower_bound(all(vals), val) - vals.begin();

		assert(pos < sz(vals) && vals[pos] == val);

		alive.upd(pos, +1);
		sum.inc(pos, +val.fst);
	}

	ll get_sum_pref(int pref) {
		int pos = alive.get_left_not_less(0, sz(vals) - 1, pref);
		if  (pos == -1) {
			return 0;
		}
		if  (pos >= sz(vals)) {
			return INF;
		}
		return sum.get(pos);
	}
};


ll solve() {
	// printf("both:");
	// for (auto x : both) {
	// 	printf("%d ", x.fst);
	// }
	// puts("");
	// forn(it, 2) {
	// 	printf("one[%d]:\n", it);
	// 	for (auto x : one[it]) {
	// 		printf("%d ", x.fst);
	// 	}
	// 	puts("");
	// }
	// for (auto x : rest) {
	// 	printf("%d ", x.fst);
	// }
	// puts("");

	vii vals;
	for (auto x : both) {
		vals.pb(x);
	}
	forn(i, 2) {
		for (auto x : one[i]) {
			vals.pb(x);
		}
	}
	for (auto x : rest) {
		vals.pb(x);
	}
	Arr arr(vals);
	for (auto x : rest) {
		arr.make_alive(x);
	}
	
	int min_cnt = max(0, k - min(sz(one[0]), sz(one[1])));
	if  (min_cnt > sz(both)) {
		return -1;
	}
	ll must = 0;
	forn(i, min_cnt) {
		must += both[i].fst;
	}
	forn(it, 2) {
		forn(i, sz(one[it])) {
			if  (i < k - min_cnt) {
				must += one[it][i].fst;
			} else {
				arr.make_alive(one[it][i]);
			}
		}
	}

	ll ans = INF;
	for (int cnt = min_cnt; cnt <= sz(both); ++cnt) {
		forn(it, 2) {
			assert(sz(one[it]) >= k - cnt);
		}

		int cnt_must = cnt;
		cnt_must += 2 * max(0, k - cnt);

		// printf("cnt=%d, cnt_must=%d, must=%lld\n", cnt, cnt_must, must);

		if  (cnt_must <= m) {
			ll other = arr.get_sum_pref(m - cnt_must);
			// printf("other=%lld, pref=%d\n", other, m - cnt_must);
			if  (other < INF) {
				ans = min(ans, must + other);
			}
		}

		if  (cnt == sz(both)) {
			break;
		}

		const int last = k - cnt - 1;
		if  (last >= 0) {
			forn(it, 2) {
				must -= one[it][last].fst;
				arr.make_alive(one[it][last]);
			}
		}
		must += both[cnt].fst;
	}

	if  (ans >= INF) {
		ans = -1;
	}
	return ans;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		printf("%lld\n", solve());
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}