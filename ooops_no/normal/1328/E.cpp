#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<iostream>
#include<string>
#include<set>
#include<queue>
#include<random>

using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")

#define pb push_back
#define ld long double
#define ll long long

mt19937 rnd(51);

const int N = 2e5 + 10;
vector<int> g[N];
vector<bool> used(N);
vector<int> d(N);
vector<int> par(N);
vector<int> ans;
vector<int> ind(N);
vector<int> t;

void dfs(int v) {
	ans.pb(v);
	ind[v] = ans.size() - 1;
	used[v] = 1;
	for (auto to : g[v]) {
		if (!used[to]) {
			par[to] = v;
			d[to] = d[v] + 1;
			dfs(to);
			ans.pb(v);
		}
	}
}

void build(int v, int l, int r) {
	if (l == r) {
		t[v] = d[ans[l]];
		return;
	}
	int m = (r + l) / 2;
	build(2 * v, l, m), build(2 * v + 1, m + 1, r);
	t[v] = min(t[v * 2], t[v * 2 + 1]);
}

int mn(int v, int tl, int tr, int l, int r) {
	if (tl == l && tr == r) {
		return t[v];
	}
	if (l > r) {
		return 1e9;
	}
	int tm = (tl + tr) / 2;
	return min(mn(2 * v, tl, tm, l, min(r, tm)), mn(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(1);
	t.resize(ans.size() * 4);
	build(1, 0, ans.size() - 1);
	for (int i = 0; i < m; i++) {
		map<int, int> was;
		int p;
		cin >> p;
		vector<int> v;
		int j = 0;
		for (int i = 0; i < p; i++) {
			int u;
			cin >> u;
			v.pb(u);
			if (d[u] >= d[j]) {
				j = u;
			}
		}
		bool x = 0;
		for (auto to : v) {
			int p = min(ind[j], ind[to]), p1 = max(ind[j], ind[to]);
			int k = mn(1, 0, ans.size() - 1, p, p1);
			if (k != d[to] && k + 1 != d[to]) {
				x = 1;
			}
		}
		if (x) {
			cout << "NO\n";
		}
		else {
			cout << "YES\n";
		}
	}
	return 0;
}