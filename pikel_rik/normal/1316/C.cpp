#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 1e6 + 5;

int n, m, p, a[N], b[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> p;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];

	while (n > 0 && a[n - 1] % p == 0) {
		n--;
	}
	while (m > 0 && b[m - 1] % p == 0) {
		m--;
	}

	cout << n + m - 2 << '\n';
	return 0;
}