#include <bits/stdc++.h>

const int N = 1e5 + 50;
int n, a[N];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int t;
	std::cin >> t;
	while (t--) {
		std::cin >> n;
		std::vector<int> a(n), b(n);
		std::bitset<20005> bs;
		long long sum = 0, cons = 0;
		for (int &x : a) {
			std::cin >> x;
			sum += x;
			cons += x * x;
		}
		for (int &x : b) {
			std::cin >> x;
			sum += x;
			cons += x * x;
		}
		bs[0] = 1;
		for (int i = 0; i < n; ++i) {
			bs = (bs << a[i]) | (bs << b[i]);
		}
		long long ans = 1e18;
		for (int i = 0; i <= sum; ++i) if (bs[i]) {
			assert(bs[sum - i]);
			ans = std::min(ans, 1ll * i * i + 1ll * (sum - i) * (sum - i));
		}
		std::cout << (n - 2) * cons + ans << '\n';
	}
}