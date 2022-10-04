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
#define tr1 TR1
const int B = 1 << 18, N = 151515, LG = 18;
int tr1[B << 1], tr1mod[B << 1];
int tr2[26][B << 1], tr2mod[26][B << 1];

void upd(int tr[], int modi[], int l, int r, int v, int nd = 1, int ndl = 0, int ndr = B - 1) {
	if (ndr < l || r < ndl)return;
	else if (l <= ndl&&ndr <= r) {
		modi[nd] += v;
		tr[nd] += v;
	}
	else {
		int mid = ndl + ndr >> 1;
		upd(tr, modi, l, r, v, nd << 1, ndl, mid);
		upd(tr, modi, l, r, v, nd << 1 | 1, mid + 1, ndr);
		tr[nd] = max(tr[nd << 1], tr[nd << 1 | 1]) + modi[nd];
	}
}

int get(int tr[], int modi[], int l, int r, int nd = 1, int ndl = 0, int ndr = B - 1) {
	if (ndr < l || r < ndl) return -inf;
	else if (l <= ndl&&ndr <= r) {
		return tr[nd];
	}
	else {
		int mid = ndl + ndr >> 1;
		return max(get(tr, modi, l, r, nd << 1, ndl, mid), get(tr, modi, l, r, nd << 1 | 1, mid + 1, ndr)) + modi[nd];
	}
}

char parc[N];
int par[N], dpth[N], cnt[N], hv[N], anc[N][LG], up[N], clk, L[N], R[N], init[N][26], initmax[N][26];
vector<int> adj[N];
void dfs(int u, bool hve = false) {
	L[u] = clk++;
	memcpy(initmax[u], init[u], sizeof(init[u]));
	if (hve)up[u] = up[par[u]];
	else up[u] = u;
	if (hv[u] != -1) {
		memcpy(init[hv[u]], init[u], sizeof(init[u]));
		if (parc[hv[u]] != '?')init[hv[u]][parc[hv[u]] - 'a']++;
		dfs(hv[u], true);
		F(j, 26)initmax[u][j] = max(initmax[u][j], initmax[hv[u]][j]);
	}
	for (auto &x : adj[u]) {
		if (x == hv[u])continue;
		memcpy(init[x], init[u], sizeof(init[u]));
		if (parc[x] != '?')init[x][parc[x] - 'a']++;
		dfs(x);
		F(j, 26)initmax[u][j] = max(initmax[u][j], initmax[x][j]);
	}
	R[u] = clk;
}
void incr(int u, int j) {
	int curmax = get(tr2[j], tr2mod[j], L[u], R[u] - 1);
	int v = u;
	for (int i = LG; i--;) {
		if (anc[v][i] == -1)continue;
		int M = get(tr2[j], tr2mod[j], L[anc[v][i]], R[anc[v][i]] - 1);
		if (M == curmax)v = anc[v][i];
	}
	upd(tr2[j], tr2mod[j], L[u], R[u] - 1, 1);
	if (u != v) {
		u = par[u];
		while (up[u] != up[v]) {
			upd(tr1, tr1mod, L[up[u]], L[u], 1);
			u = par[up[u]];
		}
		upd(tr1, tr1mod, L[v], L[u], 1);
	}
}
void decr(int u, int j) {
	upd(tr2[j], tr2mod[j], L[u], R[u] - 1, -1);
	int curmax = get(tr2[j], tr2mod[j], L[u], R[u] - 1);
	int v = u;
	for (int i = LG; i--;) {
		if (anc[v][i] == -1) continue;
		int M = get(tr2[j], tr2mod[j], L[anc[v][i]], R[anc[v][i]] - 1);
		if (M == curmax)v = anc[v][i];
	}
	if (u != v) {
		u = par[u];
		while (up[u] != up[v]) {
			upd(tr1, tr1mod, L[up[u]], L[u], -1);
			u = par[up[u]];
		}
		upd(tr1, tr1mod, L[v], L[u], -1);
	}
}
int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int n, q; nii(n, q);
	for (int i = 1; i < n; i++) {
		scanf("%d %c", par + i, parc + i);
		par[i]--;
		adj[par[i]].push_back(i);
	}
	for (int i = n; i--;) {
		cnt[i] = 1;
		for (auto &x : adj[i])cnt[i] += cnt[x];
		hv[i] = -1;
		for (auto &x : adj[i])if (hv[i] == -1 || cnt[x]> cnt[hv[i]])hv[i] = x;
		if (adj[i].empty())dpth[i] = 0;
		else {
			dpth[i] = dpth[adj[i][0]] + 1;
			for (auto &x : adj[i])if (dpth[i] != dpth[x] + 1) {
				while (q--)puts("Fou");
				return 0;
			}
		}
	}
	dfs(0);
	par[0] = -1;
	F(i, n)anc[i][0] = par[i];
	for (int j = 1; j < LG; j++)F(i, n) {
		int a = anc[i][j - 1];
		if (a == -1)anc[i][j] = -1;
		else anc[i][j] = anc[a][j - 1];
	}

	for (int i = 1; i < n; i++) {
		F(j, 26)tr2[j][B + L[i]] = init[i][j];
	}

	F(i, 26)for (int j = B; --j;)tr2[i][j] = max(tr2[i][j << 1], tr2[i][j << 1 | 1]);

	F(i, n) {
		F(j, 26)tr1[B + L[i]] += initmax[i][j] - init[i][j];
		tr1[B + L[i]] -= dpth[i];
	}
	for (int i = B; --i;)tr1[i] = max(tr1[i << 1], tr1[i << 1 | 1]);
	/*
	auto printstat = [&]() {
		return;
		F(i, n) {
			printf("node %d:\n", i);
			printf("(main %d) ", get(tr1, tr1mod, L[i], L[i]));
			F(j, 26)printf("(%c %d)", 'a' + i, get(tr2[j], tr2mod[j], L[i], L[i])); puts("");
		}
	};
	printstat();
	*/
	while (q--) {
		int u; ni(u); u--;
		char c; scanf(" %c", &c);
		if (parc[u] != '?') decr(u, parc[u] - 'a');
		parc[u] = c;
		if (parc[u] != '?') incr(u, parc[u] - 'a');

	//	printf("Query %d %c\n", u, c);
	//	printstat();

		if (get(tr1, tr1mod, L[0], R[0] - 1) > 0)puts("Fou");
		else {
			int lft = -get(tr1, tr1mod, L[0], L[0]), ans = 0;
			F(i, 26) {
				int x = get(tr2[i], tr2mod[i], L[0], R[0]), len = dpth[0];
				ans += (i + 1)*(x + lft);
			}
			printf("Shi %d\n", ans);
		}
	}

}