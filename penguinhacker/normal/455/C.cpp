#include<bits/stdc++.h>
using namespace std;

const int mxN=3e5;
int n, m, q;
bool vis[mxN];
set<int> adj[mxN];

int p[mxN], ans[mxN];
pair<int, int> dfs(int u, int source) {
	pair<int, int> ret={0, 0};
	vector<int> dep={0, 0};
	p[u]=source;
	vis[u]=1;
	for (int v: adj[u]) if (!vis[v]) {
		pair<int, int> cur=dfs(v, source);
		ret.first=max(ret.first, cur.first);
		dep.push_back(cur.second+1);
		ret.second=max(ret.second, cur.second+1);
	}
	sort(dep.rbegin(), dep.rend());
	ret.first=max(ret.first, dep[0]+dep[1]);
	return ret;
}

int find(int i) {return i==p[i]?i:p[i]=find(p[i]);}
void merge(int a, int b) {
	a=find(a), b=find(b);
	if (a==b) return;
	if (ans[a]<ans[b]) swap(a, b);
	p[b]=a;
	ans[a]=max(ans[a], (ans[a]+1)/2+(ans[b]+1)/2+1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> q;
	for (int i=0; i<m; ++i) {
		int a, b; cin >> a >> b, --a, --b;
		adj[a].insert(b);
		adj[b].insert(a);
	}
	for (int i=0; i<n; ++i) if (!vis[i]) {
		ans[i]=dfs(i, i).first;
	}

	for (int i=0; i<q; ++i) {
		int type; cin >> type;
		if (type==1) {
			int a; cin >> a, --a;
			cout << ans[find(a)] << "\n";
		}
		if (type==2) {
			int a, b; cin >> a >> b, --a, --b;
			merge(a, b);
		}
	}
}