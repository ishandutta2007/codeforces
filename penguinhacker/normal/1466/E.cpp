#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int MOD = 1e9 + 7;
int n;
ll a[500000], cnt[60];
void solve() {
	memset(cnt, 0, sizeof(cnt));
	cin >> n;
	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sum = (sum + a[i]) % MOD;
		for (int j = 0; j < 60; ++j) {
			cnt[j] += (a[i] >> j) & 1;
		}
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		ll and_sum = 0;
		for (int j = 0; j < 60; ++j) {
			if ((a[i] >> j) & 1) {
				and_sum += (1ll << j) % MOD * cnt[j] % MOD;
			}
		}
		and_sum %= MOD;
		ll or_sum = (sum + a[i] % MOD * n - and_sum + MOD) % MOD;
		ans = (ans + and_sum * or_sum) % MOD;
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) solve();
	return 0;
}