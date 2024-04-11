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
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//
const ll infll = (ll)inf*(inf);
const int N = 200000;
ll d[N];
ll e[N];
int a[N];
vector<int> adj[N];
int par[N];
ll ans = -infll;
void dfs(int u) {
	d[u] = a[u];
	ll M1 = -infll, M2 = -infll;
	auto upd = [&](ll x) {
		if (x > M2) M2 = x;
		if (M2 > M1)swap(M1, M2);
	};
	for (auto &x : adj[u]) {
		if (x == par[u])continue;
		par[x] = u;
		dfs(x);
		d[u] += d[x];
		upd(e[x]);
	}
	if (M2 > -infll) ans = max(ans, M1 + M2);
	e[u] = d[u];
	for (auto &x : adj[u]) {
		if (x == par[u])continue;
		e[u] = max(e[u], e[x]);
	}
}
int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int n; ni(n);
	F(i, n)ni(a[i]);
	F(i, n - 1) {
		int x, y; nii(x, y); x--; y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	par[0] = -1;
	dfs(0);
	if (ans == -infll) puts("Impossible");
	else printf("%I64d\n", ans);
}