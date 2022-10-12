#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e6 + 3;
const int N = MOD + 5;
const int INV2 = 500002;

long long fact[N], inv[N];

long long power (long long a, long long n) {
	long long ret = 1, carry = a;
	
	while ( n ) {
		if (n & 1) ret = ret * carry % MOD;
		carry = carry * carry % MOD;
		n >>= 1;
	}
	
	return ret;
}

int main () {
	long long n, k;
	cin >> n >> k;
	
	if (n < 64 && (1LL << n) < k) {
		cout << "1 1\n";
		return 0;
	}
		
	int msb = floor (log2 (k));
	msb++;
	
//	if (n < 64) num_bit = __builtin_popcount ((1LL << n) - k);
	long long v2 = k - 1 + n - msb - 1 + __builtin_popcountll ((1LL << (msb + 1)) - k);
	
	if (k >= MOD) cout << power (power (2, k), n) * power (INV2, v2) % MOD << " " << power (power (2, k), n) * power (INV2, v2) % MOD << endl;
	else {
		long long ret = 1;
		long long twon = power (2, n);
		for (int i = 0; i < k; i++)
			ret = ret * (twon - i + MOD) % MOD;
		
		cout << (power (power (2, k), n) - ret + MOD) * power (INV2, v2) % MOD << " " << power (power (2, k), n) * power (INV2, v2) % MOD << endl;
	}
	
	return 0;
}