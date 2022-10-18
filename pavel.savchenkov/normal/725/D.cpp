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

const int MAXN = 3e5 + 10;

int n;
ll t[MAXN];
ll w[MAXN];

bool read() {
	if  (scanf("%d", &n) < 1) {
		return 0;
	}
	forn(i, n) {
		scanf("%lld%lld", &t[i], &w[i]);
	}
	return 1;
}

int solve() {
	multiset<ll> gr;
	multiset<pll> sm;
	for (int i = 1; i < n; ++i) {
		if  (t[i] > t[0]) {
			gr.insert(w[i] - t[i] + 1);
		} else {
			sm.insert(mp(t[i], w[i]));
		}
	}

	int ans = n;
	while (t[0] > 0) {
		if (gr.empty()) {
			return 1;
		}

		ans = min(ans, sz(gr) + 1);

		// printf("t[0] = %lld, sz(gr) = %d\n", t[0], sz(gr));

		ll mn = *gr.begin();

		if  (mn > t[0]) {
			return ans;
		}

		gr.erase(gr.begin());
		// printf("erase %lld\n", mn);

		t[0] -= mn;
		while (!sm.empty() && sm.rbegin()->fst > t[0]) {
			auto it = sm.rbegin();
			gr.insert(it->snd - it->fst + 1);
			// printf("insert %lld\n", it->snd - it->fst + 1);
			sm.erase(sm.find(*it));
		}
	}

	ans = min(ans, sz(gr) + 1);
	
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