#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=400, M=998244353;
int n, m, d[mxN][mxN], ans[mxN][mxN];
vector<int> adj[mxN];
bool on_path[mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	memset(d, -1, sizeof(d));
	for (int i=0; i<n; ++i) {
		d[i][i]=0;
		for (queue<int> q({i}); q.size(); q.pop()) {
			int u=q.front();
			for (int v : adj[u])
				if (d[i][v]==-1) {
					d[i][v]=d[i][u]+1;
					q.push(v);
				}
		}
	}
	for (int s=0; s<n; ++s) {
		for (int t=s; t<n; ++t) {
			memset(on_path, 0, sizeof(on_path));
			int cnt=0;
			for (int i=0; i<n; ++i)
				if (d[s][i]+d[i][t]==d[s][t]) {
					on_path[i]=1;
					++cnt;
				}
			if (cnt!=d[s][t]+1) {
				ans[s][t]=ans[t][s]=0;
				continue;
			}
			ll cur=1;
			for (int i=0; i<n; ++i) {
				if (on_path[i])
					continue;
				int t2=0;
				for (int j : adj[i])
					t2+=d[s][i]==d[s][j]+1&&d[t][i]==d[t][j]+1;
				cur=cur*t2%M;
			}
			ans[s][t]=ans[t][s]=cur;
		}
	}
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j)
			cout << ans[i][j] << " ";
		cout << "\n";
	}
	return 0;
}