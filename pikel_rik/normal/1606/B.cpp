#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		long long n, k;
		cin >> n >> k;

		long long hours = 0;

		long long fixed = 1;
		while (fixed < k) {
			fixed += fixed;
			hours += 1;
		}

		hours += (max(0ll, n - fixed) + k - 1) / k;
		cout << hours << '\n';
	}
	return 0;
}