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
const int N = 200000;
vector<int> adj[N];
int rnk[N];
int cnt[N];
int par[N];
ll ans = 0;

void dfs(int u) {
	if (cnt[u])ans += rnk[u];
	for (auto &x : adj[u]) {
		if (x == par[u])continue;
		par[x] = u;
		rnk[x] = rnk[u] + 1;
		dfs(x);
		cnt[u] += cnt[x];
	}
}
void dfs1(int u, int d) {
	int Mx = -1;
	for (auto &x : adj[u]) {
		if (x == par[u])continue;
		if (Mx == -1 || cnt[Mx] < cnt[x])Mx = x;
	}
	if (Mx == -1)return;
	if (cnt[Mx] - d > cnt[u] - cnt[Mx]) {
		ans -= (ll)rnk[u] * (cnt[u] - cnt[Mx])*2;
		dfs1(Mx, d + cnt[u] - cnt[Mx]);
	}
	else {
		ans -= (ll)(cnt[u] - d)*rnk[u];
	}
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int n, k; nii(n, k);
	F(i, 2 * k) {
		int u; ni(u); u--;
		cnt[u] = 1;
	}
	F(i, n - 1) {
		int u, v; nii(u, v); u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	par[0] = -1;
	dfs(0);
	dfs1(0, 0);
	printf("%I64d\n", ans);
	return 0;
}