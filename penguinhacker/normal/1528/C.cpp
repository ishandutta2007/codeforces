#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=3e5;
int n, a[mxN], b[mxN], tin[mxN], tout[mxN], t, ans;
vector<int> adj1[mxN], adj2[mxN];
set<int> s;

void dfs1(int u=0) {
	tin[u]=t++;
	for (int v : adj2[u])
		dfs1(v);
	tout[tin[u]]=t-1;
}

bool anc(int u, int v) {
	return u<=v&&tout[v]<=tout[u];
}

void dfs2(int u=0) {
	//cout << u << endl;
	int rem=-1, add=0;
	auto it=s.lower_bound(tin[u]);
	if (it!=s.end()||!anc(tin[u], *it)) {
		add=1;
		if (it!=s.begin()) {
			--it;
			if (anc(*it, tin[u])) {
				rem=*it;
				s.erase(it);
			}
		}
		s.insert(tin[u]);
	}
	ans=max(ans, (int)s.size());
	for (int v : adj1[u])
		dfs2(v);
	if (add)
		s.erase(tin[u]);
	if (rem^-1)
		s.insert(rem);
}

void solve() {
	cin >> n;
	t=ans=0;
	for (int i=0; i<n; ++i) {
		adj1[i].clear();
		adj2[i].clear();
	}
	for (int i=1; i<n; ++i) {
		cin >> a[i], --a[i];
		adj1[a[i]].push_back(i);
	}
	for (int i=1; i<n; ++i) {
		cin >> b[i], --b[i];
		adj2[b[i]].push_back(i);
	}
	dfs1();
	dfs2();
	cout << ans << "\n";
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