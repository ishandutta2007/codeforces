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

#define TEST 0

ll L, R;

bool read() {
#if TEST
	const ll M = ll(1e18);
	// L = M - rand() % 100;
	// R = M - rand() % 5;
	L = 1 + rand() % 10000;
	R = L + rand() % 10000;
	if  (L > R) {
		swap(L, R);
	}
	return 1;
#else
	if  (scanf("%lld%lld", &L, &R) < 2) {
		return 0;
	}
	return 1;
#endif
}

const int LEN = 18;

struct Mask {
	int cnt[10];
	int cnt_pos;
	int len;

	Mask() {
		clear();
	}

	Mask(const vi& num) {
		clear();
		for (int d : num) {
			upd(d, 1);
		}
		len = LEN - sz(num);
		for (int d : num) {
			if  (d) {
				++len;
			}
		}
	}

	void print() const {
		eprintf("mask:\n");
		forn(d, 10) {
			forn(it, cnt[d]) {
				eprintf("%d", d);
			}
		}
		eprintf("\n");
		eprintf("len = %d\n\n", len);
	}

	void clear() {
		memset (cnt, 0, sizeof cnt);	
		cnt_pos = 0;
		len = 0;
	}

	void upd(int d, int val) {
		assert(0 <= d && d < 10);
		if  (!d) {
			return;
		}
		cnt_pos -= cnt[d] > 0;
		cnt[d] += val;
		cnt_pos += cnt[d] > 0;
	}

	bool operator < (const Mask& mask) const {
		forn(i, 10) {
			if  (cnt[i] != mask.cnt[i]) {
				return cnt[i] < mask.cnt[i];
			}
		}
		if  (len != mask.len) {
			return len < mask.len;
		}
		return 0;
	}

	bool operator == (const Mask& mask) const {
		forn(i, 10) {
			if  (cnt[i] != mask.cnt[i]) {
				return 0;
			}
		}
		if  (len != mask.len) {
			return 0;
		}
		return 1;
	}	
};

vll nums;

void rec(int len, ll num, int last, vector<Mask>& masks, int ptr) {
	while (ptr < sz(masks) && len > masks[ptr].len) {
		++ptr;
	}
	for (int i = ptr; i < sz(masks); ++i) {
		if  (masks[i].cnt_pos == 0) {
			nums.pb(num);
			break;
		}
	}
	if  (len == LEN) {
		return;
	}
	for (int next = last; next < 10; ++next) {
		for (int i = 0; i < sz(masks); ++i) {
			masks[i].upd(next, -1);
		}
		rec(len + 1, num * 10 + next, next, masks, ptr);
		for (int i = 0; i < sz(masks); ++i) {
			masks[i].upd(next, +1);
		}
	}
}


vi parse(ll x, int len) {
	vi res;
	forn(it, len) {
		res.pb(x % 10);
		x /= 10;
	}
	assert(x == 0);
	reverse(all(res));
	return res;
}

bool check_greater(const vi& left, const vi& right) {
	forn(i, sz(right)) {
		if  (right[i] < left[i]) {
			return 0;
		}
		if  (right[i] > left[i]) {
			return 1;
		}
	}
	return 0;
}

bool check_less(const vi& left, const vi& right) {
	forn(i, sz(right)) {
		if  (right[i] < left[i]) {
			return 1;
		}
		if  (right[i] > left[i]) {
			return 0;
		}
	}
	return 0;
}

int solve() {
	const ll MAX = ll(1e18);

	if  (L == MAX) {
		return 1;
	}

	bool BIG = R == MAX;

	if  (BIG) {
		--R;
	}

	assert(L <= R);
	assert(R < MAX);

	vi left = parse(L, LEN);

	vi right = parse(R, LEN);

	vector<Mask> masks;
	forn(pref_left, sz(left)) forn(pref_right, sz(right)) {
		vi cur;
		forn(z, max(pref_left, pref_right)) {
			if  (pref_left > pref_right) {
				cur.pb(left[z]);
			} else {
				cur.pb(right[z]);
			}
		}

		forn(next, 10) {
			cur.pb(next);

			bool bad = 0;
			if  (!check_greater(left, cur)) {
				bad = 1;
			}
			if  (!check_less(right, cur)) {
				bad = 1;
			}

			if  (!bad) {
				masks.pb(Mask(cur));
			}
			cur.pop_back();
		}
	}

	masks.pb(Mask(left));
	masks.pb(Mask(right));

	sort(all(masks));
	masks.resize(unique(all(masks)) - masks.begin());

	sort(all(masks), [](const Mask& m1, const Mask& m2) { return m1.len < m2.len; });
	// for (auto mask : masks) {
	// 	mask.print();
	// }
	// eprintf("cnt masks = %d\n", sz(masks));

	vector<bool> bad(sz(masks), 0);
	forn(i, sz(masks)) forn(j, sz(masks)) {
		if  (masks[i].len < masks[j].len || i == j) {
			continue;
		}
		bool i_better = 1;
		forn(d, 10) {
			if  (masks[i].cnt[d] > masks[j].cnt[d]) {
				i_better = 0;
				break;
			}
		}
		if  (masks[i] == masks[j]) {
			if  (i < j) {
				continue;
			}
		}
		if  (i_better) {
			bad[j] = 1;
		}
	}
	vector<Mask> nmasks;
	forn(i, sz(masks)) {
		if  (!bad[i]) {
			nmasks.pb(masks[i]);
		}
	}
	masks.swap(nmasks);
	sort(all(masks), [](const Mask& m1, const Mask& m2) { return m1.len < m2.len; });

	// eprintf("cnt masks = %d\n", sz(masks));

	nums.clear();
	int ptr = 0;
	rec(0, 0, 1, masks, ptr);

	if  (BIG) {
		nums.pb(1);
		++R;
	}

	sort(all(nums));
	nums.resize(unique(all(nums)) - nums.begin());

	return sz(nums);
}

int brut(ll L, ll R) {
	set<vi> S;
	for (ll x = L; x <= R; ++x) {
		vi d = parse(x, 20);
		vi nd;
		for (int dd : d) {
			if  (dd) {
				nd.pb(dd);
			}
		}
		sort(all(nd));

		assert(sz(nd));
		S.insert(nd);
	}
	return sz(S);
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

#if TEST
	while (1) {
		read();

		int br = brut(L, R);

		int my = solve();
		
		if  (my == br) {
			printf("%d == %d, L=%lld, R=%lld\n", my, br, L, R);
			continue;
		}

		printf("my=%d, br=%d, L=%lld, R=%lld\n", my, br, L, R);
		exit(0);
	}
#endif

	while (read()) {
		printf("%d\n", solve());

		// printf("brut = %d\n", brut(L, R));
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}