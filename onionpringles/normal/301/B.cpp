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
const int N = 100;
int x[N], y[N], a[N];
int cst[N], chk[N];
int d;
int dist(int i, int j) {
	return d*(abs(x[i] - x[j]) + abs(y[i] - y[j]));
}
int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	int n; nii(n, d);
	FF(i, n - 2)  ni(a[i]);
	F(i, n) nii(x[i], y[i]);
	chk[n - 1] = 1;
	while (!chk[0]) {
		int ii = -1; int cur = inf;
		F(i, n) {
			if (chk[i]) continue;
			int c = inf;
			F(j, n) {
				if (chk[j]) {
					c = min(c, max(dist(i,j) - a[i],cst[j] + dist(i, j) - a[i]));
				}
			}
			if (c < cur) {
				ii = i;
				cur = c;
			}
		}
		chk[ii] = 1;
		cst[ii] = cur;
	}
	if (cst[0] < 0) cst[0] = 0;
	printf("%d\n", cst[0]);
	return 0;
}