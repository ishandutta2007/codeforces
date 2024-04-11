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

const int N = 1000;
const int M = 30000;
struct Edge {
	int u, v; int w;
	bool tree; bool val;
	Edge() {}
	Edge(int a, int b, int c) :u(a), v(b), w(c), tree(false), val(true) {}
	inline int get(int _u) {
		return (u == _u) ? v : u;
	}
} el[M];

int chk[M];
int vis[N];
vector<int> adj[N];

void dfs(int u) {
	vis[u] = 1;
	for (auto &i : adj[u]) {
		if (chk[i])continue;
		chk[i] = 1;
		int v = el[i].get(u);
		if (vis[v])continue;
		el[i].tree = true;
		dfs(v);
	}
}

int rnk[N];
int up[N];
int par[N];
void dfs2(int u) {
	vis[u] = 1;
	up[u] = rnk[u];
	for (auto &i : adj[u]) {
		if (el[i].val == false)continue;
		if (i == par[u])continue;
		int v = el[i].get(u);
		if (vis[v]) {
			up[u] = min(up[u], rnk[v]);
			continue;
		}
		par[v] = i;
		rnk[v] = rnk[u] + 1;
		dfs2(v);
		up[u] = min(up[u], up[v]);
	}
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int n, m, s, t; nii(n, m); nii(s, t);
	s--; t--;

	F(i, m) {
		int x, y; nii(x, y); x--; y--;
		int w; ni(w);
		el[i] = Edge(x, y, w);
		adj[x].push_back(i);
		adj[y].push_back(i);
	}
	dfs(s);
	if (!vis[t]) {
		puts("0\n0\n\n"); return 0;
	}
	int ans = inf; vector<int> aa;
	F(i, m) {
		if (el[i].tree) {
			el[i].val = false;
			rnk[s] = 0;
			par[s] = -1;
			memset(vis, 0, sizeof(vis));
			dfs2(s);
			el[i].val = true;
			if (!vis[t]) {
				if (ans > el[i].w) {
					ans = el[i].w;
					aa = { i };
				}
				continue;
			}
			int tt = t;
			while (tt != s) {
				int j = par[tt];
				if (up[tt] == rnk[tt]) {
					if (ans > el[i].w + el[j].w) {
						ans = el[i].w + el[j].w;
						aa = { i,j };
					}
				}
				tt = el[j].get(tt);
			}
		}
	}
	if (ans == inf) {
		puts("-1"); return 0;
	}
	printf("%d\n%d\n", ans, (int)aa.size());
	for (auto &x : aa)printf("%d ", x + 1); puts("");
	return 0;
}