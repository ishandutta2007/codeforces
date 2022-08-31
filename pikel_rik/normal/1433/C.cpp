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
		for (auto& aa : a) cin >> aa;

		auto [mn, mx] = minmax_element(a.begin(), a.end());
		if (*mx == *mn) {
			cout << "-1\n";
			continue;
		}

		for (int i = 0; i < n; i++) {
			if (a[i] == *mx) {
				if ((i == 0 or a[i - 1] == *mx) && (i + 1 == n or a[i + 1] == *mx)) continue;
				cout << i + 1 << '\n';
				break;
			}
		}
	}
	return 0;
}