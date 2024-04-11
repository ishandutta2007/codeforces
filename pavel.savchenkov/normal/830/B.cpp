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


int n;
vi a;

bool read() {
	if  (scanf("%d", &n) < 1) {
		return 0;
	}
	a.resize(n);
	forn(i, n) {
		scanf("%d", &a[i]);
		--a[i];
	}
	return 1;
}

struct FenwTree {
	vi t;

	FenwTree(int n = 0) {
		t.assign(n, 0);
	}

	int get(int r) {
		int s = 0;
		for (int i = r; i >= 0; i &= i + 1, --i) {
			s += t[i];
		}
		return s;
	}

	int get(int l, int r) {
		if  (l > r) {
			return 0;
		}
		return get(r) - get(l - 1);
	}

	void inc(int pos, int val) {
		for (int i = pos; i < sz(t); i |= i + 1) {
			t[i] += val;
		}
	}
};

vvi poses;
FenwTree T;

int get_next(int pos, int val) {
	if  (poses[val].back() < pos) {
		return poses[val].front();
	}
	int p = lower_bound(all(poses[val]), pos) - poses[val].begin();
	return poses[val][p];
}

int dist(int from, int to) {
	if  (from <= to) {
		return T.get(from + 1, to - 1);
	}
	return T.get(from + 1, n - 1) + T.get(0, to - 1);
}

ll solve() {
	poses.clear();

	const int mx = *max_element(all(a));
	poses.resize(mx + 1);
	forn(i, n) {
		poses.at(a[i]).pb(i);
	}

	vi vals = a;
	sort(all(vals));

	int pos = get_next(0, vals[0]);
	vi perm;
	for (int val : vals) {
		pos = get_next(pos, val);
		assert(pos != -1);
		assert(a[pos] == val);
		perm.pb(pos);
		pos = (pos + 1) % n;
	}
	for (int p : perm) {
		eprintf("%d ", p);
	}
	eprintf("\n");

	T = FenwTree(n);
	forn(i, n) {
		T.inc(i, 1);
	}
	ll ans = perm[0];
	forn(i, sz(perm)) {
		++ans;
		eprintf("++\n");
		if  (i + 1 == sz(perm)) {
			break;
		}
		ll cur = dist(perm[i], perm[i + 1]);
		eprintf("%d -> %d, cur=%lld\n", perm[i], perm[i + 1], cur);
		ans += cur;
		T.inc(perm[i], -1);
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