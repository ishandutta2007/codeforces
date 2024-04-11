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

struct Hole {
	int x, c;

	void read() {
		scanf("%d%d", &x, &c);
	}

	bool operator < (const Hole& hole) const {
		return x < hole.x;
	}
};

int n, m;
vi xs;
vector<Hole> holes;

bool read() {
	if  (scanf("%d%d", &n, &m) < 2) {
		return 0;
	}
	xs.resize(n);
	forn(i, n) {
		scanf("%d", &xs[i]);
	}
	holes.resize(m);
	forn(i, m) {
		holes[i].read();
	}
	return 1;
}

const int MAXN = 5e3 + 10;
const ll INF = 1e18;

ll dp[MAXN][2];
ll pref[MAXN];

ll cost_to(int l, int r) {
	if  (l > r) {
		return 0;
	}
	ll res = pref[r + 1] - pref[l];
	// printf("l=%d, r=%d -> %lld\n", l, r, res);
	return res;
}

ll solve() {
	sort(all(xs));
	sort(all(holes));
	vector<Hole> nholes;
	for (const auto& hole : holes) {
		if  (nholes.empty() || nholes.back().x < hole.x) {
			nholes.pb(hole);
		} else {
			nholes.back().c += hole.c;
		}
	}
	holes.swap(nholes);
	m = sz(holes);

	// forn(i, n) {
	// 	printf("%d ", xs[i]);
	// }
	// puts("");
	// forn(i, m) {
	// 	printf("%d %d\n", holes[i].x, holes[i].c);
	// }

	forn(i, n + 1) forn(c, 2) {
		dp[i][c] = INF;
	}

	int c = 0;
	forn(j, m + 1) {
		if  (j > 0) {
			pref[0] = 0;
			forn(i, n) {
				pref[i + 1] = pref[i] + abs(xs[i] - 1ll * holes[j - 1].x);
			}
		}

		int opt = 0;
		forn(i, n + 1) {
			if  (!i) {
				dp[i][c] = 0;
				opt = 0;
				continue;
			}
			if  (!j) {
				dp[i][c] = INF;
				opt = 0;
				continue;
			}
			int cnt = opt + 1;
			if  (cnt > holes[j - 1].c) {
				cnt = holes[j - 1].c;
			}
			assert(i >= cnt);
			dp[i][c] = cost_to((i - 1) - cnt + 1, i - 1) + dp[i - cnt][c ^ 1];
			opt = cnt;
			while (cnt >= 1 && cost_to((i - 1) - (cnt - 1) + 1, i - 1) + dp[i - (cnt - 1)][c ^ 1] < dp[i][c]) {
				--cnt;
				dp[i][c] = cost_to((i - 1) - cnt + 1, i - 1) + dp[i - cnt][c ^ 1];
				opt = cnt;
			}
			// for (int cn = cnt - 20; cn <= cnt + 20; ++cn) {
			// 	if  (cn >= 0 && cn <= i && cn <= holes[j - 1].c && cost_to((i - 1) - cn + 1, i - 1) + dp[i - cn][c ^ 1] < dp[i][c]) {
			// 		opt = cn;
			// 		dp[i][c] = cost_to((i - 1) - cn + 1, i - 1) + dp[i - cn][c ^ 1];
			// 	} 
			// }
			// printf("dp[i=%d][j=%d] = %lld\n", i, j, dp[i][c]);
		}

		c ^= 1;
	}

	ll ans = dp[n][c ^ 1];
	if  (ans >= INF) {
		ans = -1;
	}
	return ans;
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