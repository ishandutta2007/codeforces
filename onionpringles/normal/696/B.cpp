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

const int N = 100000;
int cnt[N];
int par[N];
vector<int> adj[N];
double ans[N];

void dfs(int u) {
	int S = cnt[u] - 1;
	int n = adj[u].size();
	for (auto &x : adj[u]) {
		ans[x] = ans[u] + 1 + (S - cnt[x]) / 2.0;
		dfs(x);
	}
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int n; ni(n);
	F(i, n)cnt[i] = 1;
	F(i, n - 1) {
		int x; ni(x);
		x--;
		adj[x].push_back(i + 1);
		par[i + 1] = x;
	}
	for (int i = n - 1; i > 0; i--)cnt[par[i]] += cnt[i];
	ans[0] = 1;
	dfs(0);
	F(i, n)printf("%.15f\n", ans[i]);
}