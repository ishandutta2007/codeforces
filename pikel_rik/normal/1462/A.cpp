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

		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];

		for (int l = 0, r = n - 1; l <= r; l++, r--) {
			cout << a[l] << ' ';
			if (l != r) {
				cout << a[r] << ' ';
			}
		}
		cout << '\n';
	}
	return 0;
}