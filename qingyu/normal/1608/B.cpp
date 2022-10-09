#include <bits/stdc++.h>

const int N = 1e6 + 50;
int arr[N];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int t;
	std::cin >> t;
	while (t--) {
		int n, a, b;
		std::cin >> n >> a >> b;
		if (abs(a - b) <= 1 && a + b <= n - 2) {
			if (a == b) {
				int tot = 0;
				int t = a + 1;
				for (int k = 1; k <= t; ++k) {
					arr[++tot] = t - k + 1;
					if (k != t) arr[++tot] = n - k + 1;
				}
				for (int i = t + 1; i <= n - t + 1; ++i) {
					arr[++tot] = i;
				}
			}
			else if (a == b + 1) {
				int tot = 0;
				for (int k = 1; k <= a; ++k) {
					arr[++tot] = a - k + 1;
					arr[++tot] = n - k + 1;
				}
				for (int i = n - a; i >= a; --i) {
					arr[++tot] = i;
				}
			}
			else {
				int tot = 0;
				for (int k = 1; k <= b; ++k) {
					arr[++tot] = n - k + 1;
					arr[++tot] = b - k + 1;
				}
				for (int i = b + 1; i <= n - b; ++i) {
					arr[++tot] = i;
				}
			}
			for (int i = 1; i <= n; ++i) std::cout << arr[i] << " ";
			std::cout << '\n';
		}
		else std::cout << -1 << '\n';
	}
}