#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=5e5+5;

int n, m, in[mxN];
vector<pair<int, int>> v;
vector<int> adj[mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0, u, v; i<m; ++i) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i=1, a; i<=n; ++i) {
		cin >> a;
		v.emplace_back(a, i);
	}
	sort(v.begin(), v.end());
	for (int i=0; i<n; ++i) {
		int col=v[i].first, ind=v[i].second;
		if (col!=++in[ind]) {
			cout << -1;
			return 0;
		}
		for (int j : adj[ind])
			if (in[j]==col-1)
				in[j]=col;
	}
	for (int i=0; i<n; ++i)
		cout << v[i].second << ' ';
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/