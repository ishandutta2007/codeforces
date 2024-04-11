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

const int N = 300000;
int c[N];
vector<int> adj[N];
int q[N], chk[N], cl[N];

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int d;
	int n, k; nii(n, k); ni(d);
	F(i, k) {
		int p; ni(p);
		c[--p] = 1;
	}
	map<pii, int> ind;
	F(i, n - 1) {
		int u, v; nii(u, v); u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
		ind[mp(u, v)] = i + 1;
		ind[mp(v, u)] = i + 1;
	}
	int num = 0;
	int qs = 0, qe = 0;
	F(i, n) {
		if (c[i]) {
			num++;
			cl[i] = i;
			chk[i] = 1;
			q[qe++] = i;
		}
	}
	while (qs < qe) {
		int u = q[qs++];
		for (auto &x : adj[u]) {
			if (chk[x])continue;
			cl[x] = cl[u];
			chk[x] = 1;
			q[qe++] = x;
		}
	}
	printf("%d\n", num - 1);
	F(i, n) {
		for (auto &x : adj[i]) {
			if (cl[i] != cl[x] && i < x)printf("%d ", ind[mp(i, x)]);
		}
	}
	puts("");
}