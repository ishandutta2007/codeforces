#include <bits/stdc++.h>
using namespace std;
 
long long modpow(long long n, long long k, long long MOD) {
	long long ans = 1; n %= MOD;
	while (k > 0) {
		if (k & 1) ans = (ans*n) % MOD;
		k >>= 1; n = (n*n) % MOD;
	}
	return ans;
}
 
signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
 
	int n, m; cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
		sort(a.begin(), a.end());
 
	vector<int> cnt(m);
	vector<long long> diff(m);
	for (int i = 0; i < n; i++) {
		int x = a[i];
		for (int j = 0; j < m; j++) {
			int k = abs(x - j) % m;
			diff[k] += cnt[j];
		}
		cnt[x % m]++;
	}
 
	int ans = 1;
	for (int i = 0; i < m; i++) {
		ans = (1LL * ans * modpow(i, diff[i], m)) % m;
	}
	cout << ans << '\n';
 
	return 0;
}