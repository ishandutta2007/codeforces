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
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;

#define FILE_NAME "a"

int n;
vi t;

bool read() {
	if  (scanf("%d", &n) < 1) {
		return 0;
	}
	t.resize(n);
	forn(i, n) {
		scanf("%d", &t[i]);
	}
	return 1;
}

#define image(c) sort(all(c)), c.resize(unique(all(c)) - c.begin())

vii get(int dir, int start) {
	assert(start < sz(t));

	assert(dir == 0 || dir == 1);

	int pref = t[start];

	vii res;
	if  (dir == 0) {
		forn(i, pref) {
			res.pb(mp(0, i));
		}
	} else {
		forn(i, pref) {
			res.pb(mp(i, i));
		}
	}

	if  (start + 1 == sz(t)) {
		return res;
	}

	if  (dir == 0) {
		auto rec = get(1, start + 1);
		for (auto& p : rec) {
			p.fst += 1;
			p.snd += pref;
			res.pb(mp(-p.fst, p.snd));
			res.pb(p);
		}	
		image(res);
		return res;
	}

	{
		assert(dir == 1);
		auto rec = get(0, start + 1);
		for (auto& p : rec) {
			p.fst += pref - 1;
			p.snd += pref;
			res.pb(mp(p.snd, p.fst));
			res.pb(p);
		}
		image(res);
		return res;
	}
}

void print(vii ps) {
	int min_x = 1e9;
	int min_y = 1e9;
	int max_x = -1e9;
	int max_y = -1e9;
	for (auto p : ps) {
		min_x = min(min_x, p.fst);
		min_y = min(min_y, p.snd);
		max_x = max(max_x, p.fst);
		max_y = max(max_y, p.snd);
	}

	vvi a(max_y - min_y + 1, vi(max_x - min_x + 1, 0));
	for (auto p : ps) {
		a[p.snd - min_y][p.fst - min_x] = 1;
	}

	ford(i, sz(a)) {
		forn(j, sz(a[i])) {
			printf("%c", a[i][j] ? '#' : '.');
		}
		puts("");
	}
	puts("");
}

int solve() {
	auto res = get(0, 0);
	// print(res);
	return sz(res);
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