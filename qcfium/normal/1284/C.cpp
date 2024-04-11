#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

int main() {
	int n = ri();
	int mod = ri();
	
	static int fact[250001];
	fact[0] = 1;
	for (int i = 1; i <= 250000; i++) fact[i] = (int64_t) fact[i - 1] * i % mod;
	
	int res = 0;
	for (int i = 1; i <= n; i++) {
		int num = (n - i + 1);
		res += (int64_t) num * num % mod * fact[i] % mod * fact[n - i] % mod;
		if (res >= mod) res -= mod;
	}
	std::cout << res << std::endl;
	return 0;
}