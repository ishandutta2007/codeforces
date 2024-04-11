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

using namespace std;

#define PB push_back
#define F first
#define S second
#define MP make_pair 
#define SZ(C) ((int) (C).size())
#define FORN(i, n) for (int i = 0; i < (int) n; ++i)
#define FORD(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define ALL(C) begin(C), end(C)

#define DEBUG(x) cerr << #x" = " << x << '\n';

template <typename T>
inline T sqr( T x ) {
	return x * x;
}

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef vector <vector <int> > vvi;
typedef vector <pii> vii;
typedef vector <vector<pii> > vvii;

const double EPS = 1e-9;
const int MAXN = int(1e3) + 10;

int fenw[MAXN][MAXN];
int n, m;

void inc( int x, int y, int val ) {
	for (int i = x; i < n; i = i | (i + 1)) {
		for (int j = y; j < m; j = j | (j + 1)) {
			fenw[i][j] += val;
		}
	}
}

int get( int x, int y ) {
	int res = 0;
	for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
		for (int j = y; j >= 0; j = (j & (j + 1)) - 1) {
			res += fenw[i][j];
		}
	}
	return res;
}

int get( int x1, int x2, int y1, int y2 ) {
	return get(x2, y2) - get(x1 - 1, y2) - get(x2, y1 - 1) + get(x1 - 1, y1 - 1);
}

bool full( int x1, int x2, int y1, int y2 ) {
	return get(x1, x2, y1, y2) == (x2 - x1 + 1) * (y2 - y1 + 1);
}

int expand_gor( int x1, int x2, int y ) {
	if  (!full(x1, x2, y, y)) {
		return 0;
	}

	int L = 0;
	int R = y + 1;

	while (L != R - 1) {
		int M = (L + R) >> 1;

		if  (full(x1, x2, y - M, y)) {
			L = M;
		} else {
			R = M;
		}
	}

	int left_y = y - L;


	L = 0;
	R = m - y;

	while (L != R - 1) {
		int M = (L + R) >> 1;

		if  (full(x1, x2, y, y + M)) {
			L = M;
		} else {
			R = M;
		}
	}

	int right_y = y + L;

	return (x2 - x1 + 1) * (right_y - left_y + 1);
}

int expand_ver( int y1, int y2, int x ) {
	if  (!full(x, x, y1, y2)) {
		return 0;
	}

	int L = 0;
	int R = x + 1;

	while (L != R - 1) {
		int M = (L + R) >> 1;

		if  (full(x - M, x, y1, y2)) {
			L = M;
		} else {
			R = M;
		}
	}

	int down_x = x - L;


	L = 0;
	R = n - x;

	while (L != R - 1) {
		int M = (L + R) >> 1;

		if  (full(x, x + M, y1, y2)) {
			L = M;
		} else {
			R = M;
		}
	}

	int up_x = x + L;

	return (up_x - down_x + 1) * (y2 - y1 + 1);
}

int a[MAXN][MAXN];

int main() {
	int q;
	scanf("%d%d%d", &n, &m, &q);

	memset (fenw, 0, sizeof fenw);

	FORN(i, n) {
		FORN(j, m) {
			int v;
			scanf("%d", &v);

			if  (v) {
				inc(i, j, 1);
			}	

			a[i][j] = v;
		}
	}

	while (q --> 0) {
		int op, x, y;

		scanf("%d%d%d", &op, &x, &y);
		--x;
		--y;

		if  (op == 1) {
			int cur = get(x, x, y, y);
			inc(x, y, cur == 1 ? (-1) : 1);
			a[x][y] += cur == 1 ? (-1) : 1;
		} else {
			int ans = 0;

			// left
			int x1 = x;
			int x2 = x;

			while (x2 < n && a[x2][y]) ++x2;
			--x2;

			while (x1 >= 0 && a[x1][y]) --x1;
			++x1;

			for (int y2 = y; y2 < m; ++y2) {
				ans = max(ans, (x2 - x1 + 1) * (y2 - y + 1));

				if  (y2 == m - 1) {
					break;
				}

				while (x2 >= x && !full(x, x2, y2 + 1, y2 + 1)) --x2;
				while (x1 <= x && !full(x1, x, y2 + 1, y2 + 1)) ++x1;

				if  (x2 < x || x1 > x) {
					break;
				}
			}

			// right
			x1 = x;
			x2 = x;

			while (x2 < n && a[x2][y]) ++x2;
			--x2;

			while (x1 >= 0 && a[x1][y]) --x1;
			++x1;

			for (int y1 = y; y1 >= 0; --y1) {
				ans = max(ans, (x2 - x1 + 1) * (y - y1 + 1));

				if  (y1 == 0) {
					break;
				}

				while (x2 >= x && !full(x, x2, y1 - 1, y1 - 1)) --x2;
				while (x1 <= x && !full(x1, x, y1 - 1, y1 - 1)) ++x1;

				if  (x2 < x || x1 > x) {
					break;
				}
			}

			// down
			int y1 = y;
			int y2 = y;

			while (y2 < m && a[x][y2]) ++y2;
			while (y1 >= 0 && a[x][y1]) --y1;
			--y2;
			++y1;

			for (int x1 = x; x1 >= 0; --x1) {
				ans = max(ans, (x - x1 + 1) * (y2 - y1 + 1));

				if  (x1 == 0) {
					break;
				}

				while (y1 <= y && !full(x1 - 1, x1 - 1, y1, y)) ++y1;
				while (y2 >= y && !full(x1 - 1, x1 - 1, y, y2)) --y2;

				if  (y1 > y || y2 < y) {
					break;
				}
			}

			// up
			y1 = y;
			y2 = y;

			while (y2 < m && a[x][y2]) ++y2;
			while (y1 >= 0 && a[x][y1]) --y1;
			--y2;
			++y1;

			for (int x2 = x; x2 < n; ++x2) {
				ans = max(ans, (x2 - x + 1) * (y2 - y1 + 1));

				if  (x2 == n - 1) {
					break;
				}

				while (y1 <= y && !full(x2 + 1, x2 + 1, y1, y)) ++y1;
				while (y2 >= y && !full(x2 + 1, x2 + 1, y, y2)) --y2;

				if  (y1 > y || y2 < y) {
					break;
				}
			}

			/*
			//left
			for (int y2 = y; y2 < m; ++y2) {
				ans = max(ans, expand_ver(y, y2, x));
			}

			// right
			for (int y1 = y; y1 >= 0; --y1) {
				ans = max(ans, expand_ver(y1, y, x));
			}

			// down
			for (int x1 = x; x1 >= 0; --x1) {
				ans = max(ans, expand_gor(x1, x, y));
			}

			// up
			for (int x2 = x; x2 < n; ++x2) {
				ans = max(ans, expand_gor(x, x2, y));
			}
			*/

			printf("%d\n", ans);
		}	
	}

	return 0;
}