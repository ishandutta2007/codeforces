#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000, mod = 1000000007, inv2 = (mod + 1) / 2;
int n, k, stk[maxn + 10], scnt, a[maxn + 10], l[maxn + 10], r[maxn + 10], ans;

int sum(int l, int r) {
	if (l > r) return 0;
	return 1ll * (l + r) * (r - l + 1) % mod * inv2 % mod;
}

int getcnt(int l, int r, int re) {
	int m = k - 1;
	re = (re % m + m) % m;
	if (l % m <= re) l += re - l % m;
	else l = (l / m + 1) * m + re;
	if (r % m >= re) r -= r % m - re;
	else r = (r / m - 1) * m + re;
	if (l > r) return 0;
	return (r - l) / m + 1;
}

int getsum(int l, int r, int re) {
	int m = k - 1;
	re = (re % m + m) % m;
	if (l % m <= re) l += re - l % m;
	else l = (l / m + 1) * m + re;
	if (r % m >= re) r -= r % m - re;
	else r = (r / m - 1) * m + re;
	if (l > r) return 0;
	return 1ll * (r + l) * getcnt(l, r, re) % mod * inv2 % mod;
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i) {
		while (scnt && a[stk[scnt]] < a[i]) --scnt;
		l[i] = stk[scnt]; stk[++scnt] = i;
	}
	stk[scnt = 0] = n + 1;
	for (int i = n; i >= 1; --i) {
		while (scnt && a[stk[scnt]] <= a[i]) --scnt;
		r[i] = stk[scnt]; stk[++scnt] = i;
	}
	for (int i = 1; i <= n; ++i) {
		int len1 = i - l[i], len2 = r[i] - i, upper = len1 + len2 - 1;
		int tot = 1ll * getcnt(max(len1 + 1, k), upper, 1) * len1 % mod + getsum(k, min(len1, upper), 1);
		tot -= getsum(max(k - len2, 0), upper - len2, 1 - len2);
		tot = (tot % mod + mod) % mod;
		tot %= mod;
		ans = (ans + 1ll * tot * a[i] % mod) % mod;
	}
	printf("%d", ans);
}