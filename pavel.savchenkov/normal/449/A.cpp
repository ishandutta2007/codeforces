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
typedef vector <vector<pii> > vvii;

const double EPS = 1e-9;

ll ans = 1;
int n, m, k;

void upd( int a ) {
	if  (a < 0) {
		a = 0;
	}

	if  (a > n - 1) {
		a = n - 1;
	}

	if  (a > k) {
		a = k;
	}

	int b = k - a;
	ans = max(ans, (n / (a + 1)) * 1ll * (m / (b + 1)));
}

int main() {
	scanf("%d%d%d", &n, &m, &k);

	if  (k > (n - 1) + (m - 1)) {
		puts("-1");
		return 0;
	}

	// fix [n / (a + 1)]
	for (int f = 1; f * f <= n; ++f) {
		upd((n / f) - 1);
	}

	// fix a
	for (int a = 0; a * a <= n; ++a) {
		upd(a);
	}

	cout << ans << '\n';
	return 0;
}