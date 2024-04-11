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

const int N = 2001;

double d[N][N];
int c[N][N];

double p[N], u[N];

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	int n; ni(n);
	int a, b; nii(a, b);
	F(i, n) scanf("%lf", p + i);
	F(i, n) scanf("%lf", u + i);
	double low = -1e4;
	double high = 1e4;
	for (int i = 0; i < 50; i++) {
		double mid = (low + high) / 2;
		d[0][0] = 0;
		c[0][0] = 0;
		FF(i, n) {
			F(j, i + 1) {
				d[i][j] = -1e5;
				if (j > 0) {
					if (d[i][j] < d[i - 1][j - 1] + p[i - 1]) {
						d[i][j] = d[i - 1][j - 1] + p[i - 1];
						c[i][j] = c[i - 1][j - 1];
					}
					if (d[i][j] < d[i - 1][j - 1] + p[i - 1] + u[i - 1] - p[i - 1] * u[i - 1] + mid) {
						d[i][j] = d[i - 1][j - 1] + p[i - 1] + u[i - 1] - p[i - 1] * u[i - 1] + mid;
						c[i][j] = c[i - 1][j - 1] + 1;
					}
				}
				if (j < i) {
					if (d[i][j] < d[i - 1][j] + u[i - 1] + mid) {
						d[i][j] = d[i - 1][j] + u[i - 1] + mid;
						c[i][j] = c[i - 1][j] + 1;
					}
					if (d[i][j] < d[i - 1][j]) {
						d[i][j] = d[i - 1][j];
						c[i][j] = c[i - 1][j];
					}
				}
			}
		}
		if (c[n][a] >= b) high = mid;
		else low = mid;
	}
	printf("%.15f\n", d[n][a] - b*high);
}