#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i]; a[i] -= i;
	}

	priority_queue<int> q;
	q.push(a[0]);

	int ans = 0;
	for (int i = 1; i < n; i++) {
		q.push(a[i]);
		if (q.top() > a[i]) {
			ans += q.top() - a[i];
			q.pop(); q.push(a[i]);
		}
	}
	cout << ans;

	return 0;
}