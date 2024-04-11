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

#define pb push_back
#define f first
#define s second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define foran(i, a, n) for (int i = (int) a; i < (int) n; ++i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define all(C) (C).begin(), (C).end()

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

const double EPS = 1e-9;

int a, b;

inline int msqrt( int x ) {
	int s = (int) sqrt(x);
	while (s * s > x) --s;
	while (s * s < x) ++s;
	
	return s * s == x ? s : (-1);
}

int main() {
	scanf("%d%d", &a, &b);

	for (int x = 1; x < a; ++x) {
		int y2 = a * a - x * x;
		int y = msqrt(y2);

		if  (y == -1) {
			continue;
		}

		if  ((y * b) % a != 0) {
			continue;
		}

		int xx = y * b / a;
		int yy2 = b * b - xx * xx;

		int yy = msqrt(yy2);
		
		if  (yy == -1) {
			continue;	
		}
		     
		if  (xx * xx + yy * yy == b * b && x * x + y * y == a * a && x != xx) {
			puts("YES");
			puts("0 0");
			printf("%d %d\n", x, -y);
			printf("%d %d\n", xx, yy);
			return 0;
		}
	}

	puts("NO");	
	return 0;
}