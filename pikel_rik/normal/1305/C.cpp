#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 2e5 + 5;

int n, m, a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];

	if (n > m) {
		cout << 0 << '\n';
	} else {
		ll ans = 1;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				ans = ans * abs(a[i] - a[j]) % m;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}