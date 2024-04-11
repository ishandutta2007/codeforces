#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define ull unsigned ll

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mxN=1e6;
int n, m;
ull val[mxN], adj[mxN];
ll ans;

void solve() {
	unordered_map<ull, int> mp;
	for (int i=0; i<n; ++i)
		ans+=mp[adj[i]]++;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		val[i]=rng();
	for (int i=0; i<m; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u]+=val[v];
		adj[v]+=val[u];
	}
	solve();
	for (int i=0; i<n; ++i)
		adj[i]+=val[i];
	solve();
	cout << ans;
	return 0;
}