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

string s;

bool read() {
	if  (!getline(cin, s)) {
		return 0;
	}
	return 1;
}

int solve() {
	set<int> alive;
	set<int> good;
	forn(i, sz(s)) {
		alive.insert(i);
		if  ((i > 0 && s[i - 1] != s[i]) || (i + 1 < sz(s) && s[i] != s[i + 1])) {
			good.insert(i);
		}
	}

	auto prev = [&](int i) -> int {
		assert(alive.count(i));
		if  (*alive.begin() == i) {
			return -1;
		}
		return *--alive.find(i);
	};

	auto next = [&](int i) -> int {
		assert(alive.count(i));
		if  (*alive.rbegin() == i) {
			return -1;
		}
		return *++alive.find(i);
	};

	int ans = 0;
	while (!good.empty()) {
		vi to_check;

		for (int i : good) {
			int j = prev(i);
			if (j != -1) {
				to_check.pb(j);
			}
			j = next(i);
			if  (j != -1) {
				to_check.pb(j);
			}
		}

		for (int i : good) {
			alive.erase(i);
		}

		good.clear();
		for (int i : to_check) {
			if  (!alive.count(i)) {
				continue;
			}
			int j = prev(i);
			if  (j != -1 && s[j] != s[i]) {
				good.insert(i);
			}
			j = next(i);
			if  (j != -1 && s[j] != s[i]) {
				good.insert(i);
			}
		}

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