#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m, cnt[3000];
bool vis[3000];
vector<int> adj[3000];

ll ans=0;
void solve(int s) {
	memset(cnt, 0, sizeof(cnt));
	for (int u:adj[s])
		for (int v:adj[u])
			if (v!=s)
				cnt[v]++;
	for (int i=0; i<n; ++i)
		ans+=cnt[i]*(cnt[i]-1)/2;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0, u, v; i<m; ++i) {
		cin >> u >> v, u--, v--;
		adj[u].push_back(v);
	}
	for (int i=0; i<n; ++i)
		solve(i);
	cout << ans;
	return 0;
}