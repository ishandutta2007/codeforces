#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, m, dp[mxN];
vector<int> adj[mxN];

void solve() {
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		adj[i].clear();
	for (int i=0; i<m; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[v].push_back(u);
	}
	vector<int> ans;
	for (int i=0; i<n; ++i) {
		dp[i]=0;
		for (int j : adj[i])
			dp[i]=max(dp[i], dp[j]+1);
		if (dp[i]==2) {
			ans.push_back(i);
			dp[i]=-1;
		}
	}
	assert(ans.size()<=4*n/7);
	cout << ans.size() << "\n";
	for (int i : ans)
		cout << i+1 << " ";
	cout << "\n";
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