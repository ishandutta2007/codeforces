#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define last(X) (X)[(X).size() - 1]
typedef long long ll;
using namespace std;

int n, q, x, y;
vector<ll> a, dp;

ll query(int l, int r) {
	vector<pair<ll, ll>> q;
	q.push_back({ 2e9, l - 1 });
	ll rtn = 0;
	q.push_back({ a[l], l }), dp[1] = a[l], rtn = a[l];
	for (int i = l + 1; i <= r; i++) {
		while (last(q).first <= a[i]) q.pop_back();
		q.push_back({ a[i], i });
		ll val = dp[q.size() - 2] + q[q.size() - 1].first * (ll)(q[q.size() - 1].second - q[q.size() - 2].second);
		dp[q.size() - 1] = val, rtn += val;
	}
	return rtn;
}

int main() {
	ios::sync_with_stdio(0);
	cin >> n >> q;
	dp.resize(n + 1, 0);
	cin >> x;
	for (int i = 0; i < n - 1; i++)
		cin >> y, a.push_back(abs(x - y)), x = y;
	while (q--) {
		int l, r; cin >> l >> r;
		cout << query(l - 1, r - 2) << endl;
	}
}