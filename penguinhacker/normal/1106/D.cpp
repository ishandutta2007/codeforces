#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>
const int MOD=1e9+7;

int n, m;
vector<int> adj[100000];
bool visited[100000]={0};
set<int> toGo;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0, u, v; i<m; ++i) {
		cin >> u >> v, u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	vector<int> ans;
	toGo.insert(0);
	while (!toGo.empty()) {
		int x = *toGo.begin();
		toGo.erase(toGo.begin());
		visited[x] = 1;
		ans.push_back(x);
		for (int u:adj[x]) {
			if (!visited[u])
				toGo.insert(u);
		}
	}
	for (int i:ans)
		cout << i+1 << ' ';
	return 0;
}