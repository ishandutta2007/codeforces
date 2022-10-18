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

#ifdef LOCAL
#define eprintf(args...) fprintf(stderr, args), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define FILE_NAME "a"

struct Dancer {
	int coord;
	int t;
	int id;

	bool operator < (const Dancer& d) const {
		return coord < d.coord;
	}
};

int n, w, h;
vector<Dancer> vers;
vector<Dancer> hors;

bool read() {
	if  (scanf("%d%d%d", &n, &w, &h) < 3) {
		return 0;
	}
	vers.clear();
	hors.clear();
	forn(i, n) {
		int g, p, t;
		scanf("%d%d%d", &g, &p, &t);
		if  (g == 1) {
			vers.pb(Dancer{p, t, i});
		} else {
			hors.pb(Dancer{p, t, i});
		}
	}
	return 1;
}

vii ans;

void solve_all(vector<Dancer> vers, vector<Dancer> hors) {
	sort(all(vers));
	sort(all(hors));

	// printf("sz: %d %d\n", sz(vers), sz(hors));

	forn(i, sz(vers)) {
		int right = sz(vers) - i;
		int up = sz(hors);

		// printf("id=%d, right=%d, up=%d\n", vers[i].id, right, up);

		if  (right <= up) {
			ans[vers[i].id] = mp(w, hors.at(right - 1).coord);
		} else {
			ans[vers[i].id] = mp(vers.at(i + up).coord, h);
		}
	}

	forn(i, sz(hors)) {
		int right = sz(hors) - i;
		int up = sz(vers);

		if  (right <= up) {
			ans[hors[i].id] = mp(vers.at(right - 1).coord, h);
		} else {
			ans[hors[i].id] = mp(w, hors.at(i + up).coord);
		}
	}
}

void solve() {
	ans.resize(n);

	set<int> keys;
	map<int, vector<Dancer>> group_hors;
	map<int, vector<Dancer>> group_vers;
	for (const auto& ver : vers) {
		group_vers[ver.t - ver.coord].pb(ver);
		keys.insert(ver.t - ver.coord);
	}
	for (const auto& hor : hors) {
		group_hors[hor.t - hor.coord].pb(hor);
		keys.insert(hor.t - hor.coord);
	}

	for (const auto& key : keys) {
		solve_all(group_vers[key], group_hors[key]);
	}

	forn(i, n) {
		printf("%d %d\n", ans[i].fst, ans[i].snd);
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