#include <bits/stdc++.h>
using namespace std;
const int maxn = 5000, mod = 998244353;
int n, a[maxn + 10], w[maxn + 10];
int ans, f[maxn + 10];

inline int add(int x, int y) {
	x += y; return x < mod ? x : x - mod;
}
inline int mul(int x, int y) {
	return 1ll * x * y % mod;
}
inline int fpow(int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1) ans = mul(ans, x);
		y >>= 1; x = mul(x, x);
	}
	return ans;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int x; scanf("%d", &x);
		++a[x];
	}
	w[0] = f[0] = 1;
	for (int i = 1; i <= n; ++i) 
		w[i] = mul(w[i - 1], fpow(n - i + 1, mod - 2));
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= n; ++j)
			ans = add(ans, mul(mul(w[j + 2], f[j]), mul(a[i], a[i] - 1)));
		for (int j = n; j >= 0; --j)
				f[j] = add(f[j], mul(f[j - 1], a[i]));
	}
	printf("%d", ans);
}