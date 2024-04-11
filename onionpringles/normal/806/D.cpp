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

const int N = 2000;
int c[N][N];
ll d[N][N];
vector<int> V[N];
int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int n; ni(n);
	int _m = inf;
	F(i, n) {
		FF(j, n - i - 1) {
			int x; ni(x);
			_m = min(_m, x);
			c[i][i + j] = c[i + j][i] = x;
		}
	}
	int x = -1;
	F(i, n)F(j, n)if (i != j) {
		c[i][j] -= _m;
		if (!c[i][j])x = i;
	}
	F(i, n) {
		F(j, n) {
			if (i == j)continue;
			V[i].push_back(j);
			if (i == x)d[i][j] = c[i][j];
			else d[i][j] = c[i][j] + min(c[i][j], c[x][i]);
		}
		sort(V[i].begin(), V[i].end(), [&i](int x, int y) {return c[i][x] < c[i][y]; });
	}
	F(tt, 31) {
		F(i, n) {
			ll curmin = infl;
			F(j, n - 1) {
				int jj = V[i][j];
				if (curmin + c[i][jj] < d[i][jj])d[i][jj] = curmin + c[i][jj];
				curmin = min(curmin, d[jj][i]);
			}
		}
	}
	F(i, n) {
		ll curmin = infl;
		F(j, n)if (j != i)curmin = min(curmin, d[j][i]);
		printf("%lld\n", curmin + (ll)_m*(n - 1));
	}
	return 0;
}