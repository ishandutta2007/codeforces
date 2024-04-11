#include <bits/stdc++.h>
using namespace std;

const int INF = 10000000;
const int MAXN = 51;

int n, s, m;
vector<pair<int, int>> adj[MAXN];
int cnt[MAXN];

void dfs(int now, int prev) {
	for (auto [u, w]: adj[now]) {
		if (u != prev) {
			dfs(u, now);
			cnt[now] += cnt[u];
		}
	}
}

int dp[MAXN][MAXN][MAXN][MAXN];

int solve(int now, int prev, int p1, int p2) {
	if (p1 + p2 == 0) return 0;

	if (dp[now][prev][p1][p2] != -1) return dp[now][prev][p1][p2];
	if (adj[now].size() == 1 && prev != 0) {
		return dp[now][prev][p1][p2] = solve(now, 0, p2, 0);
	} 

	int lo = 0, hi = INF, ans = 0;
	while (lo <= hi) {
		int mid = (lo + hi)/2;

		int sum = 0;
		for (auto [u, w]: adj[now]) {
			if (u != prev) {
				int l = 1, r = p1, rs = 0;
				while (l <= r) {
					int md = (l + r)/2;
					if ((w + solve(u, now, md, p2 + (p1 - md))) >= mid) {
						l = md + 1; rs = md;
					} else {
						r = md - 1;
					}
				}
				sum += rs;
			}
		}

		if (sum >= p1) {
			lo = mid + 1; ans = mid;
		} else {
			hi = mid - 1;
		}
	}

	return dp[now][prev][p1][p2] = ans;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 1; i < n; i++) {
		int x, y, z; cin >> x >> y >> z;
		adj[x].emplace_back(y, z);
		adj[y].emplace_back(x, z);
	}
	cin >> s >> m;
	for (int i = 0; i < m; i++) {
		int x; cin >> x;
		cnt[x]++;
	}
	dfs(s, 0);

	memset(dp, -1, sizeof(dp));
	int ans = INF;
	for (auto [u, w]: adj[s]) {
		ans = min(ans, solve(u, s, cnt[u], m - cnt[u]) + w);
	}
	cout << ans << '\n';

	return 0;
}