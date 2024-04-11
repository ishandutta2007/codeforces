#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<long long> factorize(long long n) {
	vector<long long> ans;
	for (long long i = 1; i*i <= n; i++) {
		if (n % i == 0) {
			ans.push_back(i);
			if (n/i != i) ans.push_back(n/i);
		}
	}
	sort(ans.begin(), ans.end());
	return ans;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n; cin >> n;
	vector<long long> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	shuffle(a.begin(), a.end(), rng);

	long long ans = 0;
	for (int s = 0; s < min(n, 8); s++) {
		auto dv = factorize(a[s]);

		vector<int> cnt(dv.size());
		for (int i = 0; i < n; i++) {
			long long g = __gcd(a[s], a[i]);

			int p = lower_bound(dv.begin(), dv.end(), g) - dv.begin();
			cnt[p]++;
		}

		for (int i = dv.size()-1; i >= 0; i--) {
			int c = cnt[i];
			for (int j = i+1; j < dv.size(); j++) {
				if (dv[j] % dv[i] == 0) {
					c += cnt[j];
				}
			}

			if (c+c >= n) {
				ans = max(ans, dv[i]);
			}
		}
	}	
	cout << ans << '\n';

	return 0;
}