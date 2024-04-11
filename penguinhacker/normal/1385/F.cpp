#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=200000;
int n, k;
set<int> adj[mxN], leaf[mxN];
struct cmp {
	bool operator()(const int &a, const int &b) const {
		if (leaf[a].size()==leaf[b].size()) return a<b;
		return leaf[a].size()>leaf[b].size();
	}
};

void solve() {
	cin >> n >> k;
	for (int i=0; i<n; ++i) {
		adj[i].clear();
		leaf[i].clear();
	}
	for (int i=1, u, v; i<n; ++i) {
		cin >> u >> v, --u, --v;
		adj[u].insert(v);
		adj[v].insert(u);
	}
	for (int i=0; i<n; ++i)
		if (adj[i].size()==1)
			leaf[*adj[i].begin()].insert(i);

	int ans=0;
	set<int, cmp> active;
	for (int i=0; i<n; ++i)
		active.insert(i);
	while(1) {
		int u=*active.begin();
		if (leaf[u].size()<k) break;
		active.erase(active.begin());
		for (int i=0; i<k; ++i) {
			int v=*leaf[u].begin();
			adj[u].erase(v);
			adj[v].erase(u);
			//active.erase(u);
			active.erase(v);

			leaf[u].erase(v);
			//if (leaf[v].find(u)!=leaf[v].end()) leaf[v].erase(u);

			/*if (adj[u].size()==1) {
				int to=*leaf[u].begin();
				active.erase(to);
				leaf[to].insert(u);
				active.insert(to);
			}*/
			//active.insert(u);
			//active.insert(v);
		}
		++ans;
		active.insert(u);
		if (adj[u].size()==1) {
			int to=*adj[u].begin();
			active.erase(to);
			leaf[to].insert(u);
			active.insert(to);
		}
	}
	cout << ans << '\n';
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

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/