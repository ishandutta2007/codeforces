#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array

int n, dp[200000];
vector<int> adj[200000];
 
bool dfs(int u, int p, int k) {
	if (adj[u].size()==1&&p!=-1) {
		dp[u]=0;
		return 1;
	}
	vector<int> c;
	for (int v : adj[u])
		if (v^p) {
			if (!dfs(v, u, k))
				return 0;
			c.push_back(dp[v]+1);
		}
	if (c.size()==1) {
		dp[u]=c[0];
		return dp[u]<=k;
	}
	sort(c.begin(), c.end());
	if (c.back()>k||c.end()[-2]==k)
		return 0;
	dp[u]=c.back()<k?c[0]:c.back();
	return 1;
}
 
void solve() {
	cin >> n;
	for (int i=0; i<n; ++i)
		adj[i].clear();
	for (int i=1; i<n; ++i) {
		int a, b;
		cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int l=1, r=n-1;
	while(l<r) {
		int mid=(l+r)/2;
		dfs(0, -1, mid)?r=mid:l=mid+1;
	}
	cout << l << "\n";
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) solve();
	return 0;
}