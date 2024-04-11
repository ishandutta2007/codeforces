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

int n, m;
vector<string> a;
string s;

bool read() {
	if  (scanf("%d%d\n", &n, &m) < 2) {
		return 0;
	}
	a.resize(n);
	forn(i, n) {
		getline(cin, a[i]);
	}
	getline(cin, s);
	return 1;
}

bool on(int i, int j) {
	return 0 <= i && i < n && 0 <= j && j < m;
}

bool check(const vi& di, const vi& dj) {
	int i = -1;
	int j = -1;
	forn(ii, n) {
		forn(jj, m) {
			if  (a[ii][jj] == 'S') {
				i = ii;
				j = jj;
				break;
			}
		}
	}

	assert(i != -1);

	for (char dir : s) {
		int ni = i + di[dir - '0'];
		int nj = j + dj[dir - '0'];

		if  (!on(ni, nj) || a[ni][nj] == '#') {
			return 0;
		}

		if  (a[ni][nj] == 'E') {
			return 1;
		}

		i = ni;
		j = nj;
	}

	return 0;
}

int solve() {
	const vi DI = {1, -1, 0, 0};
	const vi DJ = {0, 0, 1, -1};

	vi perm(4);
	iota(all(perm), 0);
	int ans = 0;
	do {
		vi di;
		vi dj;
		forn(i, 4) {
			di.pb(DI[perm[i]]);
			dj.pb(DJ[perm[i]]);
		}
		if  (check(di, dj)) {
			++ans;
		}
	} while (next_permutation(all(perm)));

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