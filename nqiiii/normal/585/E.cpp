#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7, mod = 1e9 + 7;
int n, s[maxn + 10], mu[maxn + 10], pw[maxn + 10];
int ans;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int x; scanf("%d", &x);
		++s[x];
	}
	for (int i = 1; i <= maxn; ++i)
		for (int j = i + i; j <= maxn; j += i)
			s[i] += s[j];
	mu[1] = 1;
	for (int i = 1; i <= maxn; ++i)
		for (int j = i + i; j <= maxn; j += i)
			mu[j] -= mu[i];
	pw[0] = 1;
	for (int i = 1; i <= n; ++i) pw[i] = pw[i - 1] * 2 % mod;
	for (int i = 2; i <= maxn; ++i)
		if (mu[i]) {
			int v = 1ll * (pw[s[i]] - 1) * (n - s[i]) % mod;
			if (mu[i] == -1) ans = (ans + v) % mod;
			else ans = (ans + mod - v) % mod;
		}
	printf("%d", ans);
}