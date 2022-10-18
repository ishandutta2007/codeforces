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

const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;

void add(int& x, int y) {
	((x += y) >= MOD) && (x -= MOD);
}

int mul(int x, int y) {
	return x * 1ll * y % MOD;
}

int n, m;
vvi g;

bool read() {
	if  (scanf("%d%d", &n, &m) < 1) {
		return 0;
	}
	g.clear();
	g.resize(n);
	forn(i, n) {
		int cnt;
		scanf("%d", &cnt);
		forn(j, cnt) {
			int x;
			scanf("%d", &x);
			--x;
			g[i].pb(x);
		}
	}
	return 1;
}

int fact[MAXN];

void precalc() {
	fact[0] = 1;
	for (int i = 1; i < MAXN; ++i) {
		fact[i] = mul(fact[i - 1], i);
	}
}

vector<vii> hs;

int solve() {
	precalc();


	hs.clear();
	hs.resize(m);

	forn(it, n) {
		sort(all(g[it]));
		const auto& v = g[it];
		for (int i = 0, j = 0; i < sz(v); i = j) {
			while (j < sz(v) && v[i] == v[j]) {
				++j;
			}
			hs[v[i]].pb(mp(it + 1, j - i));
		}
	}

	map<pair<int, ull>, int> cnt;
	forn(i, m) {
		int h1 = 0;
		ull h2 = 0;
		const int P1 = 1e5 + 19;
		const ull P2 = 1e6 + 3;
		int p1 = 1;
		ull p2 = 1;

		for (const auto& it : hs[i]) {
			add(h1, it.fst * p1);
			h2 += it.fst * p2;

			p1 = mul(p1, P1);
			p2 *= P2;

			add(h1, it.snd * p1);
			h2 += it.snd * p2;

			p1 = mul(p1, P1);
			p2 *= P2; 
		}

		++cnt[mp(h1, h2)];
	}

	int ans = 1;
	for (const auto& it : cnt) {
		ans = mul(ans, fact[it.snd]);
	}
	return ans;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif


	while (read()) {
		printf("%d\n", solve());
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}