//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

#define div DIV

const int maxn = 2e5 + 10,
	  maxval = 2e5 + 20,
	  maxl = 20;
int div[maxval],
	h[maxn],
	dp[maxn],
	par[maxn],
	n;
bool mark[maxn],
	 dmark[maxn];
vector<int> adj[maxn],
	vec[maxval];

bool exist(int u) {
	return u != -1 and mark[u];
}

void dfs(int u, int p) {
	par[u] = p;
	for (auto v : adj[u])
		if (v ^ p) {
			h[v] = h[u] + 1;
			dfs(v, u);
		}
}

int little_dfs(int u) {
	dmark[u] = true;
	dp[u] = 1;
	int mx1 = 0, mx2 = 0;
	int ans = 0;
	for (auto v : adj[u]) {
		smax(ans, little_dfs(v));
		if (dp[v] > mx1) {
			mx2 = mx1;
			mx1 = dp[v];
		}
		else if (dp[v] > mx2)
			mx2 = dp[v];
	}
	dp[u] = mx1 + 1;
	return max(ans, mx1 + mx2 + 1);
}

bool hcmp(int u, int v) {
	return h[u] < h[v];
}

int solve(vector<int> &verts) {
	if (!sz(verts)) return 0;
	for (auto u : verts) {
		mark[u] = true;
		dmark[u] = false;
		dp[u] = 1;
		adj[u].clear();
	}

	sort(all(verts), hcmp);
	for (int i = sz(verts) - 1; i >= 0; i--) {
		int u = verts[i];
		if (exist(par[u]))
			adj[par[u]].PB(u);
	}
	int ans = 0;
	for (auto u : verts)
		if (!dmark[u])
			smax(ans, little_dfs(u));

	for (auto u : verts)
		mark[u] = false;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	memset(div, -1, sizeof div);
	for (int i = 2; i < maxval; i++)
		if (div[i] == -1)
			for (int j = i; j < maxval; j += i)
				div[j] = i;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		while (x > 1) {
			int d = div[x];
			vec[d].PB(i);
			while (x % d == 0)
				x /= d;
		}
	}
	for (int i = 1; i < n; i++) {
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	dfs(0, -1);
	int ans = 0;
	for (int i = 0; i < maxval; i++)
		smax(ans, solve(vec[i]));
	cout << ans << endl;
	return 0;
}