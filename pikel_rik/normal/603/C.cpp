#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 1e5 + 5;

int n, k, a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];

	if (k % 2 == 0) {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] <= 2) {
				sum ^= a[i];
			} else {
				sum ^= (a[i] & 1) ^ 1;
			}
		}
		cout << (sum ? "Kevin" : "Nicky") << '\n';
	} else {
		int g[5] = {0, 1, 0, 1, 2};

		function<int(int)> grundy = [&](int x) -> int {
			if (x <= 4) {
				return g[x];
			}
			if (x % 2 != 0) {
				return 0;
			}
			int gg = grundy(x / 2);
			return 1 + (gg == 1);
		};

		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum ^= grundy(a[i]);
		}
		cout << (sum ? "Kevin" : "Nicky") << '\n';
	}
	return 0;
}