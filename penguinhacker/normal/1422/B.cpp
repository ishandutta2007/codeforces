#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m, a[100][100];
bool vis[100][100];

void solve() {
	cin >> n >> m;
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (vis[i][j]) continue;
			vector<int> cur;
			auto add = [&](int ci, int cj) {
				if (vis[ci][cj]) return;
				vis[ci][cj] = 1;
				cur.push_back(a[ci][cj]);
			};
			add(i, j);
			add(n - i - 1, j);
			add(i, m - j - 1);
			add(n - i - 1, m - j - 1);
			sort(cur.begin(), cur.end());
			int x = cur[cur.size() / 2];
			for (int i  : cur) {
				ans += abs(x - i);
			}
		}
	}
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