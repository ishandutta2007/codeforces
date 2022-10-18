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
const int MAXN = int(1e5) + 10;

int cnt[MAXN];
ll dp[MAXN][2];

main() {
	int n;
	scanf("%d", &n);
	FORN(i, n) {
		int a;
		scanf("%d", &a);
		++cnt[a];
	}

	FORN(i, MAXN) {
		FORN(c, 2) {
			dp[i][c] = 0;
		}
	}


	dp[0][0] = dp[0][1] = 0;
	for (int i = 1; i < MAXN; ++i) {
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
		if  (cnt[i]) {
			dp[i][1] = dp[i - 1][0] + i * 1ll * cnt[i];
		}		
	}        

	cout << dp[MAXN - 1][0] << '\n';
	return 0;
}