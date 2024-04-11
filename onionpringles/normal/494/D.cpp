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
const ll infll = 9000000000000000000LL;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

const int N = 101010;
const int LG = 17;
vector<pii> adj[N];
int cnt[N];
int c1[N];
int c2[N];
int s1[N];
int s2[N];
int n;
int par[N];
int anc[N][LG];
int d[N];
int rnk[N];
void dfs(int u) {
	cnt[u] = 1;
	for (auto &p : adj[u]) {
		int v = p.first;
		if (v == par[u]) continue;
		par[v] = u;
		d[v] = d[u] + p.second;
		if (d[v] >= mod) d[v] -= mod;
		rnk[v] = rnk[u] + 1;
		dfs(v);
		cnt[u] += cnt[v];
		c1[u] += (0LL + mul(p.second, cnt[v]) + c1[v]) % mod;
		if (c1[u] >= mod)c1[u] -= mod;
		ll x = c2[u];
		x += 0LL + mul(mul(p.second, p.second), cnt[v]) + 2LL*p.second*c1[v] + c2[v];
		c2[u] = x%mod;
	}
}
void dfs2(int u,int a1 = 0,int a2 = 0) {
	s1[u] = (0LL + a1 + c1[u]) % mod;
	s2[u] = (0LL + a2 + c2[u]) % mod;
	for (auto &p : adj[u]) {
		int v = p.first;
		if (v == par[u]) continue;
		int d1 = (0LL + s1[u] - c1[v] - mul(p.second, cnt[v])) % mod;
		if (d1 < 0) d1 += mod;
		int a1 = (0LL + d1 + mul(p.second, (n - cnt[v]))) % mod;
		if (a1 < 0) a1 += mod;
		int a2 = (0LL + s2[u] - c2[v] + mul(2 * p.second, d1 - c1[v]) + mul(n - 2 * cnt[v], mul(p.second, p.second)))%mod;
		if (a2 < 0) a2 += mod;
		dfs2(v, a1, a2);
	}
}
int lca(int u, int v) {
	if (rnk[u] < rnk[v]) swap(u, v);
	int d = rnk[u] - rnk[v];
	F(i, LG)if (d&(1 << i))u = anc[u][i];
	if (u == v)return u;
	for (int i = LG - 1; i >= 0; i--)if (anc[u][i] != anc[v][i])u = anc[u][i], v = anc[v][i];
	return anc[u][0];
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	ni(n);
	F(i, n - 1) {
		int u, v, c; nii(u, v); u--; v--;
		ni(c);
		adj[u].emplace_back(v, c);
		adj[v].emplace_back(u, c);
	}
	par[0] = -1;
	dfs(0);
	dfs2(0);
	F(i, n) anc[i][0] = par[i];
	FF(j, LG - 1)F(i, n) anc[i][j] = (anc[i][j - 1] == -1) ? -1 : anc[anc[i][j - 1]][j - 1];
	int Q; ni(Q);
	F(q, Q) {
		int u, v; nii(u, v); u--; v--;
		int L = lca(u, v);
		if (L == v) {
			ll d = ::d[u] - ::d[v];
			ll p1 = s1[v] - c1[v];
			ll p2 = s2[v] - c2[v];
			ll x = mul(d, d)*(ll)(n - cnt[v]) + 2 * d*p1%mod + p2;
			x = x%mod;
			x = s2[u] - 2 * x;
			x = x%mod;
			if (x < 0) x += mod;
			printf("%d\n", (int)x);
		}
		else {
			ll d = 0LL + ::d[u] + ::d[v] - 2 * ::d[L];
			d = d%mod;
			ll x = d*d%mod*cnt[v] % mod + 2 * d*c1[v] % mod + c2[v];
			x = x%mod;
			x = 2 * x - s2[u];
			x = x%mod;
			if (x < 0) x += mod;
			printf("%d\n", (int)x);
		}
	}
	return 0;
}