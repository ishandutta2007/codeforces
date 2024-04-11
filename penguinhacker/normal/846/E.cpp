#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n;
ll a[mxN], b[mxN];
vector<ar<int, 2>> adj[mxN];

ll dfs(int u=0) { // >0 = extra, <0 = need
	ll x=a[u]-b[u];
	for (ar<int, 2> v : adj[u]) {
		ll y=dfs(v[0]);
		if (y>=0)
			x+=y;
		else {
			y*=-1;
			if ((long double)y*v[1]>=1e18) {
				cout << "NO";
				exit(0);
			}
			if ((x-=y*v[1])<=-1e18) {
				cout << "NO\n";
				exit(0);
			}
		}
	}
	return x;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	for (int i=0; i<n; ++i)
		cin >> b[i];
	for (int i=1; i<n; ++i) {
		int x, k;
		cin >> x >> k, --x;
		adj[x].push_back({i, k});
	}
	cout << (dfs()>=0?"YES":"NO");
	return 0;
}