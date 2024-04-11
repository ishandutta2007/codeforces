#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n);
	for (auto &x : a) cin >> x;

	int ans = 0;
	for (int b = 0; b < 25; b++) {
		vector<int> cnt(1 << (b + 1));
		for (int i = 0; i < n; i++) {
			cnt[a[i] % (1 << (b + 1))] += 1;
		}

		partial_sum(cnt.begin(), cnt.end(), cnt.begin());

		long long times = 0;
		for (int i = 0; i < (1 << (b + 1)); i++) {
			int l = max(0, (1 << b) - i), r = (1 << (b + 1)) - i - 1;

			long long temp = 0;
			temp += cnt[r] - (l == 0 ? 0 : cnt[l - 1]);
			temp -= l <= i && i <= r;

			int j = (1 << (b + 1)) + (1 << b) - i;
			if (j < (1 << (b + 1))) {
				temp += cnt.back() - cnt[j - 1];
				temp -= j <= i;
			}
			times += temp * (i == 0 ? cnt[0] : cnt[i] - cnt[i - 1]);
		}
		assert(times % 2 == 0);
		times /= 2;
		if (times % 2 != 0) {
			ans |= (1 << b);
		}
	}
	cout << ans << '\n';
	return 0;
}