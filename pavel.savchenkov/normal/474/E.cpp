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

using namespace std;

#define PB push_back
#define f first
#define s second
#define mp make_pair 
#define SZ(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define FORD(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define ALL(C) begin(C), end(C)

#define DEBUG(x) cerr << #x" = " << x << '\n';

#define prev djfhsjdkfhkjsdkfsj

template <typename T>
inline T sqr( T x ) {
	return x * x;
}

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef vector <vector <int> > vvi;
typedef vector <pii> vii;
typedef vector <vector<pii> > vvii;

const double EPS = 1e-9;
const int MAXN = int(1e5 + 5);

struct SegmTree {
	vii t;

	SegmTree( int n = 0 ) {
		int sz = 1;
		while (sz < n) sz <<= 1;

		t.assign(sz << 1, mp(0, 0));	
	}	

	void upd( int pos, int val ) {
		int sz = SZ(t) >> 1;

		pos += sz;
		t[pos] = mp(val, pos - sz);
		pos >>= 1;

		while (pos) {
			t[pos] = max(t[pos << 1], t[1 + (pos << 1)]);
			pos >>= 1;
		}
	}

	pii get( int l, int r ) {
		int sz = SZ(t) >> 1;

		pii res = mp(0, -1);

		l += sz;
		r += sz;

		while (l <= r) {
			res = max(res, t[l]);
			res = max(res, t[r]);

			r = (r - 1) >> 1;
			l = (l + 1) >> 1;
		}

		return res;
	}
};

SegmTree T;
ll h[MAXN];
ll H[MAXN];
ll prev[MAXN];
int n, d;

int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	scanf("%d%d", &n, &d);

	forn(i, n) {
    	scanf("%I64d", &h[i]);
    	H[i] = h[i];
    }

    sort(H, H + n);

    T = SegmTree(n);

    memset (prev, -1, sizeof prev);

    forn(i, n) {
    	int cur = 0;
    	ll mn = h[i] - d;

    	int pos = upper_bound(H, H + n, mn) - H;
    	--pos;

    	if  (pos >= 0) {
    		pii p = T.get(0, pos);
    		if  (p.f > cur) {
    			prev[i] = H[p.s];
    			cur = p.f;
    		}
    	}

    	ll mx = h[i] + d;
    	pos = lower_bound(H, H + n, mx) - H;

    	if  (pos < n) {
    		pii p = T.get(pos, n - 1);
    		if  (p.f > cur) {
    			prev[i] = H[p.s];
    			cur = p.f;
    		}
    	}

    	T.upd(lower_bound(H, H + n, h[i]) - H, cur + 1);
    }

    pii res = T.get(0, n - 1);

    cout << res.f << '\n';

	vector <ll> ans;

	ll cur_h = H[res.s];

	FORD(i, n) {
		if  (h[i] == cur_h) {
			ans.PB(i);

			cur_h = prev[i];
		}
	}

	FORD(i, SZ(ans)) {
		cout << ans[i] + 1 << ' ';
	}

	return 0;
}