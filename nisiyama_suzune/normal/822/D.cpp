#include <bits/stdc++.h>

const int MOD = 1E9 + 7;

std::vector <int> prime;
bool is_nonprime[5100000];
int f[5100000];

int main () {
	for (int i = 2; i <= 5000000; ++i) {
		if (!is_nonprime[i]) {
			prime.push_back (i);
			f[i] = 1LL * i * (i - 1) / 2 % MOD;
		}
		for (int j = 0; i * prime[j] <= 5000000 && j < prime.size (); ++j) {
			is_nonprime[i * prime[j]] = true;
			f[i * prime[j]] = (f[i] + (1LL * prime[j] * (prime[j] - 1) / 2 % MOD) * i % MOD) % MOD;
			if (i % prime[j] == 0) break;
		}
	}
	int T, L, R;
	scanf ("%d%d%d", &T, &L, &R);
	int mul = 1, ans = 0;
	for (int i = L; i <= R; ++i) {
//		printf ("%d\n", f[i]);
		ans = (ans + 1LL * mul * f[i] % MOD) % MOD;
		mul = (1LL * mul * T) % MOD;
	}
	printf ("%d\n", ans);
}