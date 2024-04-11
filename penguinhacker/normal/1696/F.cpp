#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

#define debug(x) cerr << "[" << #x << "] = [" << x << "]\n"

template<class A, unsigned int sz> ostream& operator<< (ostream& out, ar<A, sz> a) {
	out << '[';
	for (int i = 0; i < sz; ++i) {
		if (i > 0) out << ", ";
		out << a[i];
	}
	return out << ']';
}

template<class T> ostream& operator<< (ostream& out, vector<T> v) {
	out << '[';
	for (int i = 0; i < v.size(); ++i) {
		if (i > 0) {
			out << ", ";
		}
		out << v[i];
	}
	return out << ']';
}

const int mxN=100;
int n, who[mxN][mxN];
bool d[mxN][mxN][mxN], vis[mxN];
vector<vector<int>> cmp[mxN];
vector<int> cur, adj[mxN], by_distance[mxN];
vector<ar<int, 2>> edges;

void dfs(int i, int u) {
	vis[u]=1;
	cur.push_back(u);
	for (int v=0; v<n; ++v)
		if (d[i][u][v]&&!vis[v])
			dfs(i, v);
}

void gen(int u, int p) {
	vector<int> children=cmp[u][who[u][p]];
	for (int v : children) {
		if (!vis[v]) {
			vis[v]=1;
			edges.push_back({u, v});
			gen(v, u);
		}
	}
}

void dfs2(int u, int p=-1, int d=0) {
	by_distance[d].push_back(u);
	for (int v : adj[u])
		if (v!=p)
			dfs2(v, u, d+1);
}

bool check() {
	//debug(edges);
	/*for (auto [u, v] : edges) {
		cout << "[" << u << ", " << v << "]\n";
	}
	cout << endl;*/
	if (edges.size()!=n-1)
		return 0;
	for (int i=0; i<n; ++i)
		adj[i].clear();
	for (auto [u, v] : edges) {
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i=0; i<n; ++i) {
		for (int j=0; by_distance[j].size(); ++j)
			by_distance[j].clear();
		dfs2(i);
		vector<vector<int>> me;
		for (int j=0; by_distance[j].size(); ++j) {
			sort(by_distance[j].begin(), by_distance[j].end());
			me.push_back(by_distance[j]);
		}
		sort(me.begin(), me.end());
		if (cmp[i]!=me)
			return 0;
	}
	cout << "Yes\n";
	for (auto [u, v] : edges)
		cout << u+1 << " " << v+1 << "\n";
	return 1;
}

void solve() {
	cin >> n;
	for (int i=0; i<n; ++i)
		cmp[i].clear();
	for (int i=0; i<n; ++i)
		for (int j=i+1; j<n; ++j) {
			string s;
			cin >> s;
			for (int k=0; k<n; ++k)
				d[k][i][j]=d[k][j][i]=s[k]=='1';
		}
	for (int i=0; i<n; ++i) {
		memset(vis, 0, sizeof(vis));
		for (int j=0; j<n; ++j)
			if (!vis[j]) {
				cur.clear();
				dfs(i, j);
				for (int a=0; a<cur.size(); ++a)
					for (int b=a+1; b<cur.size(); ++b) {
						if (!d[i][cur[a]][cur[b]]) {
							cout << "No\n";
							//cout << i << endl;
							return;
						}
					}
				for (int k : cur)
					who[i][k]=cmp[i].size();
				sort(cur.begin(), cur.end());
				cmp[i].push_back(cur);
			}
		sort(cmp[i].begin(), cmp[i].end());
	}
	for (vector<int> children0 : cmp[0]) {
		memset(vis, 0, sizeof(vis));
		edges.clear();
		vis[0]=1;
		for (int i : children0) {
			vis[i]=1;
			edges.push_back({0, i});
		}
		for (int i : children0)
			gen(i, 0);
		if (check())
			return;
	}
	cout << "No\n";
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