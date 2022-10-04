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
#define F(i,n) for(int i = 0; i < (n); i++)
#define FF(i,n) for(int i = 1; i <= (n); i++)
#define FE(i,n) for(int i = 0; i <= (n); i++)

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const ll infl = 9012345678901234567;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

int d[2][501][501];
int a[500];
int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int n, m, b, p;
	nii(n, m); nii(b, p);
	F(i, n)ni(a[i]);
	FE(k, b) d[0][0][k] = 1;
	int cur = 0;
	F(i, n) {
		cur ^= 1;
		FE(j, m) {
			FE(k, b) {
				d[cur][j][k] = d[cur ^ 1][j][k];
				if (j > 0 && k >= a[i]) {
					d[cur][j][k] += d[cur][j - 1][k - a[i]];
					if (d[cur][j][k] >= p)d[cur][j][k] -= p;
				}
			}
		}
	}
	printf("%d\n", d[cur][m][b]%p);
	return 0;
}