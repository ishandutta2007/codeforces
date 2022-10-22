#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=200000;
int n;
vector<pair<int, int>> adj[mxN];
ll up[mxN][2], down[mxN][2];
ll ans=0;

void dfs(int u=0, int p=-1) {
	vector<ll> cup[2];
	vector<ll> cdown[2];
	for (auto edge: adj[u]) if (edge.first!=p) {
		int v=edge.first, w=edge.second;
		dfs(v, u);
		if (w==0) {
			cup[0].push_back(up[v][0]+1);
			cup[1].push_back(0);
			cdown[0].push_back(down[v][0]+down[v][1]+1);
			cdown[1].push_back(0);
		}
		if (w==1) {
			cup[0].push_back(0);
			cup[1].push_back(up[v][0]+up[v][1]+1);
			cdown[0].push_back(0);
			cdown[1].push_back(down[v][1]+1);
		}
		up[u][0]+=cup[0].back();
		up[u][1]+=cup[1].back();
		down[u][0]+=cdown[0].back();
		down[u][1]+=cdown[1].back();
	}
	ans+=up[u][0]+up[u][1]+down[u][0]+down[u][1];
	for (int i=0; i<cup[0].size(); ++i) {
		ans+=cup[0][i]*(down[u][0]+down[u][1]-cdown[0][i]-cdown[1][i]);
		ans+=cup[1][i]*(down[u][1]-cdown[1][i]);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=1; i<n; ++i) {
		int a, b, w; cin >> a >> b >> w, --a, --b;
		adj[a].emplace_back(b, w);
		adj[b].emplace_back(a, w);
	}
	dfs();
	cout << ans;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/