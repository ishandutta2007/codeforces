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


const int MAXN = 4e5 + 10;
const ll INF = 2e18;
const ld EPS = 1e-9;

struct Line {
	int a, b;

	ld inter(const Line& l) const {
		assert(a != l.a);
		return (ld) (l.b - b) / (a - l.a);
	}

	Line() {}

	Line(int a, int b) : a(a), b(b) {}

	ll get(int x) {
		return a * 1ll * x + b;
	}
};

struct Hull {
	vector<Line> st;

	void push(const Line& l) {
		while (sz(st) >= 2) {
			const Line& l1 = st[sz(st) - 2];
			const Line& l2 = st[sz(st) - 1];

			if  (l2.a == l.a) {
				if  (l.b > l2.b) {
					st.pop_back();
					continue;
				} else {
					return;
				}
			}

			ld x1 = l1.inter(l2);
			ld x2 = l2.inter(l);
			if  (x2 < x1 + EPS) {
				st.pop_back();
			} else {
				break;
			}
		}
		st.pb(l);
	}

	ll get_best(ll x) {
		int L = -1;
		int R = sz(st) - 1;
		while (L < R - 1) {
			int M = (L + R) / 2;
			ld xx = st[M].inter(st[M + 1]);
			if  (xx < x) {
				L = M;
			} else {
				R = M;
			}
		}
		ll ans = -INF;
		for (int i = max(0, L - 1); i < min(sz(st), R + 2); ++i) {
			ans = max(ans, st[i].get(x));
		}
		return ans;
	}
};

struct Query {
	int type;
	int a, b;
	int i;
	int q;

	int id;

	bool read(int id_) {
		id = id_;
		if  (scanf("%d", &type) < 1) {
			return false;
		}
		if  (type == 1) {
			scanf("%d%d", &a, &b);
		} else if  (type == 2) {
			scanf("%d", &i);
			--i;
		} else {
			assert(type == 3);
			scanf("%d", &q);
		}
		return true;
	}

	bool operator < (const Query& other) const {
		return mp(a, b) < mp(other.a, other.b);
	}
};

vector<Query> qs;
vector<Query> sorted_qs;
bool alive[MAXN];
int n;
bool used[MAXN];

bool read() {
	if  (scanf("%d", &n) < 1) {
		return false;
	}
	qs.resize(n);
	forn(i, n) {
		assert(qs[i].read(i));
	}
	return true;
}

void solve(int l, int r) {
	memset (used, false, sizeof used);
	vi ids;
	for (int i = l; i <= r; ++i) {
		if  (qs[i].type == 2) {
			used[qs[i].i] = true;
			ids.pb(qs[i].i);
		}
		if  (qs[i].type == 1) {
			used[qs[i].id] = true;
			ids.pb(qs[i].id);
		}
	}

	Hull h;
	for (const auto& q : sorted_qs) {
		assert(q.type == 1);
		if  (alive[q.id] && !used[q.id]) {
			h.push(Line(q.a, q.b));
		}
	}

	for (int i = l; i <= r; ++i) {
		if  (qs[i].type != 3) {
			if  (qs[i].type == 2) {
				alive[qs[i].i] = false;
			} else {
				alive[qs[i].id] = true;
			}
			continue;
		}
		ll ans = -INF;
		int x = qs[i].q;
		for (int j : ids) {
			assert(qs[j].type == 1);
			if  (alive[j]) {
				ans = max(ans, Line(qs[j].a, qs[j].b).get(x));
			}
		}
		ans = max(ans, h.get_best(x));

		if  (ans == -INF) {
			printf("EMPTY SET\n");
		} else {
			printf("%lld\n", ans);
		}
	}
}

const int K = 3000;

void solve() {
	for (const auto& q : qs) {
		if  (q.type == 1) {
			sorted_qs.pb(q);
		}
	}
	sort(all(sorted_qs));

	for (int l = 0; l < sz(qs); l += K) {
		int r = min(sz(qs) - 1, l + K - 1);
		solve(l, r);
	}
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		solve();
	}

#ifdef LOCAL
	printf("Time: %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}