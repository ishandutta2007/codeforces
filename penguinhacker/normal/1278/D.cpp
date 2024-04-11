#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, 
    rb_tree_tag, tree_order_statistics_node_update>;

const int mxN=500000;
int n;
bool vis[mxN];
pair<int, int> edge[mxN], ev[2*mxN];
Tree<pair<int, int>> t;
vector<int> adj[mxN];

void dfs(int u=0) {
	vis[u]=1;
	for (int v: adj[u]) if (!vis[v])
		dfs(v);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) {
		int a, b;
		cin >> a >> b, --a, --b;
		edge[i]={a, b};
		ev[a]={i, 0};
		ev[b]={i, 1};
	}
	int cntEdge=0;
	for (int i=0; i<2*n; ++i) {
		int ind=ev[i].first, type=ev[i].second;
		if (type==0) {
			cntEdge+=t.order_of_key({edge[ind].second, 0});
			if (cntEdge>n-1) {
				cout << "NO";
				return 0;
			}
			for (auto it=t.begin(); it!=t.end()&&it->first<edge[ind].second; ++it) {
				int x=it->second;
				adj[ind].push_back(x);
				adj[x].push_back(ind);
			}
			t.insert({edge[ind].second, ind});
		}
		if (type==1) {
			t.erase({edge[ind].second, ind});
		}
	}
	dfs();
	for (int i=0; i<n; ++i)
		if (!vis[i]) {
			cout << "NO";
			return 0;
		}
	cout << "YES";
	return 0;
}