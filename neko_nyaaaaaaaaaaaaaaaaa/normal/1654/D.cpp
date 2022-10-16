#include <bits/stdc++.h>
using namespace std;

#define int long long
const int M = 998244353;
const int MAXN = 200005;
int pr[MAXN+1];

void init() {
	for (int i = 2; i <= MAXN; i++) {
		if (pr[i] == 0) {
			for (int j = i; j <= MAXN; j += i) {
				pr[j] = i;
			}
		}
	}
}

int modpow(int n, int k) {
	int ans = 1;
	while (k > 0) {
		if (k % 2) ans = (ans*n) % M;
		n = (n*n) % M; k /= 2;
	}
	return ans;
}

vector<pair<int, int>> process(int n) {
	map<int, int> mp;
	while (n > 1) {
		mp[pr[n]]++; n /= pr[n];
	}
	vector<pair<int, int>> ans(mp.begin(), mp.end());
	return ans;
}

void dfs(int now, int prv, int val, map<int, int> &mn, map<int, int> &cur, int &ans, vector<vector<tuple<int, int, int>>> &adj) {
	ans = (ans + val) % M;

	//cout << now+1 << '\n';
	//for (auto [u, v]: cur) cout << u << ' ' << v << '\n';

	for (auto [u, x, y]: adj[now]) {
		if (u == prv) continue;

		vector<pair<int, int>> p = process(x), q = process(y);
		// * y / x, * q / p
		for (auto [pp, pw]: p) cur[pp] -= pw;
		for (auto [pp, pw]: q) cur[pp] += pw;

		for (auto [pp, pw]: p) mn[pp] = min(mn[pp], cur[pp]);
		for (auto [pp, pw]: q) mn[pp] = min(mn[pp], cur[pp]);

		int nxt = val;
		nxt = (nxt*y) % M;
		nxt = (nxt*modpow(x, M-2)) % M;

		dfs(u, now, nxt, mn, cur, ans, adj);

		for (auto [pp, pw]: p) cur[pp] += pw;
		for (auto [pp, pw]: q) cur[pp] -= pw;
	}
}

void solve() {
	int n; cin >> n;
	vector<vector<tuple<int, int, int>>> adj(n);
	for (int i = 1; i < n; i++) {
		int u, v, x, y; cin >> u >> v >> x >> y; u--, v--;
		adj[u].emplace_back(v, x, y);
		adj[v].emplace_back(u, y, x);
	}

	map<int, int> mn, cur;
	int ans = 0;

	dfs(0, 0, 1, mn, cur, ans, adj);
	for (auto [pp, pw]: mn) {
		if (pw == 0) continue;

		int tmp = modpow(pp, -pw);
		ans = (ans*tmp) % M;
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	init();

	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}