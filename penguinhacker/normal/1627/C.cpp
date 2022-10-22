#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n, ans[mxN];
vector<ar<int, 2>> adj[mxN];

void solve() {
	cin >> n;
	for (int i=0; i<n; ++i)
		adj[i].clear();
	for (int i=1; i<n; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back({v, i});
		adj[v].push_back({u, i});
	}
	for (int i=0; i<n; ++i)
		if (adj[i].size()>2) {
			cout << "-1\n";
			return;
		}
	int u=-1;
	for (int i=0; i<n; ++i)
		if (adj[i].size()==1)
			u=i;
	assert(u!=-1);
	int last=-1;
	for (int rep=0; rep<n-1; ++rep) {
		bool ok=0;
		for (ar<int, 2> v : adj[u]) {
			if (v[0]==last)
				continue;
			ans[v[1]]=rep%2?2:3;
			last=u, u=v[0];
			ok=1;
			break;
		}
		assert(ok);
	}
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