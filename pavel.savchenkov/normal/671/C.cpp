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


const int MAXN = 2e5 + 10;

struct SegmTreeMax {
	vii t;
	int sz;

	SegmTreeMax(int n = 0) {
		sz = 1;
		while (sz < n) sz *= 2;
		t.assign(sz * 2, mp(0, 0)); 
	}

	void put(int pos, int val) {
		int v = sz + pos;
		t[v] = mp(val, pos);
		v >>= 1;
		while (v) {
			t[v] = max(t[v * 2], t[v * 2 + 1]);
			v >>= 1;
		}
	}

	int get_right_greater(int v, int tl, int tr, int l, int r, int val) {
		l = max(l, tl);
		r = min(r, tr);
		if  (l > r) {
			return -1;
		}

		if  (t[v].fst < val) {
			return -1;
		}

		if  (tl == tr) {
			return tl;
		}

		int tm = (tl + tr) >> 1;
		int right = get_right_greater(v * 2 + 1, tm + 1, tr, l, r, val);
		if  (right != -1) {
			return right;
		}
		return get_right_greater(v * 2, tl, tm, l, r, val);
	}

	int get_right_greater(int l, int r, int val) {
		int pos = get_right_greater(1, 0, sz - 1, l, r, val);
		if  (pos == -1) {
			return l - 1;
		}
		return pos;
	}

	int get_max(int l, int r) {
		l += sz;
		r += sz;
		int res = 0;
		while (l <= r) {
			res = max(res, t[l].fst);
			res = max(res, t[r].fst);
			l = (l + 1) >> 1;
			r = (r - 1) >> 1;
		}
		return res;
	}
};

struct SegmTreeSum {
	vll sum;
	vi put;
	int sz;

	SegmTreeSum(int n = 0) {
		sz = 1;
		while (sz < n) sz *= 2;
		sum.assign(sz * 2, 0);
		put.assign(sz * 2, 0);
	}

	void push(int v, int tl, int tr) {
		if  (put[v] == -1) {
			return;
		}
		int len = (tr - tl + 1);
		sum[v * 2] = (len / 2) * 1ll * put[v];
		put[v * 2] = put[v];
		sum[v * 2 + 1] = (len / 2) * 1ll * put[v];
		put[v * 2 + 1] = put[v];
		put[v] = -1;
	}

	void recalc(int v) {
		assert(put[v] == -1);
		sum[v] = sum[v * 2] + sum[v * 2 + 1];
	} 

	void go_put(int v, int tl, int tr, int l, int r, int val) {
		l = max(l, tl);
		r = min(r, tr);
		if  (l > r) {
			return;
		}

		if  (l == tl && r == tr) {
			sum[v] = val * 1ll * (tr - tl + 1);
			put[v] = val;
			return;
		}

		push(v, tl, tr);

		int tm = (tl + tr) >> 1;
		go_put(v * 2, tl, tm, l, r, val);
		go_put(v * 2 + 1, tm + 1, tr, l, r, val);
		recalc(v);
	}

	void go_put(int l, int r, int val) {
		go_put(1, 0, sz - 1, l, r, val);
	}

	ll get_sum(int v, int tl, int tr, int l, int r) {
		l = max(l, tl);
		r = min(r, tr);
		if  (l > r) {
			return 0;
		}
		if  (l == tl && r == tr) {
			return sum[v];
		}

		push(v, tl, tr);

		int tm = (tl + tr) >> 1;
		ll res = get_sum(v * 2, tl, tm, l, r) + get_sum(v * 2 + 1, tm + 1, tr, l, r);
		recalc(v);
		return res;
	}

	ll get_sum(int l, int r) {
		return get_sum(1, 0, sz - 1, l, r);
	}
};

vi divs[MAXN];
int a[MAXN];
int n;
bool was[MAXN];

void precalc() {
	int mx = 0;
	for (int i = 1; i < MAXN; ++i) {
		for (int j = i; j < MAXN; j += i) {
			divs[j].pb(i);
		}
		mx = max(mx, sz(divs[i]));
	}
	// cout << mx << endl;
}

int pref[MAXN];
int suff[MAXN];
int right_pos[MAXN];

void precalc2() {
	memset (was, false, sizeof was);
	forn(i, n) {
		int mx = 0;
		int x = a[i];
		for (int d : divs[x]) {
			if  (was[d]) {
				mx = d;
			}
			was[d] = true;
		}
		pref[i] = mx;
		if  (i > 0) {
			pref[i] = max(pref[i], pref[i - 1]);
		}
	}

	memset (was, false, sizeof was);
	ford(i, n) {
		int mx = 0;
		int x = a[i];
		for (int d : divs[x]) {
			if  (was[d]) {
				mx = d;
			}
			was[d] = true;
		}
		suff[i] = mx;
		if  (i + 1 < n) {
			suff[i] = max(suff[i], suff[i + 1]);
		}
	}

	forn(i, MAXN) {
		right_pos[i] = -1;
	}
	ford(i, n) {
		for (int d : divs[a[i]]) {
			if  (right_pos[d] == -1) {
				right_pos[d] = i;
			}
		}
	}
}

SegmTreeSum t_sum;
SegmTreeMax t_max;
int t_max_[MAXN];

void try_val(int d, int pos) {
	if  (t_max.get_max(pos, n - 1) >= d) {
		return;
	}

	int rpos = t_max.get_right_greater(0, pos, d);
	t_sum.go_put(rpos + 1, pos, d);
	if  (rpos + 1 <= pos) {
		t_max.put(pos, d);
		t_max_[pos] = d;
		// printf("[%d] := %d\n", pos, d);
	}
}

ll brut() {
	ll ans = 0;
	forn(i, n) for (int j = i; j < n; ++j) {
		vi cur;
		forn(k, n) {
			if  (k < i || j < k) {
				cur.pb(a[k]);
			}
		}

		int mx = 0;
		forn(ii, sz(cur)) forn(jj, sz(cur)) {
			if  (ii != jj) {
				mx = max(mx, __gcd(cur[ii], cur[jj]));
			}
		}

		printf("i=%d, j=%d, mx=%d\n", i, j, mx);
		ans += mx;
	}

	return ans;
}

ll solve() {
	precalc2();

	// forn(i, n) {
	// 	printf("pref[%d] = %d, suff[%d] = %d\n", i, pref[i], i, suff[i]);
	// }

	t_sum = SegmTreeSum(n);
	t_max = SegmTreeMax(n);
	forn(i, n) {
		t_max_[i] = 0;
	}

	ll ans = 0;
	for (int i = 1; i + 1 < n; ++i) {
		ans += pref[i];
		ans += suff[i];
	}

	forn(i, n) {
		try_val(i + 1 == n ? 0 : suff[i], i);
	}

	memset (was, false, sizeof was);
	forn(i, n) {
		if  (!was[a[i]]) {
			for (int d : divs[a[i]]) {
				int pos = right_pos[d];
				if  (pos > i + 1) {
					try_val(d, pos);
				}
			}
		}
		try_val(pref[i], n - 1);
		was[a[i]] = true;

		// printf("add i=%d\n", i);
		// printf("t_max:\n");
		// forn(j, n) {
		// 	printf("%d ", t_max_[j]);
		// }
		// puts("");
		ll add = t_sum.get_sum(i + 2, n - 1);
		// printf("add = %lld\n", add);
		ans += add;
	}

	return ans;
}

void read() {
	// n = rand() % 50 + 2;
	// forn(i, n) {
	// 	a[i] = rand() % 100 + 2;
	// }
	// return;

	scanf("%d", &n);
	forn(i, n) {
		scanf("%d", &a[i]);
	}
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	precalc();

	read();
	cout << solve() << endl;
	return 0;
	
	while (1) {
		read();
		ll my = solve();
		ll corr = brut();
		if  (my != corr) {
			printf("at n=%d\n", n);
			forn(i, n) {
				printf("%d ", a[i]);
			}
			puts("");
			cout << my << " != " << corr << endl; 
			return 0;
		}
		printf("ok n=%d\n", n);
	}

	return 0;
}