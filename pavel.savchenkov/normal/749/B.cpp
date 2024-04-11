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

const int MAXN = 1e5 + 10;

struct pnt {
	int x, y;

	pnt() {}

	pnt(int x, int y) : x(x), y(y) {}

	bool read() {
		return (scanf("%d%d", &x, &y) >= 2);
	}

	pnt operator - (const pnt& p) const {
		return pnt(x - p.x, y - p.y);
	}

	pnt operator + (const pnt& p) const {
		return pnt(x + p.x, y + p.y);
	}

	int operator % (const pnt& p) const {
		return x * p.y - y * p.x;
	}

	int operator * (const pnt& p) const {
		return x * p.x + y * p.y;
	}

	int len() const {
		return (x * x + y * y);
	}

	void print() const {
		printf("%d %d\n", x, y);
	}
};

pnt ps[3];

bool read() {
	forn(i, 3) {
		if  (!ps[i].read()) {
			return 0;
		}
	}
	return 1;
}

void solve() {
	printf("3\n");
	forn(i, 3) {
		auto p1 = ps[i];
		auto p2 = ps[(i + 1) % 3];
		auto p3 = ps[(i + 2) % 3];
		auto p4 = p3 + (p2 - p1);
		p4.print();
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