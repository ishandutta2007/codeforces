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

		if (n <= 3) {
			cout << n - 1 << '\n';
			continue;
		}

		if (n % 2 == 0) {
			cout << 2 << '\n';
		} else {
			cout << 3 << '\n';
		}
	}
	return 0;
}