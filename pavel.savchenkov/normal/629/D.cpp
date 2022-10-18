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

struct SegmTree {
	vll t;
	int sz;

	SegmTree(int n = 0) {
		sz = 1;
		while (sz < n) sz *= 2;
		t.assign(sz * 2, 0);
	}

	void put(int pos, ll val) {
		int v = sz + pos;
		t[v] = max(t[v], val);
		v /= 2;
		while (v) {
			t[v] = max(t[v * 2], t[v * 2 + 1]);
			v /= 2;
		}
	}

	ll get_max(int l, int r) {
		ll res = 0;
		l += sz;
		r += sz;
		while (l <= r) {
			res = max(res, t[l]);
			res = max(res, t[r]);
			l = (l + 1) / 2;
			r = (r - 1) / 2;
		}
		return res;
	}
};

const int MAXN = 1e5 + 10;

int r[MAXN];
int h[MAXN];
int n;
vll vals;

bool read() {
	if  (scanf("%d", &n) < 1) {
		return false;
	}
	forn(i, n) {
		scanf("%d%d", &r[i], &h[i]);
	}
	return true;
}

ll solve() {
	vals.clear();
	forn(i, n) {
		vals.pb(r[i] * 1ll * r[i] * 1ll * h[i]);
	}
	sort(all(vals));
	vals.resize(unique(all(vals)) - vals.begin());
	SegmTree T(sz(vals));

	ll ans = 0;
	forn(i, n) {
		ll cur_val = r[i] * 1ll * r[i] * 1ll * h[i];
		int pos = lower_bound(all(vals), cur_val) - vals.begin();
		ll mx = T.get_max(0, pos - 1);
		ans = max(ans, mx + cur_val);
		T.put(pos, mx + cur_val);
	}

	return ans;
}

int main() {
#ifdef DEBUG
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	const double PI = acos(-1);

	while (read()) {
		ll ans = solve();
		printf("%.10f\n", PI * ans);
	}
	
	return 0;
}