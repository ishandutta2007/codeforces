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

struct point {
	int x, y, z;

	void output() {
		printf("%d %d %d\n", x, y, z);
	}	
};

point operator -( const point& a, const point& b ) {
	return { a.x - b.x, a.y - b.y, a.z - b.z };
}
 
ll operator *( const point& a, const point& b ) {
	return a.x * 1ll * b.x + a.y * 1ll * b.y + a.z * 1ll * b.z;
}

bool OK( const point& a, const point& b ) {
	return (a * b) == 0;
}

int c[8][3];
point pt[8];

bool check() {
	FORN(i, 8) {
		pt[i] = { c[i][0], c[i][1], c[i][2] };
	}

	ll len = -1ll;

	FORN(i, 8) {
		pair <ll, int> dist[8];

		FORN(j, 8) {
			point diff = pt[i] - pt[j];
			dist[j] = MP(diff * diff, j);
		}

		stable_sort(dist, dist + 8);

		if  (len == -1ll) {
			len = dist[1].F;
		}

		if  (!len || dist[1].F != len || dist[2].F != len || dist[3].F != len || dist[4].F != len + len || dist[5].F != len + len
			|| dist[6].F != len + len || dist[7].F != len + len + len) {
			return false;
		}

		point p2 = pt[dist[1].S] - pt[i];
		point p3 = pt[dist[2].S] - pt[i];
		point p4 = pt[dist[3].S] - pt[i];

		if  (!OK(p2, p3) || !OK(p2, p4) || !OK(p3, p4)) {
			return false;
		}
	}

	return true;
}

void go( int i ) {
	if  (i == 7) {
		if  (check()) {
			puts("YES");
			FORN(j, 8) {
				FORN(k, 3) {
					printf("%d ", c[j][k]);
				}
				puts("");
			}
			exit(0);
		}
		return;
	}

	int p[3] = {0, 1, 2};
	int tmp[3] = { c[i][0], c[i][1], c[i][2] };
		
	do {
		FORN(j, 3) {
			c[i][j] = tmp[p[j]];
		}

		go(i + 1);
	} while (next_permutation(p, p + 3));
}

int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	FORN(i, 8) {
		FORN(j, 3) {
			scanf("%d", &c[i][j]);
		}
	}

	go(0);

	puts("NO");
	return 0;
}