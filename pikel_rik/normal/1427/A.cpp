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

		int sum = accumulate(a.begin(), a.end(), 0);
		if (sum == 0) {
			cout << "NO\n";
			continue;
		} else if (sum < 0) {
			sort(a.begin(), a.end());
		} else {
			sort(a.rbegin(), a.rend());
		}
		cout << "YES\n";
		for (int i : a) cout << i << ' '; cout << '\n';
	}
	return 0;
}