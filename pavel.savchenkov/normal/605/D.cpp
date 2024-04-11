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
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef vector <vector <int> > vvi;
typedef vector <pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

#define FILE_NAME "a"

const ld EPS = 1e-9;

struct SegmTree {
	vii t;
	int sz;

	SegmTree(int n = 0) {
		sz = 1;
		while (sz < n) sz *= 2;
		t.assign(sz * 2, mp(-1, 0));
	}

	void put(int pos, int val) {
		int v = sz + pos;
		t[v] = mp(val, pos);
		v /= 2;
		while (v) {
			t[v] = max(t[v * 2], t[v * 2 + 1]);
			v /= 2;
		}
	}

	pii get_max(int l, int r) {
		pii res(-1, 0);
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

int a[MAXN];
int b[MAXN];
int c[MAXN];
int d[MAXN];
int n;
SegmTree T;
vii x;

bool read() {
	if  (scanf("%d", &n) < 1) {
		return false;
	}
	forn(i, n) {
		scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
	}
	return true;
}

void build() {
	forn(i, n) {
		x.pb(mp(c[i], i));
	}
	sort(all(x));
	T = SegmTree(sz(x));
	forn(i, n) {
		int pos = lower_bound(all(x), mp(c[i], i)) - x.begin();
		assert(pos < sz(x));
		assert(x[pos] == mp(c[i], i));
		T.put(pos, d[i]);
	}
}

vi solve() {
	build();

	vi nxt(n, -1);
	vi ps;
	ps.pb(n - 1);
	int pos = lower_bound(all(x), mp(c[n - 1], n - 1)) - x.begin();
	T.put(pos, -1);
	for (int it = 0; !ps.empty(); ++it) {
		// printf("it = %d\n", it);
		for (int i : ps) {
			if  (a[i] == 0 && b[i] == 0) {
				vi ans;
				for (int j = i; j != -1; j = nxt[j]) {
					ans.pb(j);
				}
				return ans;
			}
		}

		vi nps;
		for (int i : ps) {
			int low_x = a[i];
			int low_y = b[i];
			low_x = upper_bound(all(x), mp(low_x, -1)) - x.begin();
			while (1) {
				pii cur = T.get_max(low_x, sz(x) - 1);
				if  (cur.fst < low_y) {
					break;
				}
				int id = x[cur.snd].snd;
				nxt[id] = i;
				nps.pb(id);
				T.put(cur.snd, -1);
			}
		}

		ps.swap(nps);
	}

	return {};
}

int main() {
//	freopen(FILE_NAME ".in", "r", stdin);
//	freopen(FILE_NAME ".out", "w", stdout);
  
  	while (read()) {
  		vi ans = solve();
  		if  (ans.empty()) {
  			puts("-1");
  		} else {
  			printf("%d\n", sz(ans));
  			for (int i : ans) {
  				printf("%d ", i + 1);
  			}
  			puts("");
  		}
  	}
	return 0;
}