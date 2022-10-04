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
const int N = 1010101;
char b1[N], b2[N];
void fill(char* a, int n, char* b, int m, int* c) {
	int curm = -1;
	for (int i = 0; i<n; i++) {
		if (curm + 1<m&&a[i] == b[curm + 1]) {
			curm++;
			c[i] = curm;
		}
		else c[i] = i ? c[i - 1] : -1;
	}
}
int d1[N], d2[N];
int cum[6][N]; int tp[N];
//rg,gb,br, rb,bg,gr
int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	scanf("%s", b1);
	scanf("%s", b2);
	int n = strlen(b1);
	int m = strlen(b2);
	fill(b1, n, b2, m, d1);
	fill(b2, m, b1, n, d2);
	tp[0] = -1;
	for (int i = 1; i<n; i++) {
		if (b1[i] == b1[i - 1]) {
			tp[i] = -1; continue;
		}
		switch (b1[i - 1]) {
		case 'R':
			tp[i] = (b1[i] == 'G') ? 0 : 3;
			break;
		case 'G':
			tp[i] = (b1[i] == 'R') ? 5 : 1;
				break;
		case 'B':
			tp[i] = (b1[i] == 'R') ? 2 : 4;
		}
	}
	for (int i = 1; i<m; i++) {
		if (b2[i] == b2[i - 1]) {
			continue;
		}
		switch (b2[i - 1]) {
		case 'R':
			cum[(b2[i] == 'G') ? 0 : 3][i] = 1;
			break;
		case 'G':
			cum[(b2[i] == 'R') ? 5 : 1][i] = 1;
			break;
		case 'B':
			cum[(b2[i] == 'R') ? 2 : 4][i] = 1;
		}
	}
	for (int i = 0; i<6; i++) {
		int t = 0;
		for (int j = 0; j<m; j++) {
			int r = cum[i][j + 1];
			cum[i][j + 1] = cum[i][j] + t;
			t = r;
		}
	}
	long long ans = 0;
	int r = 0;
	for (int i = 0; i<n; i++) {
		while (r<m-1&&d2[r]<i)r++;
		int l = (i) ? d1[i - 1] + 1 : 0;
		if (l > r)continue;
		int x = r - l + 1;
		if (tp[i] != -1)x -= cum[5 - tp[i]][r + 1] - cum[5 - tp[i]][l];
		ans += x;
	}
	printf("%I64d\n", ans);
}