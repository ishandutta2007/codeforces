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

struct Seg {
	int u, l, r, s;

	void read() {
		scanf("%d%d%d%d", &u, &l, &r, &s);
		--l;
		--r;
	}

	bool operator < (const Seg& other) const {
		return u < other.u;
	}
};

int h, w, n;
vector<Seg> segs;

bool read() {
	if  (scanf("%d%d%d", &h, &w, &n) < 3) {
		return 0;
	}
	segs.resize(n);
	forn(i, n) {
		segs[i].read();
	}
	return 1;
}

const int INF = 2e9;
const int MOD = 1e9 + 7;

void add(int& x, int y) {
	((x += y) >= MOD) && (x -= MOD);
}

int mul(int x, int y) {
	return x * 1ll * y % MOD;
}

const pair<pii, int> INFP = mp(mp(INF, 0), 0);

struct SegmTree {
	vector<pair<pii, int>> t;
	vector<vector<pair<pii, int>>> s;
	int sz;

	SegmTree(int n = 0) {
		sz = 1;
		while (sz < n) sz *= 2;

		t.assign(sz * 2, INFP);
		s.resize(sz * 2);
	}

	void recalc(int v) {
		t[v] = min(t[v * 2], t[v * 2 + 1]);
	}

	void put(int v, int tl, int tr, int pos, int h, int cnt) {
		if  (tl == tr) {
			assert(pos == tl);
			if  (!s[v].empty() && s[v].back().fst.fst == h) {
				add(s[v].back().fst.snd, cnt);
			} else {
				s[v].pb(mp(mp(h, cnt), pos));
			}
			t[v] = s[v].back();
			return;
		}

		int tm = (tl + tr) >> 1;
		if  (pos <= tm) {
			put(v * 2, tl, tm, pos, h, cnt);
		} else {
			put(v * 2 + 1, tm + 1, tr, pos, h, cnt);
		}
		recalc(v);
	}

	void put(int pos, int h, int cnt) {
		put(1, 0, sz - 1, pos, h, cnt);
	}

	void erase(int v, int tl, int tr, int pos) {
		if  (tl == tr) {
			assert(pos == tl);
			assert(!s[v].empty());
			s[v].pop_back();
			t[v] = s[v].empty() ? INFP : s[v].back();
			return;
		}

		int tm = (tl + tr) >> 1;
		if  (pos <= tm) {
			erase(v * 2, tl, tm, pos);
		} else {
			erase(v * 2 + 1, tm + 1, tr, pos);
		}
		recalc(v);
	}

	pair<pii, int> get_min(int v, int tl, int tr, int l, int r) {
		l = max(l, tl);
		r = min(r, tr);

		if  (l > r) {
			return INFP;
		}

		if  (l == tl && r == tr) {
			return t[v];
		}

		int tm = (tl + tr) >> 1;
		auto res = min(get_min(v * 2, tl, tm, l, r), get_min(v * 2 + 1, tm + 1, tr, l, r));
		recalc(v);
		return res;
	}

	pair<pii, int> get_min(int l, int r) {
		return get_min(1, 0, sz - 1, l, r);
	}

	void erase(int pos) {
		erase(1, 0, sz - 1, pos);
	}

	int get(int v, int tl, int tr) {
		if  (tl == tr) {
			int res = 0;
			for (const auto& it : s[v]) {
				add(res, it.fst.snd);
				// printf("h=%d, cnt=%d, pos=%d\n", it.fst.fst, it.fst.snd, it.snd);
			}
			return res;
		}

		int tm = (tl + tr) >> 1;
		int res = get(v * 2, tl, tm);
		add(res, get(v * 2 + 1, tm + 1, tr));
		return res;
	}

	int get() {
		return get(1, 0, sz - 1);
	}
};


int solve() {
 	SegmTree T(w);
 	forn(i, w) {
 		T.put(i, h + 1, 1);
 	}

 	sort(all(segs));
 	reverse(all(segs));

 	for (const auto& seg : segs) {
 		while (1) {
 			int l = seg.l;
 			int r = seg.r;
 			int u = seg.u;

 			auto mn = T.get_min(seg.l, seg.r);
 			if  (mn.fst.fst >= INF || mn.fst.fst > u + seg.s) {
 				break;
 			}

 			int pos = mn.snd;
 			T.erase(pos);
 			int cnt = mn.fst.snd;

 			if  (l == 0) {
 				T.put(r + 1, u, mul(2, cnt));
 			} else if  (r == w - 1) {
 				T.put(l - 1, u, mul(2, cnt));
 			} else {
 				T.put(l - 1, u, cnt);
 				T.put(r + 1, u, cnt);
 			}
 		}
 	}

 	return T.get();
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		cout << solve() << endl;
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}