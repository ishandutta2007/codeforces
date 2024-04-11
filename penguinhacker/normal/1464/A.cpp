#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m, x[100000], y[100000], p[100000];
bool vis[100000], check[100000];
void solve() {
	cin >> n >> m;
	memset(vis, 0, n);
	memset(check, 0, n);
	int ans = 0;
	for (int i = 0; i < m; ++i) {
		cin >> x[i] >> y[i], --x[i], --y[i];
		if (x[i] != y[i]) {
			++ans;
			p[x[i]] = y[i];
			check[x[i]] = 1;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (vis[i] || !check[i]) continue;
		int cur = i;
		while(!vis[cur] && check[cur]) {
			vis[cur] = 1;
			cur = p[cur];
		}
		ans += cur == i;
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) solve();
	return 0;
}