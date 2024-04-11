#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=6000;
int n, a[mxN], ans;
vector<int> adj[mxN], lis;

void dfs(int u, int p) {
	ar<int, 2> rb={-1, -1};
	if (lis.empty()||a[u]>lis.back())
		lis.push_back(a[u]);
	else {
		int pos=upper_bound(lis.begin(), lis.end(), a[u])-lis.begin();
		if (!pos||a[u]>lis[pos-1]) {
			rb={pos, lis[pos]};
			lis[pos]=a[u];
		} else
			rb={0, lis[0]};
	}
	ans=max(ans, (int)lis.size());
	for (int v : adj[u])
		if (v^p)
			dfs(v, u);
	if (rb[0]==-1)
		lis.pop_back();
	else
		lis[rb[0]]=rb[1];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	for (int i=1; i<n; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i=0; i<n; ++i)
		dfs(i, -1);
	cout << ans;
	return 0;
}