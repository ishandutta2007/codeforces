#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, ans[mxN];
vector<ar<int, 3>> adj[mxN];
vector<ll> bs;

void dfs(int u=0, ll as=0) {
	if (u)
		ans[u]=upper_bound(bs.begin(), bs.end(), as)-bs.begin()-1;
	for (auto [v, a, b] : adj[u]) {
		bs.push_back(bs.back()+b);
		dfs(v, as+a);
		bs.pop_back();
	}
}

void solve() {
	cin >> n;
	for (int i=0; i<n; ++i)
		adj[i].clear();
	for (int i=1; i<n; ++i) {
		int p, a, b;
		cin >> p >> a >> b, --p;
		adj[p].push_back({i, a, b});
	}
	bs={0};
	dfs();
	for (int i=1; i<n; ++i)
		cout << ans[i] << " ";
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