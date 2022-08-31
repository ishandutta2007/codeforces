#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

ll f(ll x) {
	return (x * x + x) / 2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, m, r, c;
		cin >> n >> m >> r >> c;

		cout << max(r - 1, n - r) + max(c - 1, m - c) << '\n';
	}
	return 0;
}