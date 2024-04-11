#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n;
vector<int> adj[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=1, u, v; i<n; ++i) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	set<int> left;
	for (int i=1; i<=n; ++i)
		left.insert(i);
	while(1) {
		if (left.size()==1) {
			cout << "! " << *left.begin() << '\n' << flush;
			break;
		}
		int u=-1, v=-1;
		for (const int &i : left) {
			if (adj[i].size()==1) {
				if (u==-1) {
					u=i;
				}
				else {
					assert(v==-1);
					v=i;
					break;
				}
			}
		}
		adj[adj[u][0]].erase(find(adj[adj[u][0]].begin(), adj[adj[u][0]].end(), u));
		adj[adj[v][0]].erase(find(adj[adj[v][0]].begin(), adj[adj[v][0]].end(), v));
		left.erase(u);
		left.erase(v);
		cout << "? " << u << ' ' << v << '\n' << flush;
		int lca; cin >> lca;
		if (lca==u||lca==v) {
			cout << "! " << lca << '\n' << flush;
			break;
		}
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/