#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<class T> using Tree=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int mxN=1e6;
int n, q, p[mxN], a[mxN], cnt[mxN], ans[mxN];
vector<int> adj[mxN];
vector<ar<int, 3>> qry[mxN];
Tree<ar<int, 2>> t;

void dfs(int u=0) {
	if (++cnt[a[u]]==1) {
		t.insert({1, a[u]});
	} else {
		t.erase({cnt[a[u]]-1, a[u]});
		t.insert({cnt[a[u]], a[u]});
	}
	for (auto [l, k, i] : qry[u]) {
		int pos=t.order_of_key({l, -1})+k-1;
		ans[i]=pos>=t.size()?-1:(*t.find_by_order(pos))[1]+1;
	}
	for (int v : adj[u])
		dfs(v);
	if (--cnt[a[u]]==0) {
		t.erase({1, a[u]});
	} else {
		t.erase({cnt[a[u]]+1, a[u]});
		t.insert({cnt[a[u]], a[u]});
	}
}

void solve() {
	cin >> n >> q;
	for (int i=0; i<n; ++i) {
		cin >> a[i], --a[i];
		adj[i].clear();
		qry[i].clear();
	}
	for (int i=1; i<n; ++i) {
		cin >> p[i], --p[i];
		adj[p[i]].push_back(i);
	}
	for (int i=0; i<q; ++i) {
		int v, l, k;
		cin >> v >> l >> k, --v;
		qry[v].push_back({l, k, i});
	}
	dfs();
	for (int i=0; i<q; ++i)
		cout << ans[i] << " ";
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}