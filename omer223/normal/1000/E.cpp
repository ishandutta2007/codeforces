#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <bitset>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
const ll sz = 5e5;

int n, m, totMx = 0;

vector<pii> adj[sz];
bitset<sz> vis;
int dep[sz], f[sz], dp[sz];

void input() {
	cin >> n >> m;
	foru(i, 0, m) {
		int a, b;
		cin >> a >> b;
		adj[--a].pb({ --b,0 });
		adj[b].pb({ a,0 });
	}
}

void dfs(int src, int prv) {
	vis[src] = 1;
	f[src] = prv;
	for (auto &k : adj[src]) {
		if (k.first == prv) k.second = 1;
		else if (!vis[k.first]) {
			k.second = 1;
			dep[k.first] = dep[src] + 1;
			dfs(k.first, src);
		}
	}
}

void dfs2(int src, int prv) {
	for (auto &x : adj[src]) {
		if (x.first == prv)continue;
		else if (x.second == 1) {
			dfs2(x.first, src);
			dp[src] += dp[x.first];
		}
		else {
			if (dep[src] > dep[x.first])dp[src]--;
			else dp[src]++;
		}
	}
}

void dfs3(int src, int prv) {
	for (auto &x : adj[src]) {
		if (x.first == prv) {
			if (!dp[src])x.second = 2;
		}
		else if (x.second) {
			if (!dp[x.first])x.second = 2;
			dfs3(x.first, src);
		}
	}
}

void findBridges() {
	dfs2(0, -1);
	dfs3(0, -1);
}

int foo(int src, int prv) {
	int f = 0, s = 0;
	for (auto x : adj[src]) {
		if (x.first == prv || x.second == 0)continue;
		int y = foo(x.first, src) + (x.second == 2);
		if (y > f) {
			s = f;
			f = y;
		}
		else if (y > s)s = y;
	}
	totMx = max(totMx, f + s);
	return f;
}

int main() {
	fast;
	input();
	dfs(0, -1);
	findBridges();
	totMx = 0;
	foo(0, -1);
	cout << totMx << endl;
	return 0;
}