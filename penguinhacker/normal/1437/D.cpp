#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a[200000], d[200000];

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i], --a[i];
	queue<int> q;
	q.push(0);
	int ind = 1;
	int ans = 0;
	auto Add = [&](int u) {
		assert(ind < n);
		d[a[ind]] = d[u] + 1;
		ans = max(ans, d[a[ind]]);
		q.push(a[ind++]);
	};
	while(!q.empty()) {
		int u = q.front(); q.pop();
		if (ind < n) Add(u);
		while(ind < n && a[ind] > a[ind - 1]) Add(u);
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}