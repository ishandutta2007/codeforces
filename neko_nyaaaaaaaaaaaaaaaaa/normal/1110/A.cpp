#include <bits/stdc++.h>
using namespace std;

#define int long long

int modpow(int n, int k, int MOD) {
	int ans = 1; n %= MOD;
	while (k > 0) {
		if (k & 1) ans = (ans*n) % MOD;
		k >>= 1; n = (n*n) % MOD;
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int b, k; cin >> b >> k;
	int ans = 0;
    while (k--) {
		int x; cin >> x;
		ans += x*modpow(b, k, 2);
		ans %= 2;
    }
    cout << (ans ? "odd" : "even");

	return 0;
}