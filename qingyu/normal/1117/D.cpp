#pragma GCC optimize(3)
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <cctype>
#include <string>
using namespace std;
inline long long read() {
	char ch = getchar(); long long i = 0, f = 1;
	while (!isdigit(ch)) { if (ch == '-')f = -1; ch = getchar(); }
	while (isdigit(ch)) { i = (i << 1) + (i << 3) + ch - '0'; ch = getchar(); }
	return i * f;
}
const long long Maxn = 2e3 + 20, Mod = 1000000007;
#define rg register 
long long n, k, a[Maxn << 1], b[Maxn << 1], c[Maxn << 1], h[Maxn], tp[Maxn << 1], ans, lim;
inline void add(long long &x, long long y) {
	x += y; (x > Mod ? x -= Mod : (x < 0 ? x += Mod : 0));
}
inline void mul(long long *A, long long *B) {
	for (rg long long i = 0; i <= lim; i++)tp[i] = 0;
	for (rg long long i = 0; i <= k; i++)
		for (rg long long j = 0; j <= k; j++)
			tp[i + j] = (tp[i + j] + 1ll * A[i] * B[j]) % Mod;
	for (rg long long i = lim; i >= k; i--) {
		for (rg long long j = 0; j < k; j++)
			tp[i - k + j] = (tp[i - k + j] + 1ll * tp[i] * a[k - j]) % Mod;
		tp[i] = 0;
	}
	for (long long i = 0; i <= lim; i++)A[i] = tp[i];
}
inline void power(long long *A, long long B, long long *C) {
	for (; B; B >>= 1, mul(A, A))if (B & 1)mul(C, A);
}
int main() {
	n = read(), k = read(); lim = k << 1;
	a[1] = a[k] = 1;
	for (long long i = 1; i <= k; i++)h[i] = 1;
	if (n < k) { printf("%lld\n", h[n + 1]); return 0; }
	b[0] = 1; c[1] = 1; power(c, n, b);
	for (long long i = 0; i < k; i++)add(ans, 1ll * b[i] * h[i + 1] % Mod);
	printf("%lld\n", ans);
}