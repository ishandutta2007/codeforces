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

		if (n == 1 or n == 2 or n == 4) {
			cout << "-1\n";
		} else {
			if (n % 3 == 0) {
				cout << n / 3 << ' ' << 0 << ' ' << 0 << '\n';
			} else if (n % 3 == 2) {
				cout << (n - 5) / 3 << ' ' << 1 << ' ' << 0 << '\n';
			} else {
				cout << (n - 7) / 3 << ' ' << 0 << ' ' << 1 << '\n';
			}
		}
	}
	return 0;
}