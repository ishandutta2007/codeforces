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

const int MAXN = 2e5 + 10;

int n;
char s[MAXN];

bool read() {
	if  (scanf("%d\n", &n) < 1) {
		return 0;
	}
	scanf("%s\n", s);
	assert((int) strlen(s) == n);
	return 1;
}

int next(set<int>& s, int ptr) {
	auto it = s.lower_bound(ptr);
	if  (it != s.end()) {
		return *it;
	}
	return *s.begin();
}

void solve() {
	set<int> D;
	set<int> R;
	forn(i, n) {
		if  (s[i] == 'D') {
			D.insert(i);
		} else {
			R.insert(i);
		}
	}

	int ptr = 0;
	while (!D.empty() && !R.empty()) {
		int d = next(D, ptr);
		int r = next(R, ptr);
		if  ((d - ptr + n) % n < (r - ptr + n) % n) {
			auto it = R.upper_bound(ptr);
			if  (it != R.end()) {
				R.erase(it);
			} else {
				R.erase(R.begin());
			}
			ptr = (d + 1) % n;
		} else {
			auto it = D.upper_bound(ptr);
			if  (it != D.end()) {
				D.erase(it);
			} else {
				D.erase(D.begin());
			}
			ptr = (r + 1) % n;
		}
	}

	if  (!D.empty()) {
		puts("D");
	} else {
		puts("R");
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