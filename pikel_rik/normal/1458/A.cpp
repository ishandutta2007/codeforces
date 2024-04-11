#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	using ll = long long;

	int n, m;
	cin >> n >> m;

	vector<ll> a(n), b(m);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];

	sort(a.begin(), a.end());

	ll g = 0;
	for (int i = 1; i < n; i++) g = __gcd(g, a[i] - a[0]);

	for (int i = 0; i < m; i++) {
		cout << __gcd(a[0] + b[i], g) << ' ';
	}
	cout << '\n';
	return 0;
}