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

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const ll infl = 9012345678901234567;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//
char buf[1000];
int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int n; ni(n);
	int c = 20000;
	int m = 20000;
	F(i, n) {
		int d; ni(d);
		scanf("%s", buf);
		if (buf[0] == 'S') {
			if (d > c) {
				puts("NO"); return 0;
			}
			c -= d;
		}
		else if (buf[0] == 'W') {
			if (c == 0 || c == 20000) {
				puts("NO"); return 0;
			}
		}
		else if (buf[0] == 'E') {
			if (c == 0 || c == 20000) {
				puts("NO"); return 0;
			}
		}
		else{
			if (d > 20000 - c) {
				puts("NO"); return 0;
			}
			c += d;
		}
	}
	if(c==20000)
	puts("YES");
	else puts("NO");
	return 0;
}