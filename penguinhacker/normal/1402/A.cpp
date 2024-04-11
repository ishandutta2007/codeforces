#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5, MOD=1e9+7;
int n, m, sz[mxN];
vector<int> adj[mxN];
vector<ll> cnt;

void dfs(int u=0, int p=-1) {
	sz[u]=1;
	for (int v: adj[u]) if (v!=p) {
		dfs(v, u);
		sz[u]+=sz[v];
		cnt.push_back((ll)sz[v]*(n-sz[v]));
	}
}

void solve() {
	cin >> n;
	for (int i=0; i<n; ++i)
		adj[i].clear();
	for (int i=1; i<n; ++i) {
		int a, b; cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	cin >> m;
	vector<int> f(m);
	for (auto& i: f) cin >> i;
	sort(f.begin(), f.end());
	while(f.size()>=n) {
		int x=f.back();
		f.pop_back();
		int y=f.back();
		f.pop_back();
		f.push_back((ll)x*y%MOD);
	}
	dfs();
	sort(cnt.begin(), cnt.end());
	ll ans=0;
	while(f.size()) {
		assert(cnt.size());
		ans+=cnt.back()%MOD*f.back()%MOD;
		f.pop_back();
		cnt.pop_back();
	}
	while(cnt.size()) {
		ans+=cnt.back();
		cnt.pop_back();
	}
	ans%=MOD;
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	while(t--)
		solve();
	return 0;
}