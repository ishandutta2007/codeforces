#pragma warning(disable:4996)

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <complex>
#include <iterator>
#include <random>
#include <time.h>
#include <tuple>
#include <functional>
#include <list>
#include <limits.h>
#define mp make_pair
#define ni(x) scanf("%d", &(x))
#define nii(x,y) scanf("%d%d",&(x),&(y))
#define mul(x,y) ((ll)(x)*(y)%mod)
#define mtp make_tuple
#define add(x,y) ((ll)(x)+(y))%mod
#define F(i,n) for(int i = 0; i < (n); i++)
#define FF(i,n) for(int i = 1; i <= (n); i++)

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

const int N = 1024;
const int LG = 10;
int bd[N][N];
int bd2[N][N];
int bd3[N][N];
int bd4[N << 1][LG][N];
int lgtable[N];

int getmax2(int nd, int j1, int j2) {
	j2++;
	int lg = lgtable[j2 - j1];
	return max(bd4[nd][lg][j1], bd4[nd][lg][j2 - (1 << lg)]);
}
int getmax(int i1, int i2, int j1, int j2) {
	int ans = 0;
	for (i1 += N - 1, i2 += N + 1; i1 / 2 != i2 / 2; i1 /= 2, i2 /= 2) {
		if (!(i1 & 1)) {
			ans = max(ans, getmax2(i1 + 1, j1, j2));
		}
		if (i2 & 1) {
			ans = max(ans, getmax2(i2 - 1, j1, j2));
		}
	}
	return ans;
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m; nii(n, m);
	F(i, n) F(j, m) ni(bd[i][j]);
	F(i, n) {
		bd2[i][m - 1] = bd[i][m - 1];
		for (int j = m - 2; j >= 0; j--) {
			if (bd[i][j]) {
				bd2[i][j] = 1 + bd2[i][j + 1];
			}
		}
	}
	F(j, m) {
		bd3[n - 1][j] = bd[n - 1][j];
		for (int i = n - 2; i >= 0; i--) {
			if (bd[i][j]) bd3[i][j] = 1 + bd3[i + 1][j];
		}
	}
	F(i, n) bd4[N + i][0][m - 1] = bd[i][m - 1];
	F(j, m) bd4[N + n - 1][0][j] = bd[n - 1][j];
	for (int i = n - 2; i >= 0; i--) {
		for (int j = m - 2; j >= 0; j--) {
			if (bd[i][j]) bd4[N + i][0][j] = min(bd2[i][j], min(bd3[i][j], bd4[N + i + 1][0][j + 1] + 1));
		}
	}
	F(i, n) {
		FF(k, LG - 1) {
			F(j, m) {
				int a = j + (1 << (k - 1));
				if (a >= m) bd4[N + i][k][j] = bd4[N + i][k - 1][j];
				else bd4[N + i][k][j] = max(bd4[N + i][k - 1][j], bd4[N + i][k - 1][a]);
			}
		}
	}
	for (int i = N - 1; i; i--) {
		F(k, LG) {
			F(j, m) {
				bd4[i][k][j] = max(bd4[i << 1][k][j], bd4[i << 1 | 1][k][j]);
			}
		}
	}
	int cur = 0;
	FF(i, N - 1) {
		if (1 << (cur + 1) <= i) cur++;
		lgtable[i] = cur;
	}

	int T; scanf("%d", &T);
	while (T--) {
		int x1, y1, x2, y2;
		nii(x1, y1); nii(x2, y2);
		x1--; y1--; x2--; y2--;
		int low = 1;
		int high = min(x2 - x1, y2 - y1) + 2;
		while (low != high) {
			int mid = (low + high) / 2;
			int g = getmax(x1, x2 - mid + 1, y1, y2 - mid + 1);
			if (g >= mid) low = mid + 1;
			else high = mid;
		}
		printf("%d\n", low - 1);
	}

	return 0;
}