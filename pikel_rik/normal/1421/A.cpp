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
		int a, b;
		cin >> a >> b;

		int ans = 0;
		for (int i = 29; i >= 0; i--) {
			if ((a & (1 << i)) != (b & (1 << i))) {
				ans |= (1 << i);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}