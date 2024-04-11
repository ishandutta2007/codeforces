#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (ll i = k; i < n; i++)
#define ford(i, k, n) for (ll i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <queue>
#include <bitset>
#include <set>
#include <deque>
#include <stack>
#include <map>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<ll> vi;

const int sz = 2e5 + 5;
int n;
vector<int> adj[sz];
ll subt[sz], f[sz];
ll dpd[sz], dp[sz];

void dfs(int src, int prv) {
	subt[src] = 1;
	f[src] = prv;
	for (int x : adj[src]) {
		if (x == prv)continue;
		dfs(x, src);
		subt[src] += subt[x];
		dpd[src] += dpd[x];
	}
	dpd[src] += subt[src];
}

void dfs2(int src, int prv) {
	if (prv != -1)
		dp[src] = (dpd[src] + n - subt[src]) + (dp[f[src]] - subt[src] - dpd[src]);
	for (int x : adj[src]) {
		if (x != prv)
			dfs2(x, src);
	}
}

int main() {
	fast;
	cin >> n;
	foru(i, 0, n - 1) {
		int x, y;
		cin >> x >> y;
		adj[--x].pb(--y);
		adj[y].push_back(x);
	}
	dfs(0, -1);
	dp[0] = dpd[0];
	dfs2(0, -1);
	ll mx = 0;
	foru(i, 0, n)mx = max(mx, dp[i]);
	cout << mx;
	return 0;
}