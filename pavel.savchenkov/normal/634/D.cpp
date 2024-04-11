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

struct Gas {
	int x, p;

	bool operator < (const Gas& g) const {
		return x < g.x;
	}
};

int d, n, m;
vector<Gas> gs;
vi nxt;

bool read() {
	if  (scanf("%d%d%d", &d, &n, &m) < 3) {
		return false;
	}
	gs.resize(m);
	forn(i, m) {
		scanf("%d%d", &gs[i].x, &gs[i].p);
	}
	return true;
}

ll solve() {
	sort(all(gs));

	nxt.assign(m, -1);
	vi st;
	ford(i, m) {
		int L = -1;
		int R = sz(st);
		while (L != R - 1) {
			int M = (L + R) / 2;
			int id = st[M];
			if  (gs[id].p <= gs[i].p) {
				L = M;
			} else {
				R = M;
			}
		}
		if  (0 <= L && L < sz(st) && gs[st[L]].p <= gs[i].p) {
			nxt[i] = st[L];
		}
		while (!st.empty() && gs[i].p <= gs[st.back()].p) {
			st.pop_back();
		}
		st.pb(i);
	}

	const ll INF = 1e18;
	ll res = INF;
	ll have = n;
	ll ans = 0;
	if  (gs[0].x > n) {
		return -1;
	}
	have -= gs[0].x;
	int i = 0;
	while (i < m) {
		if  (d - gs[i].x <= n) {
			ll need = max(0ll, d - gs[i].x - have);
			res = min(res, ans + need * gs[i].p);
		}
		if  (i == m - 1) {
			break;
		}

		if  (gs[i + 1].x - gs[i].x > n) return -1;

		if  (nxt[i] == -1 || gs[nxt[i]].x - gs[i].x > n) {
			ans += (n - have) * 1ll * gs[i].p;
			have = n;
			have -= (gs[i + 1].x - gs[i].x);
			i = i + 1;
			continue;
		}

		ll need = max(0ll, gs[nxt[i]].x - gs[i].x - have);
		ans += need * gs[i].p;
		have += need;
		have -= (gs[i + 1].x - gs[i].x);
		i = i + 1;
	}

	return res >= INF ? -1 : res;
}

int main() {
#ifdef DEBUG
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		cout << solve() << endl;
	}
	return 0;
}