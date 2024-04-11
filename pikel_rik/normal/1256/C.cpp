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

	int n, m, d;
	cin >> n >> m >> d;

	vector<int> a(n + 1), c(m);
	for (int i = 0; i < m; i++) cin >> c[i];

	int sum = accumulate(c.begin(), c.end(), 0);

	if (sum + (d - 1) * (m + 1) < n) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		sum -= c[0];

		for (int i = 1, j = 0; j < m && i <= n; i++) {
			if (sum + (d - 1) * (m + 1 - (j + 1)) >= n - (i + c[j] - 1)) {
				for (int k = i; k < i + c[j]; k++) {
					a[k] = j + 1;
				}
				i += c[j] - 1;
				j += 1;
				if (j < m) {
					sum -= c[j];
				}
			}
		}

		for (int i = 1; i <= n; i++) cout << a[i] << ' ';
		cout << '\n';
	}
	return 0;
}