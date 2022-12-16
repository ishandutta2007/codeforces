#include <bits/stdc++.h>

int fpm (int x, int n, int mod) {
	int ans = 1, mul = x; while (n) {
		if (n & 1) ans = int (1ll * ans * mul % mod);
		mul = int (1ll * mul * mul % mod); n >>= 1; }
	return ans; }
long long mul_mod (long long x, long long y, long long mod) {
	long long t = (x * y - (long long) ((long double) x / mod * y + 1E-3) * mod) % mod;
	return t < 0 ? t + mod : t; }
long long llfpm (long long x, long long n, long long mod) {
	long long ans = 1, mul = x; while (n) {
		if (n & 1) ans = mul_mod (ans, mul, mod);
		mul = mul_mod (mul, mul, mod); n >>= 1; }
	return ans; }

struct miller_rabin {
	int BASE[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
	bool check (const long long &p, const long long &b) {
		long long n = p - 1;
		for (; ~n & 1; n >>= 1);
		long long res = llfpm (b, n, p);
		for (; n != p - 1 && res != 1 && res != p - 1; n <<= 1)
			res = mul_mod (res, res, p);
		return res == p - 1 || (n & 1) == 1; }
	bool solve (const long long &n) {
		if (n < 2) return false;
		if (n < 4) return true;
		if (~n & 1) return false;
		for (int i = 0; i < 12 && BASE[i] < n; ++i) if (!check (n, BASE[i])) return false;
		return true; } } mr;

int main () {
	int T; scanf ("%d", &T); while (T--) {
		long long a, b; scanf ("%lld%lld", &a, &b);
		if (a - b == 1 && mr.solve (a + b)) puts ("YES");
		else puts ("NO");
	}
}