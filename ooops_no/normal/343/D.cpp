#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<iostream>
#include<string>
#include<set>
#include<queue>
#include<random>
//#include<unordered_set>

using namespace std;

/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> st;*/

#pragma GCC optimize("Ofast")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")

#define pb push_back
#define ld long double

mt19937 rnd(51);

const int N = 2e6 + 10;
vector<int> g[N];
vector<int> f(N), l(N);
vector<int> ans;
vector<int> t(4 * N), add(4 * N, -1);
vector<bool> used(N);
vector<int> par(N);

void push(int v){
    if (add[v] != -1){
        add[v * 2] = add[v];
        add[v * 2 + 1] = add[v];
        t[v] = add[v];
        add[v] = -1;
    }
}

void update(int v, int tl, int tr, int l, int r, int val){
    push(v);
    if (l > r){
        return;
    }
    if (tl == l && tr == r){
        add[v] = val;
        push(v);
        return;
    }
    int tm = (tl + tr) / 2;
    update(2 * v, tl, tm, l, min(r, tm), val), update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, val);
    t[v] = min(t[v * 2 + 1], t[v * 2]);
}

int mn(int v, int tl, int tr, int l, int r){
    push(v);
    if (l > r){
        return 1e9;
    }
    if (tl == l && tr == r){
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return min(mn(2 * v, tl, tm, l, min(r, tm)), mn(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}

void dfs(int v) {
	used[v] = 1;
	ans.pb(v);
	f[v] = ans.size() - 1;
	for (auto to : g[v]) {
		if (!used[to]) {
			par[to] = v;
			dfs(to);
			ans.pb(v);
		}
	}
	l[v] = ans.size() - 1;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(1);
	int q;
	cin >> q;
	while (q--) {
		int k, v;
		cin >> k >> v;
		if (k == 1) {
			if (mn(1, 0, ans.size() - 1, f[v], l[v]) == 0) {
				if (v != 1) {
					int u = par[v];
					update(1, 0, ans.size() - 1, f[u], f[u], 0);
				}
			}
			update(1, 0, ans.size() - 1, f[v], l[v], 1);
		}
		else if (k == 2) {
			update(1, 0, ans.size() - 1, f[v], f[v], 0);
		}
		else {
			cout << mn(1, 0, ans.size() - 1, f[v], l[v]) << endl;
		}
	}
	return 0;
}