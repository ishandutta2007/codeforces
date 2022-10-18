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


int n;
int have[2];
vii a[2];

bool read() {
	if  (scanf("%d%d%d", &n, &have[0], &have[1]) < 3) {
		return 0;
	}
	forn(i, 2) {
		a[i].clear();
	}
	forn(i, n) {
		int b, p;
		scanf("%d%d ", &b, &p);
		char type = getchar();
		if  (type == 'C') {
			a[0].pb(mp(p, b));
		} else {
			assert(type == 'D');
			a[1].pb(mp(p, b));
		}
	}
	return 1;
}

const int INF = 1e9;


pair<vi, vi> calc_pref_max(const vii& a) {
	vi pr1(sz(a) + 1, -INF);
	vi pr2(sz(a) + 1, -INF);
	int mx1 = -INF;
	int mx2 = -INF;
	forn(i, sz(a) + 1) {
		pr1[i] = mx1;
		pr2[i] = mx2;

		if  (i == sz(a)) {
			break;
		}

		if  (a[i].snd > mx1) {
			mx2 = mx1;
			mx1 = a[i].snd;
		} else if  (a[i].snd > mx2) {
			mx2 = a[i].snd;
		}
	}
	return mp(pr1, pr2);
}

int get_cost(const vi& pref1, const vi& pref2, int len1, int len2) {
	if  (len1 > len2) {
		swap(len1, len2);
	}

	int cost1 = pref1[len1];
	int cost2 = pref1[len2];

	if  (cost1 <= 0 || cost2 <= 0) {
		return -INF;
	}

	if  (cost1 == cost2) {
		cost2 = pref2[len2];
		if  (cost2 <= 0) {
			return -INF;
		}
	}

	return cost1 + cost2;
}

int solve(const vii& a, const vi& pref1, const vi& pref2, int have) {
	int ans = 0;
	forn(i, sz(a)) {
		if (a[i].fst >= have) {
			break;
		}

		int j = upper_bound(all(a), mp(have - a[i].fst, INF)) - a.begin();

		ans = max(ans, get_cost(pref1, pref2, i + 1, j));
	}
	return ans;
}

int solve() {
	int ans = 0;
	forn(it, 2) {
		sort(all(a[it]));

		vi pr1, pr2;
		tie(pr1, pr2) = calc_pref_max(a[it]);
		ans = max(ans, solve(a[it], pr1, pr2, have[it]));
	}

	{
		int cur = 0;
		forn(it, 2) {
			int cur_cur = -1;
			forn(i, sz(a[it])) {
				if  (a[it][i].fst <= have[it]) {
					cur_cur = max(cur_cur, a[it][i].snd);
				}
			}
			if  (cur_cur == -1) {
				cur = 0;
				break;
			}
			cur += cur_cur;
		}

		ans = max(ans, cur);
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