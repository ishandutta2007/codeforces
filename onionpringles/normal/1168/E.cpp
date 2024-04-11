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
#include <array>
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

#ifndef __GNUG__
int __builtin_popcount(int n) {
	int x = 0;
	while (n)n -= n&(-n), x++;
	return x;
}
#endif

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000009;
const int inf = 2012345678;
const ll infl = 9012345678901234567;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

const int N = (1 << 12) + 10;
int a[N], s[N], t[N], rt[N], b[N], c[N], chk[N], se[N], m;

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int k; ni(k);

	F(i, 1 << k)ni(a[i]);
	int X = 0;
	F(i, 1 << k)X ^= a[i];
	if (X)return puts("Fou"), 0;
	puts("Shi");
	F(i, 1 << k)s[i] = t[i] = i;
	F(i, 1 << k) {
		if (a[i] == b[i])continue;
		F(j, 1 << k)rt[t[j]] = j, c[j] = b[j], chk[j] = 0;
		m = 2;
		se[0] = i;
		se[1] = i + 1;
		chk[i] = chk[i + 1] = 1;
		int X = a[i] ^ b[i];
		c[i] ^= X;
		c[i + 1] ^= X;
		int p = 0;
		while (1) {
			int j = rt[c[se[m - 1]] ^ s[se[m - 2]]];
			se[m] = j;
			if (chk[j]) {
				if (j == se[1])p = 1;
				break;
			}
			chk[j] = 1;
			m++;
		}
		int ss = s[se[m - 1]];
		for (int i = m; --i;)s[se[i]] = s[se[i - 1]];
		s[se[0]] = ss;
		ss = t[se[p ^ 1]];
		int tt = t[se[p]];
		for (int j = 1; j < m; j++)t[se[j]] = t[se[j + 1]];
		if (p == 1)t[se[m - 1]] = tt;
		t[se[0]] = ss;
		b[i] = c[i];
		b[i + 1] = c[i + 1];
	}

	F(i, 1 << k)printf("%d ", t[i]); puts("");
	F(i, 1 << k)printf("%d ", s[i]); puts("");
	return 0;
}