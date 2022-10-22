#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=3e5;
int n, m, q, t, tin[mxN], bad[mxN], rs[mxN];
vector<int> adj[mxN];
stack<int> s;
set<int> s2;
ll p[mxN+1];

void dfs(int u, int p=-1) {
	tin[u]=t++;
	s.push(u);
	for (int v : adj[u]) {
		if (v==p)
			continue;
		if (tin[v]==-1) {
			dfs(v, u);
		} else if (tin[v]<tin[u]) {
			int l=v, r=v;
			while(s.top()!=v) {
				l=min(l, s.top()), r=max(r, s.top());
				s.pop();
			}
			s.pop();
			bad[l]=r;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	memset(tin, -1, 4*n);
	for (int i=0; i<n; ++i)
		if (tin[i]==-1)
			dfs(i);
	for (int l=0, r=-1; l<n; ++l) {
		while(r+1<n&&(s2.empty()||r+1<*s2.begin()))
			if (bad[++r])
				s2.insert(bad[r]);
		rs[l]=r;
		p[l+1]=p[l]+rs[l];
		if (bad[l])
			s2.erase(bad[l]);
	}
	cin >> q;
	while(q--) {
		int l, r;
		cin >> l >> r, --l, --r;
		ll ans=(r-l+1)-1ll*(r-l+1)*(l+r)/2;
		int x=lower_bound(rs+l, rs+r+1, r)-rs;
		ans+=(ll)(r-x+1)*r;
		ans+=p[x]-p[l];
		cout << ans << "\n";
	}
	return 0;
}