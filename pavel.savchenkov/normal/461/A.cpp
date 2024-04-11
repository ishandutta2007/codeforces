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

const double EPS = 1e-9;
const int MAXN = 3 * int(1e5) + 10;

int a[MAXN];
int n;
ll sum[MAXN];

ll solve( int l, int r ) {
	if  (r < l) {
		return 0;
	}

	ll res = sum[r + 1] - sum[l];

	if  (r - l == 0) {
		return res;
	}

	int m = (l + r) / 2;

	if  ((r - l + 1) % 2 == 1) {
		--m;
	}

	m = l;
	return res + solve(l, m) + solve(m + 1, r);
}

int main() {
	scanf("%d", &n);
	FORN(i, n) {
		scanf("%d", &a[i]);
	}

	sort(a, a + n);

	sum[0] = 0;
	FORN(i, n) {
		sum[i + 1] = sum[i] + a[i];
	}

	cout << solve(0, n - 1) << '\n';

	return 0;
}