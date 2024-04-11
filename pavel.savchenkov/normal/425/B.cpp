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
const int MAXN = 100 + 5;

int dp[MAXN][(1 << 12) + 5];
int prev[MAXN][(1 << 12) + 5];
int a[MAXN][MAXN];
int n, m, k;
int timer;
int b[MAXN][MAXN];

void brut() {
	if  (n >= 11) {
		forn(i, n)
			forn(j, m)
				b[j][i] = a[i][j];

swap(n, m);
	   	forn(i, n)
	   		forn(j, m)
	   			a[i][j] = b[i][j];
	}

	vi nums;
	forn(j, m) {
		int x = 0;
		forn(i, n) {
			if  (a[i][j]) {
				x ^= 1 << i;
			}
		}
		nums.pb(x);
	}

	memset (dp, -1, sizeof dp);
	memset (dp[0], 0, sizeof dp[0]);

	forn(j, m) {
		forn(mask, 1 << n)
			if  (dp[j][mask] != -1) {
				int need = mask;
				int cnt = __builtin_popcount(need ^ nums[j]);

				if  (dp[j + 1][need] == -1 || dp[j + 1][need] > dp[j][mask] + cnt) {
//					printf("need = %d num = %d cnt = %d\n", need, nums[j], cnt);
					dp[j + 1][need] = dp[j][mask] + cnt;
					prev[j + 1][need] = mask;
				}	
//				continue;
				need = mask ^ ((1 << n) - 1);
				cnt = __builtin_popcount(need ^ nums[j]);

				if  (dp[j + 1][need] == -1 || dp[j + 1][need] > dp[j][mask] + cnt) {
					dp[j + 1][need] = dp[j][mask] + cnt;
					prev[j + 1][need] = mask;
				}	
			}
	}

	int Mask = 0;
	forn(mask, 1 << n)
		if  (dp[m][mask] != -1 && dp[m][mask] < dp[m][Mask]) {
			Mask = mask;
	  	}

	if  (dp[m][Mask] > k) {
		puts("-1");
		return;
	}

	printf("%d\n", dp[m][Mask]);
//	printf("%d\n", Mask);
	return;

	int j = m;
	nums.clear();
	while (j) {
		nums.pb(Mask);
		Mask = prev[j][Mask];
		--j;
	}

	ford(j, m) {
		forn(i, n)
			a[i][j] = (nums[j] >> i) & 1;
	}

	forn(i, n) {
		forn(j, m)
			printf("%d ", a[i][j]);
		puts("");
	}
};

int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &k);
	forn(i, n)
		forn(j, m)
			scanf("%d", &a[i][j]);

	if  (n < 11 || m < 11) {
		brut();
		return 0;
	}

	int res = n * m + 10;
	forn(i, k + 1)
		forn(j, k + 1) {
			forn(ii, n)
				forn(jj, m)
					b[ii][jj] = a[ii][jj];

			for (int ii = i - 1; ii >= 0; --ii)
				for (int jj = j + 1; jj < m; ++jj) {
				    int a1 = b[ii][jj - 1];
				    int a2 = b[ii + 1][jj - 1];
				    int a3 = b[ii + 1][jj];

					if  (a1 != a2) {
						b[ii][jj] = a3 ^ 1;
					} else {
						b[ii][jj] = a3;	
					}
				}

			for (int ii = i - 1; ii >= 0; --ii)
				for (int jj = j - 1; jj >= 0; --jj) {
					int a1 = b[ii][jj + 1];
					int a2 = b[ii + 1][jj + 1];
					int a3 = b[ii + 1][jj];

					if  (a1 != a2) {
						b[ii][jj] = a3 ^ 1;
					} else {
						b[ii][jj] = a3;	
					}
				}

			for (int ii = i + 1; ii < n; ++ii)
				for (int jj = j - 1; jj >= 0; --jj) {
					int a1 = b[ii][jj + 1];
					int a2 = b[ii - 1][jj + 1];
					int a3 = b[ii - 1][jj];

					if  (a1 != a2) {
						b[ii][jj] = a3 ^ 1;
					} else {
						b[ii][jj] = a3;	
					}
				}

			for (int ii = i + 1; ii < n; ++ii)
				for (int jj = j + 1; jj < m; ++jj) {
					int a1 = b[ii][jj - 1];
					int a2 = b[ii - 1][jj - 1];
					int a3 = b[ii - 1][jj];

					if  (a1 != a2) {
						b[ii][jj] = a3 ^ 1;
					} else {
						b[ii][jj] = a3;	
					}
				}

			int cur = 0;
			forn(ii, n)
				forn(jj, m)
					cur += int(a[ii][jj] != b[ii][jj]);

			res = min(res, cur);
	   	}

	if  (res > k) {
		res = -1;
	}

	printf("%d\n", res);
	return 0;
}