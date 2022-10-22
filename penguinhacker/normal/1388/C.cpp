#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n, m, a[mxN], h[mxN], sub[mxN], unH[mxN]; //unhappy
vector<int> adj[mxN];

bool dfs(int u=0, int p=-1) {
	sub[u]=a[u];
	for (int v: adj[u]) if (v!=p) {
		if (!dfs(v, u)) return 0;
		sub[u]+=sub[v];
	}
	if (abs(sub[u]-h[u])&1) return 0;
	return 1;
}

bool dfs2(int u=0, int p=-1) {
	if (abs(h[u])>sub[u]) return 0;
	unH[u]=(sub[u]-h[u])/2;
	//cout << u << ' ' << unH[u] << " A\n";
	int k=unH[u]-a[u];
	for (int v: adj[u]) if(v!=p) {
		if (!dfs2(v, u)) return 0;
		k-=unH[v];
	}
	return k<=0;
}

void test_case() {
	cin >> n >> m;
	for (int i=0; i<n; ++i) cin >> a[i];
	for (int i=0; i<n; ++i) cin >> h[i];
	for (int i=0; i<n; ++i) adj[i].clear();
	for (int i=1; i<n; ++i) {
		int a, b; cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	if (!dfs()) {cout << "NO\n"; return;}
	//for (int i=0; i<n; ++i) cout << sub[i] << ' ';
	//cout << '\n';
	cout << (dfs2()?"YES":"NO") << '\n';
	//for (int i=0; i<n; ++i) cout << unH[i] << ' ';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	while(t--)
		test_case();
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/