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

const int MOD = 1e9 + 7;
const int INF = 1e9 + 10;
const int MAXN = 1e6 + 10;

void add(int& x, int y) {
	((x += y) >= MOD) && (x -= MOD);
}

int mul(int x, int y) {
	return x * 1ll * y % MOD;
}

int h[MAXN];
int n;

bool read() {
	if  (scanf("%d", &n) < 1) {
		return false;
	}
	forn(i, n) {
		scanf("%d", &h[i]);
	}
	return true;
}

vector<pair<pii, int>> segs;

void assign(int l, int r, int val) {
	if  (l > r) return;

	vector<pair<pii, int>> nsegs;
	for (const auto& s : segs) {
		int L, R;
		tie(L, R) = s.fst;
		if  (R < l || r < L) {
			nsegs.pb(s);
			continue;
		}
		if  (l <= L && R <= r) {
			continue;
		}
		if  (L < l) {
			nsegs.emplace_back(mp(L, l - 1), s.snd);
		}
		if  (r < R) {
			nsegs.emplace_back(mp(r + 1, R), s.snd);
		}
	}
	nsegs.emplace_back(mp(l, r), val);
	segs.swap(nsegs);

	sort(all(segs));
	nsegs.clear();
	for (const auto& s : segs) {
		if  (!nsegs.empty() && nsegs.back().fst.snd == s.fst.fst - 1 && nsegs.back().snd == s.snd) {
			nsegs.back().fst.snd = s.fst.snd;
		} else {
			nsegs.pb(s);
		}
	}
	segs.swap(nsegs);
}

int get_sum(int l, int r) {
	if  (l > r) return 0;

	int ans = 0;
	for (const auto& s : segs) {
		int L, R;
		tie(L, R) = s.fst;
		L = max(L, l);
		R = min(R, r);
		if  (L <= R) {
			add(ans, mul(R - L + 1, s.snd));
		} 
	}
	return ans;
}

int solve() {
	int ans = 0;
	assign(2, h[0], 1);
	add(ans, get_sum(0, INF));
	for (int i = 1; i < n; ++i) {
		if  (h[i] > h[i - 1]) {
			int s = get_sum(2, h[i - 1]);
			add(s, 1);
			assign(h[i - 1] + 1, h[i], 1);
			assign(2, h[i - 1], s);
		} else {
			int s = get_sum(2, h[i]);
			add(s, 1);
			assign(2, h[i], s);
		}
		assign(h[i] + 1, INF, 0);
		add(ans, get_sum(0, INF));
	}
	return ans;
}

int main() {
#ifdef DEBUG
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		printf("%d\n", solve());
	}

	return 0;
}