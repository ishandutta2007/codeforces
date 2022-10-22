#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, a[mxN], p[mxN], t, tin[mxN], tout[mxN], ft[mxN+1], dp[mxN];
vector<int> adj[mxN], oc[mxN];
bool bad[mxN];

void upd(int i, int x) {
	for (++i; i<=n; i+=i&-i)
		ft[i]+=x;
}

int qry(int i) {
	int r=0;
	for (++i; i; i-=i&-i)
		r+=ft[i];
	return r;
}

void dfs(int u=0) {
	tin[u]=t++;
	for (int v : adj[u])
		if (v^p[u])
			p[v]=u, dfs(v);
	tout[u]=t-1;
}

void dfs2(int u=0) {
	bad[u]|=dp[u]>0;
	for (int v : adj[u])
		if (v^p[u])
			dp[v]+=dp[u], dfs2(v);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	vector<int> d(a, a+n);
	sort(d.begin(), d.end());
	d.resize(unique(d.begin(), d.end())-d.begin());
	for (int i=0; i<n; ++i) {
		a[i]=lower_bound(d.begin(), d.end(), a[i])-d.begin();
		oc[a[i]].push_back(i);
	}
	for (int i=1; i<n; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs();
	for (int i=0; i<d.size(); ++i) {
		if (oc[i].size()<2)
			continue;
		for (int j : oc[i])
			upd(tin[j], 1);
		for (int u : oc[i]) {
			// can u be the bottom part of a path? - must not have everything in subtree
			int x=qry(tout[u])-qry(tin[u]-1);
			if (x<oc[i].size())
				++dp[u];
			// can u be top part of a path? - check its children to see if any paths arent passing through child
			if (x>1)
				bad[u]=1, ++dp[0], --dp[u];
			for (int v : adj[u]) {
				if (v==p[u])
					continue;
				if (qry(tout[v])-qry(tin[v]-1)<x-1)
					++dp[v];
			}
		}
		for (int j : oc[i])
			upd(tin[j], -1);
	}
	/*for (int i=0; i<n; ++i) {
		cout << bad[i] << " " << dp[i] << endl;
	}*/
	dfs2();
	int ans=0;
	for (int i=0; i<n; ++i)
		ans+=!bad[i];
	cout << ans;
	return 0;
}