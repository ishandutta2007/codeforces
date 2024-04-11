#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, m, in[mxN], sum[mxN], ans[mxN];
ar<int, 3> edge[mxN];
vector<int> adj[mxN];

int get(int i, int u) {
	return u==edge[i][0]?0:1;
}
int other(int i, int u) {
	return u==edge[i][0]?edge[i][1]:edge[i][0];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		int a, b, c; cin >> a >> b >> c, --a, --b;
		edge[i]={a, b, c};
		adj[a].push_back(i);
		adj[b].push_back(i);
		ans[i]=-1;
	}
	for (int i=1; i<n-1; ++i) {
		for (int j: adj[i]) {
			sum[i]+=edge[j][2];
		}
		assert(sum[i]%2==0);
	}
	queue<int> q;
	for (int i: adj[0]) {
		assert(ans[i]==-1);
		int x=other(i, 0);
		in[x]+=edge[i][2];
		ans[i]=get(i, 0);
		if (x!=n-1) {
			//cerr << x << " " << sum[x] << " " << in[x] << "\n";
			assert(sum[x]>=2*in[x]);
			if (2*in[x]==sum[x]) {
				q.push(x);
			}
		}
	}
	while(!q.empty()) {
		int u=q.front(); q.pop();
		assert(2*in[u]==sum[u]);
		for (int i: adj[u]) {
			if (ans[i]!=-1) {
				continue;
			}
			ans[i]=get(i, u);
			int v=other(i, u);
			in[v]+=edge[i][2];
			if (v!=n-1) {
				assert(sum[v]>=2*in[v]);
				if (2*in[v]==sum[v]) {
					q.push(v);
				}
			}
		}
	}
	for (int i=0; i<m; ++i) {
		cout << ans[i] << "\n";
	}
	return 0;
}