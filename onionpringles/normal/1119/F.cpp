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
const int mod = 1000000007;
const int inf = 2012345678;
const ll infl = 9012345678901234567;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

const int N = 252525;
int cur[N], par[N], ord[N], m, parv[N], clk[N];
set<pair<ll,int>> A[N], B[N];
ll d[N][2], Asum[N], d0sum[N];
vector<int> V;
vector<pii> adj[N];
void dfs0(int u, int p = -1) {
	par[u] = p;
	for (auto &x : adj[u])if (x.first != p)parv[x.first] = x.second, dfs0(x.first, u);
	ord[m++] = u;
}
int find(int u) {
	if (par[u] == -1 || !cur[par[u]])return u;
	else return par[u] = find(par[u]);
}
void Erase(int u, pair<ll, int> v) {
	if (A[u].count(v)) {
		A[u].erase(v);
		Asum[u] -= v.first;
	}
	else B[u].erase(v);
}
void Insert(int u, pair<ll, int> v) {
	if (A[u].size() && v.first <= prev(A[u].end())->first) {
		A[u].insert(v);
		Asum[u] += v.first;
	}
	else B[u].insert(v);
}
void d0add(int u, ll X) {
	u = find(u);
	d[u][0] += X;
	if (par[u] == -1)return;
	d0sum[par[u]] += X;
}
ll addK(int u, int K) {
	while ((int)A[u].size() > K || (A[u].size() && prev(A[u].end())->first > 0)) {
		auto it = prev(A[u].end());
		B[u].insert(*it);
		Asum[u] -= it->first;
		A[u].erase(it);
	} 
	while ((int)A[u].size() < K && B[u].size() && B[u].begin()->first < 0) {
		auto it = B[u].begin();
		Asum[u] += it->first;
		A[u].insert(*it);
		B[u].erase(it);
	}
	return Asum[u];
}
int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int n; ni(n);
	F(i, n)clk[i] = -1;
	ll tot = 0;
	F(i, n - 1) {
		int u, v, c; nii(u, v); ni(c);
		u--; v--; tot += c;
		adj[u].emplace_back(v, c);
		adj[v].emplace_back(u, c);
	}
	F(i, n)V.push_back(i);
	sort(V.begin(), V.end(), [](int i, int j) {return adj[i].size() > adj[j].size(); });
	
	dfs0(0);

	F(i, n) {
		d[i][1] = -infl;
		if (par[i] != -1) {
			Insert(par[i], { d[i][0] - d[i][1] - parv[i],i });
		}
	}
	printf("%lld ", tot);

	for (int K = 1; K < n; K++) {
		while (V.size() && adj[V.back()].size() == K) {
			int u = V.back(); V.pop_back();
			cur[u] = 1;
			if (par[u] != -1 && !cur[par[u]]) Erase(par[u], { -d[u][1] - parv[u] + d[u][0],u }), d0sum[par[u]] -= d[u][0];
			ll curv = max(d[u][0], d[u][1] + parv[u]);
			d[u][0] = 0;
			for (auto &x : adj[u]) {
				if (x.first == par[u])continue;
				if (cur[x.first]) d[u][0] += d[x.first][0] + parv[x.first];
				else d[u][0] += max(d[x.first][0], d[x.first][1] + parv[x.first]);
			}
			if (par[u] == -1)continue;
			else if (cur[par[u]]) {
				d0add(par[u], d[u][0] + parv[u] - curv);
			}
			else {
				Insert(par[u], { -parv[u],u });
				d0sum[par[u]] += d[u][0];
			}
		}
		int j = 0;
		for (int i = 0; i < m; i++) {
			int u = ord[i];
			if (cur[u])continue;
			ord[j++] = u;
			if (par[u] != -1 && !cur[par[u]]) {
				Erase(par[u], { -d[u][1] - parv[u] + d[u][0],u });
				d0sum[par[u]] -= d[u][0];
			}
			ll curv = max(d[u][0], d[u][1] + parv[u]);
			d[u][0] = d0sum[u] - addK(u, K);
			d[u][1] = d0sum[u] - addK(u, K - 1);
			if (par[u] == -1)continue;
			else if (cur[par[u]]) {
				d0add(par[u], max(d[u][0], d[u][1] + parv[u]) - curv);
			}
			else {
				Insert(par[u], { -d[u][1] - parv[u] + d[u][0],u });
				d0sum[par[u]] += d[u][0];
			}
		}
		m = j;
		printf("%lld ", tot - d[0][0]);
	}
	puts("");
	return 0;
}