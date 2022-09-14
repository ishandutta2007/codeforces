#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (ll i = 0; i < (n); i++)
 
typedef long long ll;
typedef long double ld;
using namespace std;

struct pt {
	int u, v, w = 0;
	pt() : u(0), v(0) {};
	pt(int x) : u(x), v(x), w(x) {}
	pt(int u, int v, int w) : u(u), v(v), w(w) {}

	void p() {
		cout << u << ' ' << v << '\n';
	}
};

const int L = 18, N = 1 << L;
int p[N], rp[N], h[N], par[N], tin[N], tout[N];
int up[L][N];
pt tr[N * 2];
vector<int> g[N];
int ct, ans;

bool isp(int u, int v) {
	return tin[u] <= tin[v] && tout[v] <= tout[u];
}

int lca(int u, int v) {
	if (h[u] < h[v])
		swap(u, v);
	for (int i = L - 1; i >= 0; i--)
		if (h[up[i][u]] >= h[v])
			u = up[i][u];
	if (u == v)
		return u;
	for (int i = L - 1; i >= 0; i--)
		if (up[i][u] != up[i][v]) {
			u = up[i][u];
			v = up[i][v];
		}
	return up[0][v];
}

bool check(pt &p, int w, int v) {
	return isp(w, v) && (isp(v, p.u) || isp(v, p.v));
}

pt merge(pt p1, pt p2) {
	if (p1.u == -1 || p2.u == -1)
		return {-1};
	int w = lca(p1.w, p2.w);
	int v1 = p1.u, v2 = -1;
	for (int i : {p1.v, p2.u, p2.v}) {
		if (isp(i, v1) || v2 != -1 && isp(i, v2));
		else if (isp(v1, i))
			v1 = i;
		else if (v2 != -1 && isp(v2, i))
			v2 = i;
		else if (v2 == -1)
			v2 = i;
		else
			return {-1};
	}
	if (v2 == -1)
		return {v1, w, w};
	if (lca(v1, v2) == w)
		return {v1, v2, w};
	return {-1};
}

void dfs(int v) {
	tin[v] = ct++;
	for (int u : g[v]) {
		h[u] = h[v] + 1;
		dfs(u);
	}
	tout[v] = ct;
}

void upd(int v) {
	tr[N + v] = {rp[v]};
	for (int i = (N + v) / 2; i; i /= 2)
		tr[i] = merge(tr[i * 2], tr[i * 2 + 1]);
}

pt getmex(pt cs, int v=1, int l=0, int r=N) {
	pt ns = (cs.u == -2 ? tr[v] : merge(cs, tr[v]));
	if (ns.u != -1) {
		ans = r;
		return ns;
	}
	if (r - l == 1)
		return {-1};
	pt ls = getmex(cs, v * 2, l, (l + r) / 2);
	if (ls.u == -1)
		return ls;
	return getmex(ls, v * 2 + 1, (l + r) / 2, r);
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	rep(i, n) {
		cin >> p[i];
		rp[p[i]] = i;
	}
	for (int i = 1; i < n; i++) {
		cin >> par[i];
		par[i]--;
		up[0][i] = par[i];
		g[par[i]].push_back(i);
	}
	rep(i, L - 1)
		rep(j, n)
			up[i + 1][j] = up[i][up[i][j]];
	dfs(0);
	rep(i, N)
		tr[N + i] = {i < n ? rp[i] : -1};
	for (int i = N - 1; i >= 0; i--)
		tr[i] = merge(tr[i * 2], tr[i * 2 + 1]);
	int q, t, u, v;
	cin >> q;
	rep(i, q) {
		cin >> t;
		if (t == 1) {
			cin >> u >> v;
			u--; v--;
			swap(p[u], p[v]);
			rp[p[u]] = u;
			rp[p[v]] = v;
			upd(p[u]);
			upd(p[v]);
		}
		else {
			ans = 0;
			getmex({-2});
			cout << ans << '\n';
		}
	}

}