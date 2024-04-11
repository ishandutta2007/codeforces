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

	int q;
	cin >> q;

	while (q--) {
		ll a, b, n, s;
		cin >> a >> b >> n >> s;

		if (a * n < s) {
			cout << (s - a * n <= b ? "YES" : "NO") << '\n';
		} else {
			cout << (s % n <= b ? "YES" : "NO") << '\n';
		}
	}
	return 0;
}