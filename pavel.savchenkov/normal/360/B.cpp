#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <math.h>
#include <cstdlib>
#include <memory.h>
#include <queue>
#include <assert.h>
#include <cmath>

using namespace std;

#define pb push_back
#define f first
#define s second
#define mp make_pair 
#define sz(A) ((int)(A).size())
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define foran(i, a, n) for (int i = int(a); i < int(n); i++)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define all(A) A.begin(), A.end()
#define sqr(x)((x) * (x))

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;

const double EPS = 1e-9;
const int MAXN = 2 * int(1e3) + 10;
const int INF = 2 * int(1e9) + 1;

int get_min( int l, int r, int cnt ) {
	if  (l > r)
		swap(l, r);

	// l + (cnt + 1) * C >= r
	// C >= (r - l) / (cnt + 1)
	return (r - l + cnt) / (cnt + 1);	
}

int a[MAXN];
int n, k;
int dp[MAXN];
 
bool can( int c ) {
	forn(i, n + 1)
		dp[i] = i;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if  (get_min(a[i], a[j], j - i - 1) <= c)
				dp[j] = min(dp[j], dp[i] + j - i - 1);
		}
	}

//	forn(i, n + 1)
//		printf("%d ", dp[i]);
//	puts("");

	int mn = dp[n];

	for (int i = 0; i < n; i++)
		mn = min(mn, dp[i] + n - i - 1);

	return mn <= k;	
}

int main() {
    scanf("%d%d", &n, &k);

    forn(i, n) {
    	scanf("%d", &a[i]);
    }

    int L = 0;
    int R = INF;
    while (L != R - 1) {
    	int M = (int) ((ll(L) + ll(R)) / 2ll);

    	if  (can(M))
    		R = M;
    	else
    		L = M;
    }

    if  (can(0))
    	R = 0;

    printf("%d\n", R);
	return 0;
}