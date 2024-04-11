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
#ifndef __GNUG__
int __builtin_popcount(int n) {
	int c = 0;
	while (n) {
		n -= n&(-n); c++;
	}
	return c;
}
#endif
#define FN "contest"
//----------------------------------------------------------------------------//

int c[1000001];

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int n, m, k; nii(n, m); ni(k);
	F(i, m) {
		int x; ni(x); 
		c[x] = 1;
	}
	if (c[1]) {
		puts("1"); return 0;
	}
	int cur = 1;
	F(i, k) {
		int u, v; nii(u, v); 
		if (cur == u) {
			cur = v;
		}
		else if (cur == v)cur = u;
		if (c[cur]) {
			printf("%d\n", cur); return 0;
		}
	}
	printf("%d\n", cur);

}