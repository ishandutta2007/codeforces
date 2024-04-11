#include <bits/stdc++.h>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int n_cases;
	cin >> n_cases;
	while ((n_cases--) > 0) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		int g = 0;
		for (; g < n && a[g] == a[0]; ++g);
		int sum = 0;
		for (int i = g; i < n / 2; ++i) {
			if (a[i] != a[i + 1]) {
				sum = i + 1;
			}
		}
		int s = 0;
		int b = 0;
		if (sum > g) {
			for (int k = g; k < sum; ++k) {
				if (a[k] != a[k + 1] && k + 1 - g > g && sum - (k + 1) > g) {
					s = k + 1 - g;
					b = sum - (k + 1);
					break;
				}
			}
		}
		if (s == 0 || b == 0) {
			g = 0;
		}
		printf("%d %d %d\n", g, s, b);
	}
	return 0;
}