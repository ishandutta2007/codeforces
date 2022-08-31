#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 1e5 + 5;

int n, a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	if (n % 2 != 0) {
		cout << "YES\n";
		vector<tuple<int, int, int>> ans;

		for (int i = 0; i + 2 < n; i += 2) {
			ans.emplace_back(i, i + 1, i + 2);
		}

		for (int i = n - 5; i >= 0; i -= 2) {
			ans.emplace_back(i, i + 1, i + 2);
		}

		cout << ans.size() << '\n';
		for (auto&[i, j, k] : ans) {
			cout << i + 1 << ' ' << j + 1 << ' ' << k + 1 << '\n';
		}
	} else {
		int xor_sum = accumulate(a, a + n, 0, bit_xor<>());

		if (xor_sum == 0) {
			cout << "YES\n";
			vector<tuple<int, int, int>> ans;

			for (int i = 1; i + 2 < n; i += 2) {
				ans.emplace_back(i, i + 1, i + 2);
			}

			for (int i = n - 5; i >= 1; i -= 2) {
				ans.emplace_back(i, i + 1, i + 2);
			}

			cout << ans.size() << '\n';
			for (auto&[i, j, k] : ans) {
				cout << i + 1 << ' ' << j + 1 << ' ' << k + 1 << '\n';
			}
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}