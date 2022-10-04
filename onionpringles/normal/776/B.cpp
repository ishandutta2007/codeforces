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

const int N = 101010;
int chk[N];

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	for (int i = 2; i < N; i++) {
		if (chk[i])continue;
		for (int j = i + i; j < N; j+= i) chk[j] = 1;
	}
	int n; scanf("%d", &n);
	if (n <= 2) {
		printf("%d\n", 1);
		F(i, n)printf("%d ", 1);
		puts("");
		return 0;
	}
	puts("2");
	for (int i = 2; i <= n + 1; i++) {
		if (chk[i])printf("%d ", 1);
		else printf("%d ", 2);
	}
	return 0;
}