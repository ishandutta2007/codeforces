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
		int n, x;
		cin >> n >> x;

		vector<int> a(n), b(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];

		sort(a.begin(), a.end());
		sort(b.rbegin(), b.rend());

		bool ans = true;
		for (int i = 0; i < n; i++) {
			ans &= a[i] + b[i] <= x;
		}
		cout << (ans ? "Yes" : "No") << '\n';
	}
	return 0;
}