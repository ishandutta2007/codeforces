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

int n, s;
vi a;

bool read() {
	if  (scanf("%d%d", &n, &s) < 2) {
		return 0;
	}
	--s;
	a.resize(n);
	forn(i, n) {
		scanf("%d", &a[i]);
	}
	return 1;
}

int solve() {
	vi na;
	int aux = 0;
	int aux_ans = 0;
	forn(i, sz(a)) {
		if  (i == s) {
			if  (a[i]) {
				++aux_ans;
			}
		} else {
			if  (!a[i]) {
				++aux;
			} else {
				na.pb(a[i]);
			}
		}
	}

	if  (n == 1) {
		return aux_ans;
	}

	a.swap(na);
	sort(all(a));

	int ans = n;
	int i = 0;
	int cnt = 0;
	int not_was = 0;
	for (int h = 1; h < n; ++h) {
		bool was_h = 0;
		while (i < sz(a) && a[i] <= h) {
			++cnt;
			if  (a[i] == h) {
				was_h = 1;
			}
			++i;
		}
		if  (!was_h) {
			++not_was;
		}

		int Aux = aux + (sz(a) - cnt);
		// printf("h=%d, Aux=%d, not_was=%d\n", h, Aux, not_was);
		int cur = max(Aux, not_was);
		ans = min(ans, cur);
	}

	return ans + aux_ans;
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