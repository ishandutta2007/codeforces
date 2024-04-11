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
const int MAXN = int(1e5) + 10;

vi vals;
int a[MAXN];
int b[MAXN];
ll sum_a[MAXN];
ll sum_b[MAXN];
int n, m;

ll makeMin( int mn ) {
	int pos = lower_bound(a, a + n, mn) - a;
	--pos;

	if  (pos < 0) {
		return 0;
	}

	return mn * 1ll * (pos + 1) - sum_a[pos];
}

ll makeMax( int mx ) {
	int pos = upper_bound(b, b + m, mx) - b;

	if  (pos >= m) {
		return 0;
	}

	return -mx * 1ll * (m - pos) + sum_b[pos];
}

int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	scanf("%d%d", &n, &m);

	forn(i, n) {
		scanf("%d", &a[i]);
	}
		
	sort(a, a + n);

	sum_a[0] = a[0];
	for (int i = 1; i < n; ++i) {
		sum_a[i] = sum_a[i - 1] + a[i];	
   	}

   	forn(i, m) {
   		scanf("%d", &b[i]);
   	}

   	sort(b, b + m);

   	sum_b[m - 1] = b[m - 1];
   	for (int i = m - 2; i >= 0; --i) {
   		sum_b[i] = sum_b[i + 1] + b[i];
   	}

   	forn(i, n) {
   		vals.pb(a[i]);
   		vals.pb(a[i] + 1);
   		vals.pb(a[i] - 1);
   	}

   	forn(i, m) {
   		vals.pb(b[i]);
   		vals.pb(b[i] + 1);
   		vals.pb(b[i] - 1);
   	}

   	sort(all(vals));

   	ll res = ll(1e18);
   	forn(i, sz(vals)) {
   		ll cur = makeMin(vals[i]) + makeMax(vals[i]);

   		res = min(res, cur);
   	}

   	cout << res << '\n';

	return 0;
}