#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a, b, p[100000], ans[100000];
set<pair<int, int>> exists;

vector<int> adj[100000];
bool vis[100000];
vector<int> comp;
bool ok(int x) { //v is a component
	set<int> s;
	for (int i: comp)
		s.insert(p[i]);
	for (int i: comp)
		if (s.find(x-p[i])==s.end())
			return 0;
	return 1;
}

void dfs(int u) {
	vis[u]=1;
	comp.push_back(u);
	for (int v: adj[u]) if (!vis[v])
		dfs(v);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> a >> b;
	for (int i=0; i<n; ++i) {
		cin >> p[i];
		exists.insert({p[i], i});
	}
	//make adj list
	for (int i=0; i<n; ++i) {
		auto it=exists.lower_bound({a-p[i], -1});
		if (it!=exists.end()&&it->first==a-p[i])
			adj[i].push_back(it->second);
		it=exists.lower_bound({b-p[i], -1});
		if (it!=exists.end()&&it->first==b-p[i])
			adj[i].push_back(it->second);
	}

	for (int i=0; i<n; ++i) if (!vis[i]) {
		dfs(i);
		if (ok(a));
		else if (ok(b)) {
			for (int j: comp)
				ans[j]=1;
		}
		else {
			cout << "NO";
			return 0;
		}
		comp.clear();
	}
	cout << "YES\n";
	for (int i=0; i<n; ++i)
		cout << ans[i] << ' ';
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/