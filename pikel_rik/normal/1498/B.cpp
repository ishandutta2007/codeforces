#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, W;
		cin >> n >> W;

		vector<int> cnt(30);

		for (int i = 0, x; i < n; i++) {
			cin >> x;
			int msb = 32 - __builtin_clz(x) - 1;
			cnt[msb] += 1;
		}

		vector<int> cap(n, W);
		for (int j = 29; j >= 0; j--) {
			for (int i = 0; i < n && cnt[j] > 0; i++) {
				while (cnt[j] > 0 && cap[i] >= (1 << j)) {
					cnt[j] -= 1, cap[i] -= (1 << j);
				}
			}
		}

		cout << n - count(cap.begin(), cap.end(), W) << '\n';
	}
	return 0;
}