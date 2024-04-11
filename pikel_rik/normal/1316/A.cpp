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
		int n, m;
		cin >> n >> m;

		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];

		if (n > 1) {
			int sum = accumulate(a.begin() + 1, a.end(), 0);
			a[0] = min(m, a[0] + sum);
		}
		cout << a[0] << '\n';
	}
	return 0;
}