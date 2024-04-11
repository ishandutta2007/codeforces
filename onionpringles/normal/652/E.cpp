#pragma warning(disable:4996)

#include <stdio.h>
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
#include <random>
#include <time.h>
#include <tuple>
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
#define print(x) printf("%d\n", x)

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

const int N = 300000;

vector<pii> adj[N];
vector<pii> adj2[N];

int cc[N];
int ccn = 0;
vector<pair<pii, int> > bridge;
int atf[N];

list<int> stk;

int vis[N];

int top[N];
int rnk[N];
int par[N];

int a, b;

void dfs(int i) {
	vis[i] = 1;
	top[i] = rnk[i];
	list<int> tmpstk;
	for (auto &x : adj[i]) {
		if (vis[x.first]) {
			if (x.first == par[i]) continue;
			top[i] = min(top[i], rnk[x.first]);
			continue;
		}
		par[x.first] = i;
		rnk[x.first] = rnk[i] + 1;
		dfs(x.first);
		if (top[x.first] == rnk[x.first]) {
			bridge.push_back(mp(mp(i, x.first), x.second));
		}
		else {
			tmpstk.splice(tmpstk.end(), stk);
		}
		top[i] = min(top[i], top[x.first]);
	}
	tmpstk.push_back(i);
	if (top[i] == rnk[i]) {
		for (auto &y : tmpstk) {
			cc[y] = ccn;
		}
		ccn++;
		return;
	}
	else {
		stk.splice(stk.end(), tmpstk);
	}
}

void dfs2(int i, int tp = 0) {
	vis[i] = 1;
	if (atf[i]) tp = 1;
	if (i == b) {
		if (tp) puts("YES");
		else puts("NO");
		exit(0);
	}
	for (auto &x : adj2[i]) {
		if (vis[x.first]) continue;
		dfs2(x.first, tp | x.second);
	}
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m; nii(n, m);
	F(i, m) {
		int x, y, z;
		nii(x, y); ni(z);
		x--; y--;
		adj[x].push_back(mp(y, z));
		adj[y].push_back(mp(x, z));
	}
	par[0] = -1;
	rnk[0] = 0;
	dfs(0);
	F(i, n) {
		for (auto &x : adj[i]) {
			if (cc[i] == cc[x.first]) atf[cc[i]] |= x.second;
		}
	}
	for (auto &x : bridge) {
		adj2[cc[x.first.first]].push_back(mp(cc[x.first.second], x.second));
		adj2[cc[x.first.second]].push_back(mp(cc[x.first.first], x.second));
	}
	memset(vis, 0, sizeof(vis));
	nii(a, b); a--; b--;
	a = cc[a];
	b = cc[b];
	dfs2(a);
	return 0;
}