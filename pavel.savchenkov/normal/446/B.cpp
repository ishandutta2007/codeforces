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
const int MAXN = int(1e3) + 5;
const int MAXK = int(1e6) + 5;

int a[MAXN][MAXN];
int n, m, k, p;
ll ansCols[MAXK];
ll ansRows[MAXK];

void Precalc() {
	multiset <ll> S;
	forn(i, n) {
		ll sum = 0;
		forn(j, m) {
			sum += a[i][j];
		}
		S.insert(sum);
	}

	ll curAns = 0;
	for (int i = 1; i <= k; ++i) {
		int maxRow = *S.rbegin();
		S.erase(S.find(maxRow));
		S.insert(maxRow - m * p);

		curAns += maxRow;
		ansRows[i] = curAns;
	}


	S.clear();
	forn(j, m) {
		ll sum = 0;
		forn(i, n) {
			sum += a[i][j];
		}
		S.insert(sum);
	}

	curAns = 0;
	for (int i = 1; i <= k; ++i) {
		int maxCol = *S.rbegin();
		S.erase(S.find(maxCol));
		S.insert(maxCol - n * p);

		curAns += maxCol;
		ansCols[i] = curAns;
	}
}

int main() {
	scanf("%d%d%d%d", &n, &m, &k, &p);

	forn(i, n) {
		forn(j, m) {
			scanf("%d", &a[i][j]);
		}
	}

	Precalc();

	ll ans = -ll(1e18);
	forn(cntRows, k + 1) {
		int cntCols = k - cntRows;
		ans = max(ans, ansRows[cntRows] + ansCols[cntCols] - cntRows * 1ll * cntCols * 1ll * p);
	}

	printf("%I64d\n", ans);
	return 0;
}