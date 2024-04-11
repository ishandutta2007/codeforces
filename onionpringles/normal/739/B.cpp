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
#define add(x,y) ((ll)(x)+(y))%mod
#define F(i,n) for(int i = 0; i < (n); i++)
#define FF(i,n) for(int i = 1; i <= (n); i++)

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

const int N = 200000;
const int B = 1 << 18;
ll dist[N];
vector<pii> adj[N];
int a[N];
int anc[N][18];
void dfs(int u) {
	for (auto &x : adj[u]) {
		int v = x.first;
		anc[v][0] = u;
		dist[v] = dist[u] + x.second;
		dfs(v);
	}
}
int ans[N];
void dfs2(int u, set<pii> & ret) {
	int cur = u;
	for (int i = 17; i >= 0; i--) {
		int a = anc[cur][i];
		if (a == -1)continue;
		if (dist[a] >= dist[u] - ::a[u]) cur = a;
	}
	for (auto &x : adj[u]) {
		set<pii> h;
		dfs2(x.first, h);
		if (ret.size() < h.size()) {
			for (auto &p : ret)h.insert(p);
			ret = move(h);
		}
		else {
			for (auto &p : h)ret.insert(p);
		}
	}
	ans[u] = (int)ret.size();
	ret.insert(make_pair(cur, u));
	auto it = ret.lower_bound(make_pair(u, -inf));
	while (it != ret.end() && it->first == u) it = ret.erase(it);
}
int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	int n; ni(n);
	F(i, n)ni(a[i]);
	FF(i, n - 1) {
		int x; ni(x); x--;
		anc[i][0] = x;
		int w; ni(w);
		adj[x].emplace_back(i, w);
	}
	anc[0][0] = -1;
	dfs(0);
	FF(j, 17) {
		F(i, n) {
			int a = anc[i][j - 1];
			if (a == -1)anc[i][j] = -1;
			else anc[i][j] = anc[a][j - 1];
		}
	}
	set<pii> s;
	dfs2(0, s);
	F(i, n)printf("%d ", ans[i]);
	puts("");
	return 0;
}