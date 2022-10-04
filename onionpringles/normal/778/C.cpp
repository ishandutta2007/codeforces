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

const int N = 300010;
vector<pair<int, char> > adj[N];
int id[N][26];
int cnt[N];
int rnk[N];
int dp[N];
int dg[N];
vector<int> ht[N];


int dfs2(int u, int v,vector<int>& hist) {
	int ret = 1;
	for (auto &x : adj[u]) {
		int c = x.second - 'a';
		if (id[v][c] != -1) {
			ret += dfs2(x.first, adj[v][id[v][c]].first, hist);
		}
		else {
			hist.push_back(v);
			id[v][c] = adj[v].size();
			adj[v].emplace_back(x.first, x.second);
		}
	}
	return ret;
}

void dfs(int u) {
	ht[rnk[u]].push_back(u);
	cnt[u] = 1;
	for (auto &x : adj[u]) {
		rnk[x.first] = rnk[u] + 1;
		dfs(x.first);
		cnt[u] += cnt[x.first];
	}
	if (adj[u].size() <= 1) {
		dp[u] = adj[u].size();
		return;
	}
	else {
		int M = adj[u][0].first;
		dp[u] = 1;
		for (auto &x : adj[u]) {
			if (cnt[M] < cnt[x.first])M = x.first;
		}
		vector<int> V;
		for (auto &x : adj[u]) {
			if (x.first == M) continue;
			dp[u] += dfs2(x.first, M, V);
		}
		for (auto &x : V) {
			auto p = adj[x].back();
			adj[x].pop_back();
			id[x][p.second - 'a'] = -1;
		}
	}
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int n; ni(n);
	F(i, n)F(j, 26)id[i][j] = -1;
	F(i, n - 1) {
		int u, v; char c;
		nii(u, v); scanf(" %c", &c);
		u--; v--;
		id[u][c - 'a'] = adj[u].size();
		adj[u].emplace_back(v, c);
		dg[u]++;
	}
	dfs(0);
	int val = -1, j = -1;
	F(i, n) {
		int sum = 0;
		for (auto &x : ht[i]) sum += dp[x];
		if (sum > val) {
			j = i;
			val = sum;
		}
	}
	printf("%d\n%d\n", n - val, j + 1);
	return 0;
}