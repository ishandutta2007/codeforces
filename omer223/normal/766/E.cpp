#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <unordered_set>
#include <bitset>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 1e5, MXLOG = 20;
bitset<sz> v;
int n,a[sz];
ll dp[sz], dpb[sz][2];
vector<int> adj[sz];

void dfs(int src, int prv) {
	dpb[src][0] = dpb[src][1] = dp[src] = 0;
	ll os = 0, oss = 0, es = 0, ess = 0, oe = 0;
	for (int x : adj[src]) {
		if (x != prv) {
			dfs(x, src);
			dp[src] += dp[x];
			os += dpb[x][1];
			oss += (dpb[x][1] * dpb[x][1]);
			es += dpb[x][0];
			ess += (dpb[x][0] * dpb[x][0]);
			oe += (dpb[x][0] * dpb[x][1]);
		}
	}
	if (v[src]) {
		dpb[src][1] += (es + 1);
		dpb[src][0] += os;
		dp[src]++;
		dp[src] += es;
		dp[src] += ((os*os - oss + es * es - ess)) / 2;
	}
	else {
		dpb[src][1] += os;
		dpb[src][0] += (es + 1);
		dp[src] += os;
		dp[src] += (os*es - oe);
	}
}

int main() {
	fast;
	ll ret = 0, tpw = 1;
	cin >> n;
	foru(i, 0, n)cin >> a[i];
	foru(i, 0, n - 1) {
		int a, b;
		cin >> a >> b;
		adj[--a].pb(--b);
		adj[b].pb(a);
	}
	for (int j = 0; j <= MXLOG; j++) {
		for (int i = 0; i < n; i++)v[i] = ((a[i] >> j) & 1);
		dfs(0, -1);
		ret += dp[0] * tpw;
		tpw <<= 1;
	}
	cout << ret << '\n';
	return 0;
}