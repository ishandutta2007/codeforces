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

pii axpby(int a, int b) {
	//a,b must be less than 2^30
	int xx = 1; int yy = 0; int dd = a;
	int x = 0; int y = 1; int d = b;
	while (d) {
		int q = dd / d;

		int tmp = d;
		d = dd - d*q;
		dd = tmp;

		tmp = x;
		x = xx - x*q;
		xx = tmp;

		tmp = y;
		y = yy - y*q;
		yy = tmp;
	}
	//xx, yy are not guaranteed to be positive
	return mp(xx, yy);
}

const int N = 100010;
vector<pii> adj[N];
int par[N];
int p10[N]; int i10[N];
int da[N], db[N];
int rnk[N];
int M;
map<int, int> a[N], b[N];
void dfs(int u) {
	for (auto &p : adj[u]) {
		int x = p.first;
		if (x == par[u])continue;
		par[x] = u;
		da[x] = (da[u] + (ll)p.second*i10[rnk[u] + 1]) % M;
		db[x] = (db[u] + (ll)p.second*p10[rnk[u]]) % M;
		rnk[x] = rnk[u] + 1;
		dfs(x);
	}
}
ll ans = 0;
pii dfs2(int u) {
	int ca = -1, cb = -1;
	int k = rnk[u];
	for (auto &p : adj[u]) {
		int x = p.first;
		if (x == par[u])continue;
		auto pp = dfs2(x);
		a[pp.first][da[x]] = a[pp.first][da[x]] + 1;
		b[pp.second][db[x]] = b[pp.second][db[x]] + 1;
		auto it = a[pp.first].find(da[u]);
		if (it != a[pp.first].end())ans += it->second;
		it = b[pp.second].find(db[u]);
		if (it != b[pp.second].end())ans += it->second;
		if (ca == -1) {
			ca = pp.first;
			cb = pp.second;
			continue;
		}
		if (a[ca].size() + b[cb].size() < a[pp.first].size() + b[pp.second].size()) {
			swap(ca, pp.first);
			swap(cb, pp.second);
		}
		for (auto &q : a[pp.first]) {
			int X = (db[u] - (ll)(p10[k])*p10[k] % M*(q.first - da[u])) % M;
			if (X < 0)X += M;
			auto it = b[cb].find(X);
			if (it != b[cb].end())ans += (ll)q.second*it->second;
		}
		for (auto &q : b[pp.second]) {
			int Y = (da[u] - (ll)i10[k] * i10[k] % M*(q.first - db[u])) % M;
			if (Y < 0) Y += M;
			auto it = a[ca].find(Y);
			if (it != a[ca].end())ans += (ll)q.second*it->second;
		}
		for (auto &q : a[pp.first]) {
			a[ca][q.first] = a[ca][q.first] + q.second;
		}
		for (auto &q : b[pp.second]) b[cb][q.first] = b[cb][q.first] + q.second;
	}
	if (ca == -1) {
		return make_pair(u, u);
	}
	else return make_pair(ca, cb);
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int n; ni(n);  ni(M);
	F(i, n - 1) {
		int u, v, w; nii(u, v); ni(w);
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	if (M == 1) {
		printf("%I64d\n", (ll)n*(n - 1));
		return 0;
	}
	p10[0] = 1; i10[0] = 1;
	FF(i, n) {
		p10[i] = (ll)p10[i - 1] * 10 % M;
		i10[i] = axpby(p10[i], M).first;
		i10[i] = (i10[i] % M + M) % M;

	}
	par[0] = -1;
	dfs(0);
	dfs2(0);
	printf("%I64d\n", ans);
	return 0;
}