#include <cstdio>

typedef long long LL;

const int N = 1000000; 
const int MOD = 1000000007;

LL power (LL x, int y) {
	LL mul = x;
	LL ret = 1;
	while (y) {
		if (y & 1) ret *= mul, ret %= MOD;
		
		mul *= mul;
		mul %= MOD;
		y >>= 1;
	}
	
	return ret;
}

int y[N + 2];

int main() {
	int n, k;
	scanf ("%d %d", &n, &k);
	
	for (int i=1; i<k+2; i++)
		y[i] = (y[i-1] + power (i, k)) % MOD;
		
	if (n < k + 2) return 0 * printf ("%d\n", y[n]);
	
	LL prod = 1;
	for (int i=0; i<k+2; i++) 
		prod *= (n - i), 
		prod %= MOD;
		
	LL fact = 1;
	for (int i=1; i<k+2; i++)
		fact *= power (i, MOD - 2),
		fact %= MOD;
	
	LL sum = 0;
	for (int i=0; i<k+2; i++) {
		sum += prod * power (n - i, MOD - 2) % MOD * y[i] % MOD * fact * (k - i & 1 ? 1 : -1);
		sum %= MOD;
		
		fact *= (k + 1 - i);
		fact %= MOD;
		
		fact *= power (i + 1, MOD - 2);
		fact %= MOD;
	}
	
	if (sum < 0) sum += MOD;
	printf ("%I64d\n", sum);
	
	return 0;
}