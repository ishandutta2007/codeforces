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

const int N = 300000;
vector<int> adj[N];
const int B = 1 << 19;
ll tr[B << 1];
int modified[B << 1];
ll modval[B << 1];
int ord[N], ordr[N], clk, par[N];
ll dp[N];
int m;
tuple<int, int, int> qs[N];
vector<int> del[N];

void dfs(int u) {
	ord[u] = clk++;
	for (auto &x : adj[u]) {
		if (x == par[u]) continue;
		par[x] = u;
		dfs(x);
	}
	ordr[u] = clk;
}

void addToNode(int nd, ll v) {
	if (tr[nd] == infl) return;
	modified[nd] = 1;
	modval[nd] += v;
	tr[nd] += v;
}
void push(int nd) {
	if (nd >= B)return;
	addToNode(nd << 1, modval[nd]);
	addToNode(nd << 1 | 1, modval[nd]);
	modified[nd] = 0;
	modval[nd] = 0;
}
void upds(int nd) {
	if (!nd)return;
	upds(nd / 2);
	push(nd);
}
void updinf(int i) {
	i += B;
	upds(i);
	tr[i] = infl;
	for (i /= 2; i; i /= 2) {
		tr[i] = min(tr[i << 1], tr[i << 1 | 1]);
	}
}
void upd(int l, int r, ll v, int nd = 1, int ndl = 0, int ndr = B - 1) {
	if (l > r || l > ndr || ndl > r)return;
	else if (l <= ndl && ndr <= r) {
		addToNode(nd, v);
	}
	else {
		push(nd);
		int mid = (ndl + ndr) / 2;
		upd(l, r, v, nd << 1, ndl, mid);
		upd(l, r, v, nd << 1 | 1, mid + 1, ndr);
		tr[nd] = min(tr[nd << 1], tr[nd << 1 | 1]);
	}
}
ll get(int l, int r, int nd = 1, int ndl = 0, int ndr = B - 1) {
	if (l > r || l > ndr || ndl > r) return infl;
	else if (l <= ndl && ndr <= r) {
		return tr[nd];
	}
	else {
		push(nd);
		int mid = (ndl + ndr) / 2;
		return min(get(l, r, nd << 1, ndl, mid), get(l, r, nd << 1 | 1, mid + 1, ndr));
	}
}

void dfs2(int u) {
	ll sum = 0;
	for (auto &x : adj[u]) {
		if (x == par[u]) continue;
		dfs2(x);
		int l = lower_bound(qs, qs + m, mtp(ord[x], -1, -1)) - qs;
		int r = lower_bound(qs, qs + m, mtp(ordr[x], -1, -1)) - qs - 1;
		dp[x] = get(l, r);
		if (dp[x] == infl) {
			puts("-1"); exit(0);
		}
		sum += dp[x];
	}
	for (auto &x : adj[u]) {
		if (x == par[u]) continue;
		int l = lower_bound(qs, qs + m, mtp(ord[x], -1, -1)) - qs;
		int r = lower_bound(qs, qs + m, mtp(ordr[x], -1, -1)) - qs - 1;
		upd(l, r, sum - dp[x]);
	}
	int l = lower_bound(qs, qs + m, mtp(ord[u], -1, -1)) - qs;
	int r = lower_bound(qs, qs + m, mtp(ord[u] + 1, -1, -1)) - qs - 1;
	upd(l, r, sum);
	for (auto &i : del[u]) {
		updinf(i);
	}
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int n; nii(n, m);
	F(i, n - 1) {
		int u, v; nii(u, v);
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	par[0] = -1;
	dfs(0);
	F(i, m) {
		int u, v, c; nii(u, v); ni(c); u--; v--;
		qs[i] = mtp(ord[u], v, c);
	}
	sort(qs, qs + m);
	F(i, m) {
		tr[B + i] = get<2>(qs[i]);
		del[get<1>(qs[i])].push_back(i);
	}
	for (int i = B - 1; i; i--) tr[i] = min(tr[i << 1], tr[i << 1 | 1]);
	dfs2(0);
	ll ans = 0;
	for (auto &x : adj[0]) {
		ans += dp[x];
	}
	printf("%I64d\n", ans);
	return 0;
}