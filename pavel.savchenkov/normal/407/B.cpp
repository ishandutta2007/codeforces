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
const int MOD = int(1e9) + 7;
const int MAXN = int(1e3) + 10;

inline void add( int & x, int y ) {
	if  ((x += y) >= MOD) {
		x -= MOD;
	}
}

int p[MAXN];
int dp[MAXN];
int n;

int main() {
	scanf("%d", &n);
	forn(i, n) {
		scanf("%d", &p[i]);
		--p[i];
	}
		
	dp[0] = 1;
	for (int i = 1; i < n; ++i) {
		if  (p[i] == i) {
			dp[i] = 1;
		} else {
			dp[i] = 1;
			for (int j = p[i]; j < i; ++j) {
				add(dp[i], dp[j]);
				add(dp[i], 1);
			}
		}
	}

	int ans = 0;
	forn(i, n) {
		add(ans, dp[i]);
		add(ans, 1);
	}

	printf("%d\n", ans);
	return 0;
}