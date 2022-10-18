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

struct FenwTree {
	vll t;

	FenwTree(int n = 0) {
		t.assign(n, 0);
	}

	void upd(int pos, ll val) {
		for (int i = pos; i < sz(t); i |= i + 1) {
			t[i] += val;
		}
	}

	ll get(int r) {
		ll res = 0;
		for (int i = r; i >= 0; i &= i + 1, --i) {
			res += t[i];
		}
		return res;
	}

	ll get(int l, int r) {
		if  (l > r) return 0;
		return get(r) - get(l - 1);
	}
};

int n, k, a, b, q;
ll cnt[MAXN];

bool read() {
	if  (scanf("%d%d%d%d%d", &n, &k, &a, &b, &q) < 5) {
		return false;
	}
	return true;
}

void upd(int pos, int add, int lim, FenwTree& t) {
	ll old = min(cnt[pos], (ll) lim);
	ll nw = min(cnt[pos] + add, (ll) lim);
	t.upd(pos, nw - old);
}

void print() {
	forn(i, n) {
		printf("%lld ", cnt[i]);
	}
	puts("");
}

void solve() {
	memset (cnt, 0, sizeof cnt);
	FenwTree ta(n);
	FenwTree tb(n);
	
	forn(i, q) {
		int t;
		scanf("%d", &t);
		if  (t == 1) {
			int d, aa;
			scanf("%d%d", &d, &aa);
			--d;
			upd(d, aa, a, ta);
			upd(d, aa, b, tb);
			cnt[d] += aa;
		} else {
			int p;
			scanf("%d", &p);
			--p;
			int l = p;
			int r = l + k - 1;
			// print();
			// printf("l = %d, b = %d\n", l, b);
			printf("%lld\n", tb.get(l - 1) + ta.get(r + 1, n - 1));
		}
	}
}

int main() {
#ifdef DEBUG
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		solve();
	}

	return 0;
}