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

const int N = 1000000;
int d[N];
int par[N];
int mg = 0;
int c[N];
int find(int i) {
	return par[i] < 0 ? i : (par[i] = find(par[i]));
}
void merge(int i, int j) {
	i = find(i); j = find(j);
	if (i == j)return;
	if (par[i] < par[j])swap(i, j);
	mg++;
	par[j] += par[i];
	par[i] = j;
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int n, m; nii(n, m);
	if (m == 1) {
		puts("0"); return 0;
	}
	int L = 0;
	F(i, n)par[i] = -1;
	F(i, m) {
		int u, v; nii(u, v); u--; v--;
		c[u] = c[v] = 1;
		if (u != v) {
			d[u]++; d[v]++;
			merge(u, v);
		}
		else L++;
	}
	int sm = 0;
	F(i, n) {
		sm += c[i];
	}
	if (mg != sm - 1) {
		puts("0"); return 0;
	}
	ll ans = 0;
	ans += (ll)L*(L - 1) / 2;
	F(i, n) {
		ans += (ll)d[i] * (d[i] - 1) / 2;
	}
	ans += (ll)(m - L)*L;
	printf("%lld\n", ans);
	return 0;
}