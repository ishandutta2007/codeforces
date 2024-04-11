#include <bits/stdc++.h>
using namespace std;

#define int long long

int get_val(int val, int p) {
	// cut into p parts
	int v1 = val/p;
	int v2 = v1+1;

	int p2 = val % p;
	int p1 = p - p2;

	return v1*v1*p1 + v2*v2*p2;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	priority_queue<tuple<int, int, int>> pq;
	for (int i = 0; i < n; i++) {
		pq.push({get_val(a[i], 1) - get_val(a[i], 2), 1, i});
	}

	int sc = n;
	while (sc < k) {
		sc++;
		auto [ss, p, id] = pq.top(); pq.pop();
		int val = a[id];

		pq.push({get_val(val, p+1) - get_val(val, p+2), p+1, id});
	}

	int ans = 0;
	while (pq.size()) {
		auto [ss, p, id] = pq.top(); pq.pop();
		//cout << id << ' ' << p << '\n';
		ans += get_val(a[id], p);
	}
	cout << ans << '\n';

	return 0;
}