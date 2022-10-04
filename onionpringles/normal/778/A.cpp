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

const int N = 200010;
char p[N], t[N];
int a[N];
int ch[N];
int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	scanf("%s %s", p, t);
	int n = strlen(p);
	int m = strlen(t);
	F(i, n) {
		ni(a[i]); a[i]--;
	}
	int l = 0, h = n;
	while (l != h) {
		int mid = (l + h) / 2;
		F(i, mid)ch[a[i]] = 1;
		int cr = 0;
		F(i, n) {
			if (cr == m) break;
			if (ch[i])continue;
			if (p[i] == t[cr])cr++;
		}
		if (cr == m) {
			l = mid + 1;
		}
		else h = mid;
		F(i, mid)ch[a[i]] = 0;
	}
	printf("%d\n", l - 1);

	return 0;
}