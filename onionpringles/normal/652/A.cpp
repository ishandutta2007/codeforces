#pragma warning(disable:4996)

#include <stdio.h>
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
#include <random>
#include <time.h>
#include <tuple>
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
#define print(x) printf("%d\n", x)

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int h1, h2, a, b;
	nii(h1, h2); nii(a, b);
	int curh = h1;
	F(i, inf) {
		curh += a * 8;
		if (curh >= h2) {
			print(i);
			return 0;
		}
		curh -= b * 12;
		curh += a * 4;
		if (i == 0 && curh <= h1) {
			puts("-1");
			return 0;
		}
	}
	return 0;
}