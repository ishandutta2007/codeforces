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

const int MAXN = 50 + 10;

string read_s() {
	static char s[MAXN];
	scanf("%s\n", s);
	return s;
}

struct Table {
	vector<string> a;
	int n, m;
	vii log;

	void read(int nn, int mm) {
		n = nn;
		m = mm;
		a.resize(n);
		forn(i, n) {
			a[i] = read_s();
		}
	}

	void rotate(int i, int j) {
		assert(i + 1 < n);
		assert(j + 1 < m);
		if  (a[i][j] == 'L') {
			a[i][j] = a[i][j + 1] = 'U';
			a[i + 1][j] = a[i + 1][j + 1] = 'D';
		} else {
			a[i][j] = a[i + 1][j] = 'L';
			a[i][j + 1] = a[i + 1][j + 1] = 'R';
		}
		log.pb(mp(i, j));
	}

	void make_ver(int i, int j) {
		assert(a[i][j] == 'L' || a[i][j] == 'U');
		if  (a[i][j] == 'U') {
			return;
		}
		assert(i + 1 < n);
		if  (a[i + 1][j] == 'U') {
			make_hor(i + 1, j);
		}
		assert(a[i + 1][j] == 'L');
		rotate(i, j);
	}

	void make_hor(int i, int j) {
		assert(a[i][j] == 'L' || a[i][j] == 'U');
		if  (a[i][j] == 'L') {
			return;
		}		
		assert(j + 1 < m);
		if  (a[i][j + 1] == 'L') {
			make_ver(i, j + 1);
		}
		assert(a[i][j + 1] == 'U');
		rotate(i, j);
	}

	vii norm() {
		log.clear();
		if  (m % 2 == 0) {
			for (int j = 0; j < m; j += 2) {
				forn(i, n) {
					if  (a[i][j] != 'L') {
						assert(a[i][j] == 'U');
						make_hor(i, j);
					}
				}
			}
		} else {
			for (int i = 0; i < n; i += 2) {
				forn(j, m) {
					if  (a[i][j] != 'U') {
						assert(a[i][j] == 'L');
						make_ver(i, j);
					}
				}
			}
		}
		return log;
	}
};

Table from, to;
int n, m;

bool read() {
	if  (scanf("%d%d\n", &n, &m) < 2) {
		return 0;
	}
	from.read(n, m);
	to.read(n, m);
	return 1;
}



void solve() {
	vii F = from.norm();
	vii T = to.norm();

	vii res;
	for (auto x : F) {
		res.pb(x);
	}
	reverse(all(T));
	for (auto x : T) {
		res.pb(x);
	}

	printf("%d\n", sz(res));
	for (auto x : res) {
		printf("%d %d\n", x.fst + 1, x.snd + 1);
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