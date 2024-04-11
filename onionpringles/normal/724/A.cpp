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
char buf[1000];
int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	auto f = [](const char* buf) {
		if (buf[0] == 'm') return 1;
		else if (buf[0] == 'w') return 3;
		else if (buf[0] == 'f') return 5;
		else if (buf[1] == 'h') return 4;
		else if (buf[1] == 'a') return 6;
		else if (buf[0] == 't') return 2;
		else return 0;
	};
	int v1, v2;
	scanf("%s", buf);
	v1 = f(buf);
	scanf("%s", buf);
	v2 = f(buf);
	int dif = (v2 - v1 + 14) % 7;
	if (dif == 0 || dif == 3 || dif == 2)puts("YES");
	else puts("NO");

	return 0;
}