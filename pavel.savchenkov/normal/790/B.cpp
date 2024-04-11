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

const int MAXN = 4e5 + 10;

int n, k;
vi g[MAXN];

bool read() {
	if  (scanf("%d%d", &n, &k) < 2) {
		return 0;
	}
	forn(i, n) {
		g[i].clear();
	}
	forn(i, n - 1) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		g[a].pb(b);
		g[b].pb(a);
	}
	return 1;
}

const int K = 5;

struct Info {
	int cnt[K];
	ll sum[K];

	Info() {
		memset (cnt, 0, sizeof cnt);
		memset (sum, 0, sizeof sum);
	}

	Info& operator += (const Info& other) {
		forn(r, k) {
			cnt[r] += other.cnt[r];
			sum[r] += other.sum[r];
		}
		return *this;
	}

	Info& operator -= (const Info& other) {
		forn(r, k) {
			cnt[r] -= other.cnt[r];
			sum[r] -= other.sum[r];
		}
		return *this;
	}

	Info move() {
		Info res;
		forn(r, k) {
			res.cnt[(r + 1) % k] = cnt[r];
			res.sum[(r + 1) % k] = sum[r];
			res.sum[(r + 1) % k] += cnt[r];
		}
		return res;
	}

	ll calc() const {
		ll ans = 0;
		forn(r, k) {
			ans += (sum[r] - cnt[r] * 1ll * r) / k;
			if  (r) {
				ans += cnt[r];
			}
		}
		return ans;
	}

	void print() const {
		forn(r, k) {
			printf("%d ", cnt[r]);
		}
		puts("");
		forn(r, k) {
			printf("%lld ", sum[r]);
		}
		puts("");
		puts("");
	}
};

Info dp[MAXN];

void dfs0(int v, int p) {
	dp[v] = Info();
	dp[v].cnt[0] = 1;

	for (int to : g[v]) {
		if  (to == p) {
			continue;
		}
		dfs0(to, v);
		dp[v] += dp[to].move();
	}

	// printf("v=%d, dp=\n", v + 1);
	// dp[v].print();
}

ll ans;

void dfs(int v, int p, Info up) {
	++up.cnt[0];

	Info down;
	for (int to : g[v]) {
		if  (to == p) {
			continue;
		}

		down += dp[to].move();
	}

	ans += up.calc();
	ans += down.calc();

	up += down;
	for (int to : g[v]) {
		if  (to == p) {
			continue;
		}

		auto cur = dp[to].move();
		up -= cur;

		dfs(to, v, up.move());

		up += cur;
	}
}

void solve() {
	dfs0(0, -1);

	ans = 0;
	Info up;

	dfs(0, -1, up);

	cout << ans / 2 << endl;
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
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}