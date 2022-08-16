#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		long long n; int m;
		cin >> n >> m;

		vector<int> a(m);
		for (int i = 0; i < m; i++) cin >> a[i];

		long long sum = accumulate(a.begin(), a.end(), 0ll);

		if (sum < n) {
			cout << "-1\n";
			continue;
		}

		vector<int> cnt(60);
		for (int x : a) {
			cnt[32 - __builtin_clz(x) - 1]++;
		}

		long long ans = 0;
		for (int i = 0; i < 60; i++) {
			if (n & (1ll << i)) {
				if (cnt[i] == 0) {
					int bit = i + 1;
					for (; !cnt[bit]; bit++);
					cnt[bit]--;
					cnt[i] += 2;
					for (int j = i + 1; j < bit; j++) cnt[j]++;
					ans += bit - i;
				}
				cnt[i] -= 1;
			}
			if (i + 1 != 60) {
				cnt[i + 1] += cnt[i] / 2;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}