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

struct rat {
	long long a, b;
	rat(ll _a = 0, ll _b = 1) {
		if (_b < 0)_a = -_a, _b = -_b;
		a = _a; b = _b;
	}
	bool operator<(const rat& ot) const{
		return a*ot.b < ot.a*b;
	}
	rat operator-() const{
		return rat(-a, b);
	}
	bool operator==(const rat& ot) const{
		return a*ot.b == ot.a*b;
	}
};

const int N = 100000;
const int LG = 17;
vector<int> adj[N];
int rnk[N], up[N], anc[N][LG], down[N], hvc[N], cnt[N];

void dfs0(int u) {
	cnt[u] = 1; hvc[u] = -1;
	for (auto &x : adj[u]) {
		if (x == anc[u][0]) continue;
		rnk[x] = rnk[u] + 1;
		anc[x][0] = u;
		dfs0(x);
		cnt[u] += cnt[x];
		if (hvc[u] == -1 || cnt[x]>cnt[hvc[u]]) hvc[u] = x;
	}
}

void dfs1(int u, bool hv) {
	if (hv) up[u] = u;
	else up[u] = up[anc[u][0]];
	if (hvc[u] == -1) {
		down[u] = u;
	}
	else {
		dfs1(hvc[u], false);
		down[u] = down[hvc[u]];
	}
	for (auto &x : adj[u]) {
		if (x == anc[u][0] || x == hvc[u]) continue;
		dfs1(x, true);
	}
}

int lca(int u, int v) {
	if (rnk[u] < rnk[v])swap(u, v);
	int d = rnk[u] - rnk[v];
	F(i, LG)if (d&(1 << i))u = anc[u][i];
	if (u == v)return u;
	for (int i = LG - 1; i >= 0; i--)if (anc[u][i] != anc[v][i])u = anc[u][i], v = anc[v][i];
	return anc[u][0];
}

struct Query {
	int X, Y; int s, c;
	Query() {}
	Query(int a, int b, int x, int y) :X(a), Y(b), s(x), c(y) {}
};
vector<Query> qs[N];

double ans = 1e12;

int chk[N];

void solve(int u) {
	priority_queue<tuple<rat, int, int, int> > pq; // 3:meet, 2:insert, 1:delete
	auto cmp = [&](int i, int j)->bool {
		if (rat(qs[u][i].X, qs[u][i].c) < rat(qs[u][j].X, qs[u][j].c)) {
			return rat((long long)qs[u][i].c*qs[u][j].X, qs[u][j].c) < qs[u][j].s - qs[u][i].s + qs[u][i].X;
		}
		else {
			return rat(qs[u][i].s - qs[u][j].s + qs[u][j].X, 1) < rat((ll)qs[u][i].X*qs[u][j].c, qs[u][i].c);
		}
	};
	set<int, decltype(cmp)> st(cmp);
	int sz = qs[u].size();
	F(i, sz) {
		pq.push(mtp(rat(-qs[u][i].X, qs[u][i].c), 2, i, 0));
		pq.push(mtp(rat(-qs[u][i].Y, qs[u][i].c), 1, i, 0));
		chk[i] = 0;
	}
	while (!pq.empty()) {
		auto T = pq.top(); pq.pop();
		int tp = get<1>(T);
		rat time = -get<0>(T);
		if (tp == 1) {
			int i = get<2>(T);
			chk[i] = 0;
			auto it = st.find(i);
			it = st.erase(it);
			auto it2 = it;
			if (it != st.begin()) {
				it2--;
				if (it != st.end()) {
					int i = *it;
					int j = *it2;
					if (qs[u][i].c != qs[u][j].c) {
						rat ntime = rat(qs[u][i].X - qs[u][j].X - qs[u][i].s + qs[u][j].s, qs[u][i].c - qs[u][j].c);
						if (!(ntime < time)) {
							pq.push(mtp(-ntime, 3, i, j));
						}
					}
				}
			}
		}
		else if (tp == 2) {
			int i = get<2>(T);
			chk[i] = 1;
			auto P = st.insert(i);
			if (!P.second) {
				ans = min(ans, (double)time.a / time.b);
				return;
			}
			auto it2 = P.first;
			auto it = it2;
			if (it != st.begin()) {
				it2--;
				int j = *it2;
				if (qs[u][i].c != qs[u][j].c) {
					rat ntime = rat(qs[u][i].X - qs[u][j].X - qs[u][i].s + qs[u][j].s, qs[u][i].c - qs[u][j].c);
					if (!(ntime < time)) {
						pq.push(mtp(-ntime, 3, i, j));
					}
				}
			}
			it2 = it;
			it2++;
			if (it2 != st.end()) {
				int j = *it2;
				if (qs[u][i].c != qs[u][j].c) {
					rat ntime = rat(qs[u][i].X - qs[u][j].X - qs[u][i].s + qs[u][j].s, qs[u][i].c - qs[u][j].c);
					if (!(ntime < time)) {
						pq.push(mtp(-ntime, 3, i, j));
					}
				}
			}
		}
		else {
			int u = get<2>(T);
			int v = get<3>(T);
			if (!chk[u] || !chk[v]) continue;
			ans = min(ans, (double)time.a / time.b);
			return;
		}
	}
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int n, m; nii(n, m);
	F(i, n - 1) {
		int a, b; nii(a, b);
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	anc[0][0] = -1;
	dfs0(0);
	dfs1(0, true);
	FF(j, LG - 1)F(i, n) {
		int a = anc[i][j - 1];
		if (a == -1)anc[i][j] = -1;
		else anc[i][j] = anc[a][j - 1];
	}
	F(i, m) {
		int t, c, u, v;
		nii(t, c); nii(u, v);
		u--; v--;
		bool good = false;
		int L = lca(u, v);
		int ou = u;
		while (up[u] != up[L]) {
			int uu = up[u];
			qs[uu].emplace_back(-(c*t + rnk[ou] - rnk[u]), -(c*t + rnk[ou] - rnk[uu] + 1), rnk[u], -c);
			u = anc[uu][0];
		}
		if (u != L) {
			qs[up[u]].emplace_back(-(c*t + rnk[ou] - rnk[u]), -(c*t + rnk[ou] - rnk[L]), rnk[u], -c);
			good = true;
		}
		int d = rnk[ou] - rnk[L];
		while (up[v] != up[L]) {
			int vv = up[v];
			qs[vv].emplace_back(t*c + rnk[vv] - 1 - rnk[L] + d, t*c + rnk[v] - rnk[L] + d, rnk[vv] - 1, c);
			v = anc[vv][0];
		}
		if (v != L) {
			good = true;
			qs[up[v]].emplace_back(t*c + d, t*c + rnk[v] - rnk[L] + d, rnk[L], c);
		}
		if (!good) {
			qs[up[L]].emplace_back(t*c + d, t*c + d, rnk[L], c);
		}
	}
	F(i, n) {
		if (up[i] == i) {
			solve(i);
		}
	}
	if (ans > 1e11) {
		puts("-1");
	}
	else printf("%.15f\n", ans);
	return 0;
}