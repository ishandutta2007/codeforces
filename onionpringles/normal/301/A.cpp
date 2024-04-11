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

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	int _m = 1001;
	int n; ni(n);
	int s = 0;
	int cnt = 0;
	F(i, 2 * n - 1) {
		int x; ni(x);
		if (x < 0) x = -x, cnt++;
		s += x;
		_m = min(_m, x);
	}
	if (n % 2 == 0 && cnt % 2 == 1) s -= 2*_m;
	printf("%d\n", s);


	return 0;
}