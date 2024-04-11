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

const int N = 100010;
vector<int> adj[N];

int m = 0;
map<ll, int> tpid;
ll cval[N * 3];
int tp[N];
int ans[N];

ll rand64() {
	ll res = 0;
	F(i, 16) {
		int x = rand() & 0xff;
		res = (res << 4) + x;
	}
	return res;
}

int chsettoid(ll x) {
	auto it = tpid.find(x);
	if (it == tpid.end()) {
		tpid[x] = m;
		cval[m] = rand64();
		return m++;
	}
	else return it->second;
}

void dfs(int u, int p = -1) {
	ll ch = 0;
	for (auto &x : adj[u]) {
		if (x == p)continue;
		dfs(x, u);
		ch += cval[tp[x]];
	}
	tp[u] = chsettoid(ch);
}

int cnt[N * 3];
int total = 0;
void add(int i) {
	cnt[i]++;
	if (cnt[i] == 1)total++;
}
void erase(int i) {
	cnt[i]--;
	if (!cnt[i])total--;
}

void dfs2(int u, int ptp = -1, int p = -1) {
	erase(tp[u]);
	ans[u] = total + 1;
	ll ch = 0;
	for (auto &x : adj[u]) {
		if (x == p)continue;
		ch += cval[tp[x]];
	}
	if (ptp >= 0)ch += cval[ptp];
	for (auto &x : adj[u]) {
		if (x == p) continue;
		ch -= cval[tp[x]];
		int id = chsettoid(ch);
		add(id);
		dfs2(x, id, u);
		erase(id);
		ch += cval[tp[x]];
	}
	add(tp[u]);
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
	dfs(0);
	F(i, n)add(tp[i]);
	dfs2(0);
	printf("%d\n", max_element(ans, ans + n) - ans + 1);
	return 0;
}