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
#define ALL(C) (C).begin(), (C).end()

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

constexpr double EPS = 1e-9;
constexpr double M_PI = acos(1.0);
constexpr ll INF = ll(1e18);

ll mult( ll a, ll b ) {
	if  (a >= INF || b >= INF || a * b >= INF) {
		return INF;
	}

	ll res = a * b;
	if  (a && res / a != b) {
		return INF;
	}

	return res;
}

ll solve( const vi &a, const vi &b ) {
	ll sum_b = 0;
	FORN(i, SZ(b)) {
		sum_b += b[i];
	}

	ll sum_a = 0;
	FORN(i, SZ(a)) {
		sum_a += a[i];
	}

	ll ans = INF;	
	int cnt_fix = 0;
	FORD(i, SZ(a)) {
		sum_a -= a[i];
		++cnt_fix;

		ans = min(ans, sum_a + mult(sum_b, cnt_fix));
	}

	return ans;
}

main() {
	int n, m;
	scanf("%d%d", &n, &m);

	vi a(n);
	FORN(i, SZ(a)) {
		scanf("%d", &a[i]);
	}

	vi b(m);
	FORN(i, SZ(b)) {
		scanf("%d", &b[i]);
	}

	sort(ALL(a));
	sort(ALL(b));

	cout << min(solve(a, b), solve(b, a)) << '\n';
	return 0;
}