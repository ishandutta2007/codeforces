#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 123;
const int MOD = (int) 1e9 + 7;
const ll LINF = (ll) 1e18 + 123;

#define sz(x) (int) (x).size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define all(x) (x).begin(), (x).end()

void run();

int main() {
	cout << setprecision(15) << fixed;
#ifndef LOCAL
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
#endif
	run();
	return 0;
}

// == BEGIN SOLUTION == //

const int N = (int) 2e5 + 123;

int n, m, k;
vector<int> g[N];
int ptr;
vector<int> ans[N];
bool vis[N];

int mx;

void dfs(int v) {
	vis[v] = 1;
	for (int u : g[v]) {
		if (vis[u]) continue;
		
		ans[ptr].pb(u);
		if (sz(ans[ptr]) == mx) ptr++;
		dfs(u);
		if (sz(ans[ptr]) != 0) {
			ans[ptr].pb(v);
			if (sz(ans[ptr]) == mx) ptr++;
		}
	}
}

void run() {
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	
	mx = (2 * n + k - 1) / k;
	
	ans[ptr].pb(1);
	if (sz(ans[ptr]) == mx) ptr++;
	dfs(1);
	for (int i = 0; i < k; i++) {
		if (!sz(ans[i])) {
			ans[i].pb(1);
		}
	}
	
	for (int i = 0; i < k; i++) {
		cout << sz(ans[i]) << " ";
		for (int j : ans[i]) cout << j << " ";
		cout << "\n";
	}
}