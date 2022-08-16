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

		if (n > 2) {
			cout << 2 << '\n';
			cout << n << ' ' << n - 2 << '\n';
			cout << n - 1 << ' ' << n - 1 << '\n';
			for (int i = n - 3; i >= 1; i--) {
				cout << i << ' ' << i + 2 << '\n';
			}
		} else {
			cout << 2 << '\n';
			cout << 1 << ' ' << 2 << '\n';
		}
	}
	return 0;
}