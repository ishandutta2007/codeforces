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

const int MAXN = 1e5 + 10;

int n, m;
vi gt[MAXN];
int isGood[MAXN];

bool read() {
	if  (scanf("%d%d", &n, &m) < 2) {
		return 0;
	}
	forn(i, n) {
		scanf("%d", &isGood[i]);
	}
	forn(i, n) {
		gt[i].clear();
	}
	forn(i, m) {
		int v, to;
		scanf("%d%d", &v, &to);
		gt[to].pb(v);
	}
	return 1;
}

int solve() {
	vi deg_out(n, 0);
	forn(v, n) {
		for (int from : gt[v]) {
			++deg_out[from];
		}
	}

	set<int> goodLeaves;
	set<int> badLeaves;

	auto dec = [&](int v) {
		--deg_out[v];
		assert(deg_out[v] >= 0);
		if  (deg_out[v] == 0) {
			if  (isGood[v]) {
				goodLeaves.insert(v);
			} else {
				badLeaves.insert(v);
			}
		}
	};

	auto del = [&](int v) {
		assert(deg_out[v] == 0);
		for (int from : gt[v]) {
			dec(from);
		}
	};

	forn(v, n) {
		if  (deg_out[v] == 0) {
			if  (isGood[v]) {
				goodLeaves.insert(v);
			} else {
				badLeaves.insert(v);
			}
		}
	} 

	int ans = 0;
	while (!goodLeaves.empty() || !badLeaves.empty()) {
		while (!badLeaves.empty()) {
			int v = *badLeaves.begin();
			badLeaves.erase(badLeaves.begin());
			del(v);
			eprintf("del bad v=%d\n", v);
		}
		bool wasDelGood = 0;
		while (!goodLeaves.empty()) {
			int v = *goodLeaves.begin();
			goodLeaves.erase(goodLeaves.begin());
			del(v);
			wasDelGood = 1;
			eprintf("del good v=%d\n", v);
		}		
		if  (!wasDelGood) {
			assert(goodLeaves.empty() && badLeaves.empty());
			break;
		}
		eprintf("++ans\n");
		++ans;
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
	eprintf("Time: %.10f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}