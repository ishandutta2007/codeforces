#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, ans, a[mxN];
vector<int> adj[mxN], f[mxN+1], oc[mxN];
bool act[mxN], vis[mxN];

void upd(ar<int, 2>& b, int x) {
	if (x>b[0])
		b={x, b[0]};
	else if (x>b[1])
		b[1]=x;
}

ar<int, 2> dfs(int u, int p=-1) { // <diameter, path>
	vis[u]=1;
	ar<int, 2> r={0, 0};
	ar<int, 2> b={0, 0};
	for (int v : adj[u]) {
		if (v==p||!act[v])
			continue;
		ar<int, 2> c=dfs(v, u);
		r[0]=max(r[0], c[0]);
		upd(b, c[1]+1);
	}
	r[0]=max(r[0], b[0]+b[1]);
	r[1]=b[0];
	return r;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i=2; i<=mxN; ++i) {
		if (f[i].size())
			continue;
		for (int j=i; j<=mxN; j+=i)
			f[j].push_back(i);
	}
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		for (int j : f[a[i]])
			oc[j].push_back(i);
	}
	for (int i=1; i<n; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i=2; i<=mxN; ++i) {
		if (oc[i].empty())
			continue;
		for (int j : oc[i])
			act[j]=1;
		for (int j : oc[i])
			if (!vis[j])
				ans=max(ans, dfs(j)[0]+1);
		for (int j : oc[i])
			act[j]=vis[j]=0;
	}
	cout << ans;
	return 0;
}