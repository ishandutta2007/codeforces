#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, a[mxN], b[mxN], cnt[mxN];
vector<ar<int, 3>> adj[mxN];
bool vis[mxN];
vector<int> oc[2];

void dfs(int u, int p=-1) {
	vis[u]=1;
	for (ar<int, 3> v : adj[u])
		if (v[1]^p) {
			if (!vis[v[0]])
				dfs(v[0], v[1]);
			oc[v[2]].push_back(v[1]);
			break;
		}
}

void solve() {
	cin >> n;
	for (int i=0; i<n; ++i) {
		cnt[i]=vis[i]=0;
		adj[i].clear();
	}
	for (int i=0; i<n; ++i)
		cin >> a[i], ++cnt[--a[i]];
	for (int i=0; i<n; ++i)
		cin >> b[i], ++cnt[--b[i]];
	for (int i=0; i<n; ++i)
		if (cnt[i]!=2) {
			cout << "-1\n";
			return;
		}
	for (int i=0; i<n; ++i) {
		adj[a[i]].push_back({b[i], i, 0});
		adj[b[i]].push_back({a[i], i, 1});
	}
	vector<int> ans;
	for (int i=0; i<n; ++i) {
		if (vis[i])
			continue;
		dfs(i);
		if (oc[0].size()>oc[1].size())
			swap(oc[0], oc[1]);
		for (int j : oc[0])
			ans.push_back(j);
		oc[0].clear();
		oc[1].clear();
	}
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