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
	while (n)n -= n & (-n), x++;
	return x;
}
#endif

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const ll infl = 9012345678901234567;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

const int N = 3010;

vector<int> adj[N];

int cnt[N][N], par[N][N], rnk[N][N];
ll dp[N][N];
vector<int> D[N][N];

void dfs(int r, int u, int p = -1) {
	par[r][u] = p;
	cnt[r][u] = 1;
	for (auto &x : adj[u]) {
		if (x == p)continue;
		rnk[r][x] = rnk[r][u] + 1;
		dfs(r, x, u);
		cnt[r][u] += cnt[r][x];
	}
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif

	int n; ni(n);
	F(i, n - 1) {
		int u, v; nii(u, v);
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	F(i, n)dfs(i, i);

	F(i, n) {
		F(j, n) {
			D[i][rnk[i][j]].push_back(j);
		}
	}

	for (int d = 1; d < n; d++) {
		F(i, n) {
			for (auto &x : D[i][d]) {
				ll V = 1LL * cnt[i][x] * cnt[x][i];
				dp[i][x] = max(dp[i][par[i][x]], dp[x][par[x][i]]) + V;
			}
		}
	}

	ll ans = 0;
	F(i, n)F(j, n)ans = max(ans, dp[i][j]);
	printf("%lld\n", ans);

	return 0;
}