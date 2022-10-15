#include <iostream>

using namespace std;

int const MOD = 1000000007;
int const N = 2345678;

int mul(int a, int b) {
	return (int) ((long long) a * b % MOD);
}

void add(int &a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
}

int modPow(int a, int b) {
	int ret = 1;
	while (b > 0) {
		if (b & 1) ret = mul(ret, a);
		a = mul(a, a);
		b >>= 1;
	}
	return ret;
}

int moe[N], np[N], p[N], f[N];

int main() {
	int n, k;
	cin >> k >> n;
	for (int i = 1; i <= n; i++) moe[i] = 1;
	for (int i = 2; i <= n; i++) {
		if (np[i]) continue;
		for (int j = i; j <= n; j += i) {
			np[j] = 1;
			moe[j] = -moe[j];
		}
	}
	for (int i = 2; i * i <= n; i++) {
		for (int j = i * i; j <= n; j += i * i) {
			moe[j] = 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		p[i] = modPow(i, k);
	}
	for (int i = n; i >= 1; i--) {
		add(p[i], MOD - p[i - 1]);
	}
	for (int d = 1; d <= n; d++) {
		if (moe[d] == 0) continue;
		bool neg = moe[d] < 0;
		for (int j = d, e = 1; j <= n; j += d, e++) {
			add(f[j], neg ? (MOD - p[e]) : p[e]);
		}
	}
	for (int i = 1; i <= n; i++) add(f[i], f[i - 1]);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		add(ans, (f[i] ^ i) % MOD);
		// printf("f[%d] = %d\n", i, f[i]);
	}
	cout << ans << endl;
}