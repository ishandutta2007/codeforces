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

const int N = 301010, LG = 19;

int nxt[N][LG], a[N], it[LG];
vector<int> V[LG];
int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int n, q; nii(n, q);
	F(i, n)ni(a[i]);
	F(i, n)F(j, LG)if (a[i] & 1 << j)V[j].push_back(i);
	F(j, LG)it[j] = V[j].size();
	for (int i = n; i--;) {
		F(j, LG) nxt[i][j] = n;
		F(j, LG)if (a[i] & 1 << j) {
			if (it[j] == V[j].size()) {
				it[j]--; continue;
			}
			int ni = V[j][it[j]--];
			F(k, LG) {
				if (a[ni] & 1 << k)nxt[i][k] = min(nxt[i][k], ni);
				else nxt[i][k] = min(nxt[i][k], nxt[ni][k]);
			}
		}
	}
	while (q--) {
		int s, e; nii(s, e); s--; e--;
		bool good = false;
		F(i, LG)if (a[e] & 1 << i) {
			if (nxt[s][i] <= e)good = true;
		}
		if (good)puts("Shi");
		else puts("Fou");
	}
}