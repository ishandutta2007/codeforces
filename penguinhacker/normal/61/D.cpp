#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n;
vector<ar<int, 2>> adj[100000];
ll ans=0, sub=0;

void dfs(int u=0, int p=-1, ll d=0) {
	sub=max(sub, d);
	for (ar<int, 2> v: adj[u])
		if (v[0]!=p)
			dfs(v[0], u, d+v[1]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=1; i<n; ++i) {
		int a, b, c; cin >> a >> b >> c;
		--a, --b, ans+=c;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	ans*=2;
	dfs();
	ans-=sub;
	cout << ans;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/