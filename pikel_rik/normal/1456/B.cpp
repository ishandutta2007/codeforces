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

	for (int i = 2; i < n; i++) {
		if (__builtin_clz(a[i - 2]) == __builtin_clz(a[i - 1]) && __builtin_clz(a[i - 1]) == __builtin_clz(a[i])) {
			cout << "1\n";
			return 0;
		}
	}

	int ans = INT_MAX;
	for (int i = 0; i < n; i++) {
		int xor_sum = 0;
		for (int j = i; j < n; j++) {
			xor_sum ^= a[j];
			int other_sum = 0;
			for (int k = i - 1; k >= 0; k--) {
				other_sum ^= a[k];
				if (xor_sum < other_sum) {
					ans = min(ans, j - 1 - k);
				}
			}
		}
	}

	cout << (ans != INT_MAX ? ans : -1) << '\n';
	return 0;
}