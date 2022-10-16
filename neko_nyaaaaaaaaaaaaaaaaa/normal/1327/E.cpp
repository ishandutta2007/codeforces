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

#define int long long
const long long M = 998244353;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		if (i == n) {cout << "10 "; break;}

		int block_boundary = 2;
		int block_normal = n - i + 1 - block_boundary;

		int f1 = (10*9*block_boundary) % M;
		f1 = (f1 * modpow(10, n - i - 1, M)) % M;

		int f2 = (10*9*9*block_normal) % M;
		if (block_normal) f2 = (f2 * modpow(10, n - i - 2, M)) % M;

		cout << (f1 + f2) % M << ' ';
	}

	return 0;
}