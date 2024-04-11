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
const int MAXN = int(1e5) + 10;

vi who[MAXN];
int a[MAXN];
int n, m;

int main() {
	scanf("%d%d", &n, &m);

	ll sum = 0;
	FORN(i, m) {
		scanf("%d", &a[i]);
		if  (i && a[i] != a[i - 1]) {
			who[a[i]].PB(a[i - 1]);
			who[a[i - 1]].PB(a[i]);
			sum += abs(a[i] - a[i - 1]);
		}
	}

	ll ans = sum;
	FORN(x, n + 1) {
		sort(ALL(who[x]));

		ll cur = sum;

		FORN(i, SZ(who[x])) {
			cur -= abs(who[x][i] - x);
			cur += abs(who[x][i] - who[x][SZ(who[x]) / 2]);
		}
		
		ans = min(ans, cur);
	}

	cout << ans << '\n';
	return 0;
}