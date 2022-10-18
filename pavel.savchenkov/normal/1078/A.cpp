#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <memory.h>
#include <algorithm>
#include <cassert>
#include <numeric>
#include <functional>
#include <queue>
#include <cmath>

using namespace std;

#define prev prev_______________________
#define next next_______________________
#define hash hash_______________________
#define y1 y1___________________________

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define all(c) (c).begin(), (c).end()
#define sz(c) int((c).size())
#define mp(x, y) make_pair(x, y)
#define pb push_back
#define fst first
#define snd second

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;

#ifdef LOCAL
#define eprintf(args...) fprintf(stderr, args), fflush(stderr);
#else
#define eprintf(args...) ;
#define cerr if (0) cerr
#endif

using ld = long double;

const ld EPS = 1e-8;

struct pnt {
    ld x, y;

    bool read() {
        if (!(cin >> x >> y)) {
            return 0;
        }
        return 1;
    }
};

struct line {
    ld a, b, c;

    bool read() {
        if (!(cin >> a >> b >> c)) {
        	return 0;
        }
        return 1;
    }

    bool inter_x(ld x, ld y, pnt& res) const {
    	if (fabs(b) < EPS) {
    		if (fabs(a * x + c) < EPS) {
    			res = pnt{x, y};
    			return 1;
    		}
    		return 0;
    	}
    	ld yy = (-a * x - c) / b;
    	res = pnt{x, yy};
    	return 1;
    }

    bool inter_y(ld x, ld y, pnt& res) const {
    	if (fabs(a) < EPS) {
    		if (fabs(b * y + c) < EPS) {
    			res = pnt{x, y};
    			return 1;
    		}
    		return 0;
    	}
    	ld xx = (-b * y - c) / a;
    	res = pnt{xx, y};
    	return 1;
    }
};

line l;
pnt A, B;

bool read() {
    if (!l.read()) {
        return 0;
    }
    assert(A.read());
    assert(B.read());
    return 1;
}

ld dist(pnt a, pnt b) {
	return fabs(a.x - b.x) + fabs(a.y - b.y);
}

void solve() {
	ld ans = dist(A, B);
	vector<pnt> ps;

	for (pnt p : {A, B}) {
		pnt cur;
		if (l.inter_x(p.x, p.y, cur)) {
			ps.pb(cur);
		}
		if (l.inter_y(p.x, p.y, cur)) {
			ps.pb(cur);
		}
	}

	for (auto p1 : ps) {
		for (auto p2 : ps) {
			ld d = dist(A, p1);

			ld dx = p1.x - p2.x;
			ld dy = p1.y - p2.y;
			d += sqrt(dx * dx + dy * dy);

			d += dist(p2, B);

			ans = min(ans, d);
		}
	}

	cout << double(ans) << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cout.precision(20);
    cout << fixed;

#ifdef LOCAL
    #define FNAME "a"
    freopen(FNAME ".in", "r", stdin);
    // freopen(FNAME ".out", "w", stdout);
#endif

    while (read()) {
        solve();
    }

    return 0;
}