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
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
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


const int MAXN = 3e5 + 10;

set<int> s;
vi who[MAXN];
int n, q;

bool read() {
	if  (scanf("%d%d", &n, &q) < 2) {
		return false;
	}
	return true;
}

void solve() {
	vi t1;
	forn(i, q) {
		int t;
		scanf("%d", &t);
		if  (t == 1) {
			int x;
			scanf("%d", &x);
			--x;
			who[x].pb(i);
			s.insert(i);
			t1.pb(i);
		} else if  (t == 2) {
			int x;
			scanf("%d", &x);
			--x;
			for (int w : who[x]) {
				s.erase(w);
			}
			who[x].clear();
		} else {
			int cnt;
			scanf("%d", &cnt);
			int lim = t1[cnt - 1];
			while (!s.empty() && *s.begin() <= lim) {
				s.erase(s.begin());
			}
		}
		printf("%d\n", sz(s));
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
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}