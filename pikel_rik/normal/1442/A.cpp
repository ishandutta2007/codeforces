#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<ll> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];

		ll cur = INT_MAX;

		for (int i = 0; i < n - 1; i++) {
			cur = min(cur, a[i]);
			if (a[i] > a[i + 1]) {
				cur -= a[i] - a[i + 1];
			}
		}
		cout << (cur >= 0 ? "YES" : "NO") << '\n';
	}
	return 0;
}