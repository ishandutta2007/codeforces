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

const int B = 1 << 17;
const int N = 100000;
const ll ths = 1000000000000000000;
pair<ll,int> mxtr[B << 1];
int md[B << 1];
ll mdv[B << 1];
void push(int nd) {
	if (!md[nd])return;
	md[nd] = 0;
	ll w = mdv[nd];
	mdv[nd] = 0;
	if (nd >= B)return;
	else {
		int L = nd << 1; int R = L | 1;
		md[L] = md[R] = 1;
		mdv[L] += w;
		mdv[R] += w;
		mxtr[L].first += w;
		mxtr[R].first += w;
	}
}
void upd(int l, int r, ll w, int nd = 1, int ndl = 0, int ndr = B - 1) {
	if (l > ndr || ndl > r)return;
	else if (l <= ndl && ndr <= r) {
		md[nd] = 1;
		mdv[nd] += w;
		mxtr[nd].first += w;
	}
	else {
		push(nd);
		int mid = (ndl + ndr) / 2;
		upd(l, r, w, nd << 1, ndl, mid);
		upd(l, r, w, nd << 1 | 1, mid + 1, ndr);
		mxtr[nd] = min(mxtr[nd << 1], mxtr[nd << 1 | 1]);
	}
}
pair<ll, int> get(int l, int r, int nd = 1, int ndl = 0, int ndr = B - 1) {
	if (l > ndr || ndl > r)return make_pair(ths, 0);
	else if (l <= ndl && ndr <= r) {
		return mxtr[nd];
	}
	else {
		push(nd);
		int mid = (ndl + ndr) / 2;
		return min(get(l, r, nd << 1, ndl, mid), get(l, r, nd << 1 | 1, mid + 1, ndr));
	}
}

ll wtr[B << 1];
void upd2(int l, int r, ll w) {
	l--; r++;
	for (l += B, r += B; l / 2 != r / 2; l /= 2, r /= 2) {
		if (!(l & 1))wtr[l + 1] += w;
		if (r & 1)wtr[r - 1] += w;
	}
}
ll get2(int u) {
	u += B;
	ll ans = 0;
	while (u) {
		ans += wtr[u]; u /= 2;
	}
	return ans;
}

const int LG = 17;

vector<int> girls[N];
vector<int> adj[N];
int hv[N],cnt[N];
int anc[N][LG];
int up[N], down[N], ord[N], clk;
int rnk[N];

void dfs0(int u) {
	cnt[u] = 1;
	hv[u] = -1;
	for (auto &x : adj[u]) {
		if (x == anc[u][0]) continue;
		rnk[x] = rnk[u] + 1;
		anc[x][0] = u;
		dfs0(x);
		cnt[u] += cnt[x];
		if (hv[u] == -1 || cnt[x] > cnt[hv[u]])hv[u] = x;
	}
}
void dfs1(int u, bool tp = true) {
	ord[u] = clk++;
	if (tp) up[u] = u;
	else up[u] = up[anc[u][0]];
	if (hv[u] != -1) {
		dfs1(hv[u], false);
		down[u] = down[hv[u]];
	}
	else down[u] = u;
	for (auto &x : adj[u]) {
		if (x == anc[u][0] || x == hv[u])continue;
		dfs1(x, true);
	}
}


int lca(int u, int v) {
	if (rnk[u] < rnk[v])swap(u, v);
	int d = rnk[u] - rnk[v];
	F(i, LG)if (d&(1 << i)) u = anc[u][i];
	if (u == v)return u;
	for (int i = LG - 1; i >= 0; i--)if (anc[u][i] != anc[v][i])u = anc[u][i], v = anc[v][i];
	return anc[u][0];
}

pair<ll, int> getbest(int u, int v) { //v is anc of u
	pair<ll, int> curbest = make_pair(ths, 0);
	while (up[u] != up[v]) {
		int uu = up[u];
		curbest = min(curbest, get(ord[uu], ord[u]));
		u = anc[uu][0];
		curbest.first += get2(ord[u]);
	}
	return min(curbest, get(ord[v], ord[u]));
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int n, m, Q; nii(n, m); ni(Q);
	F(i, n - 1) {
		int u, v; nii(u, v);
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	anc[0][0] = -1;
	rnk[0] = 0;
	dfs0(0);
	dfs1(0);
	FF(j, LG - 1) {
		F(i, n) {
			int a = anc[i][j - 1];
			if (a == -1)anc[i][j] = -1;
			else anc[i][j] = anc[a][j - 1];
		}
	}
	F(i, m) {
		int c; ni(c);
		c--;
		girls[c].push_back(i);
	}
	F(i, n) {
		sort(girls[i].begin(), girls[i].end(), greater<int>());
	}
	F(i, n) {
		if (girls[i].empty()) mxtr[B + ord[i]] = make_pair(ths, 0);
		else mxtr[B + ord[i]] = make_pair(girls[i].back(), i);
	}
	for (int i = B - 1; i; i--) mxtr[i] = min(mxtr[i << 1], mxtr[i << 1 | 1]);
	F(q, Q) {
		int tp; ni(tp);
		if (tp == 1) {
			int u, v; nii(u, v);
			int k; ni(k);
			u--; v--;
			int L = lca(u, v);
			vector<int> ans;
			F(kk, k) {
				auto best = min(getbest(u, L), getbest(v, L));
				if (best.first >= ths)break;
				else {
					int i = best.second;
					ans.push_back(girls[i].back());
					if (girls[i].size() == 1) {
						girls[i].pop_back();
						upd(ord[i], ord[i], ths);
					}
					else {
						int sz = girls[i].size();
						int dif = girls[i][sz - 2] - girls[i][sz - 1];
						upd(ord[i], ord[i], dif);
						girls[i].pop_back();
					}
				}
			}
			printf("%d ", (int)ans.size());
			for (auto &x : ans) printf("%d ", x + 1);
			puts("");
		}
		else {
			int v, k; nii(v, k);
			v--;
			int dv = down[v];
			upd(ord[v], ord[dv], k);
			upd2(ord[v], ord[dv], k);
		}
	}
}