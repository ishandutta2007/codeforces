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

const int N = 202020;
char b1[N], b2[N];

int d1[N], d2[N];
int loc[26];

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	scanf("%s", b1);
	scanf("%s", b2);
	int n = strlen(b1);
	int m = strlen(b2);
	F(i, 26)loc[i] = -1;
	int curm = -1;
	F(i, n) {
		if (curm + 1 < m && b2[curm + 1] == b1[i]) {
			d1[i] = curm + 1;
			loc[b1[i]-'a'] = curm + 1;
			curm++;
			continue;
		}
		d1[i] = loc[b1[i] - 'a'];
	}
	reverse(b1, b1 + n);
	reverse(b2, b2 + m);
	F(i, 26) loc[i] = -1;
	curm = -1;
	F(i, n) {
		if (curm + 1 < m && b2[curm + 1] == b1[i]) {
			d2[i] = curm + 1;
			loc[b1[i] - 'a'] = curm + 1;
			curm++;
			continue;
		}
		d2[i] = loc[b1[i] - 'a'];
	}
	F(i, n) {
		if (d1[i] + d2[n - 1 - i] < m - 1) {
			puts("No");
			return 0;
		}
	}
	puts("Yes");
}