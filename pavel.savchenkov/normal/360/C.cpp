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
const int MOD = 1000000007;

int mul( int a, int b ) {
	return int(a * 1ll * b % MOD);
}

void add( int & a, int b ) {
	if  ((a += b) >= MOD)
		a -= MOD;
}

int dp[2][MAXN][MAXN];
char s[MAXN];
int n, k;

int solve() {
	forn(i, n + 1)
		forn(j, k + 1)
			forn(c, 2)
				dp[c][i][j] = 0;

	dp[0][0][0] = 1;
	for (int i = 0; i < n; i++)
		for (int have = 0; have <= k; have++)
			for (int bad = 0; bad <= 1; bad++)
				if  (dp[bad][i][have] != 0) {
					int cur_dp = dp[bad][i][have];

//					printf("dp[%d][%d][%d] = %d\n", bad, i, have, cur_dp);

					if  (bad == 1) {
						add(dp[0][i + 1][have], mul(cur_dp, int(s[i] - 'a')));

						add(dp[1][i + 1][have], cur_dp);

				 		continue;	
					}

					add(dp[1][i][have], cur_dp);

					for (int j = i; j <= (n + i) / 2; j++) {
						int nhave = (j - i + 1) * (n - j);
						nhave += have;

//						printf("j = %d i = %d\n", j, i);

						if  (nhave > k)
							break;

//						printf("nhave = %d cur_dp = %d\n", nhave, cur_dp);

						int ndp = mul(cur_dp, int('z' - s[j]));

//						printf("ndp = %d\n", ndp);

						add(dp[0][j + 1][nhave], ndp);
					}

					for (int j = n - 1; j > (n + i) / 2; j--) {
						int nhave = (j - i + 1) * (n - j);
						nhave += have;

						if  (nhave > k)
							break;

						int ndp = mul(cur_dp, int('z' - s[j]));

						add(dp[0][j + 1][nhave], ndp);
					}      
				}

	int ans = dp[0][n][k];
	add(ans, dp[1][n][k]);

	return ans;
}

int main() {
	scanf("%d%d\n", &n, &k);

	gets(s);

	printf("%d\n", solve());
	return 0;
}