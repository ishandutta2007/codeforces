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

set<pair<long long, int> > S[1 << 18];

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T; scanf("%d", &T);
	F(i, T) {
		char c; scanf(" %c ", &c);
		long long x; scanf("%lld", &x); long long sx = x;
		int val = 0;
		for (int i = 0; i < 18; i++) {
			int rem = x % 10;
			val = val << 1;
			if (rem % 2) val++;
			x /= 10;
		}
		if (c == '+') {
			S[val].insert(make_pair(sx, i));
		}
		else if (c == '-') {

			S[val].erase(S[val].lower_bound(make_pair(sx, 0)));
		}
		else {

			
			printf("%d\n", (int)S[val].size());
		}
	}

	return 0;
}