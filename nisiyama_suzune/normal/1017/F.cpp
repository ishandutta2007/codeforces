#include <bits/stdc++.h>

unsigned long long N, aa, bb, cc, dd;

template <int SN = 21000, int D = 3>
struct ees {
	int co[SN], prime[SN], psize, sn;
	unsigned long long powa[D + 1][SN], powb[D + 1][SN];
	unsigned long long funca[SN], funcb[SN];
	unsigned long long pow (unsigned long long x, int n) {
		unsigned long long res = 1;
		for (int i = 0; i < n; ++i) res *= x;
		return res; }
//	computes sum of powers.
	unsigned long long pre_pow (unsigned long long x, int n) {
		if (n == 0) return x;
		if (n == 1) return (1 + x) * x / 2;
		if (n == 2) return (1 + 2 * x) * (1 + x) * x * 2863311531 / 2;
		if (n == 3) return (x * (x + 1) / 2) * (x * (x + 1) / 2);
		return 0; }
//	returns f(p) when p is prime.
	unsigned long long pfunc (unsigned long long p) { return aa * p * p * p + bb * p * p + cc * p + dd; }
//	returns f(k * p) when a prime p divides k.
	unsigned long long cfunc (unsigned long long k, unsigned long long p) { return k + pfunc (p); }
//	computes funca[i] (funcb[i]) with powa[d][i] (powb[d][i]).
	void assemble () {
		for (int i = 1; i <= sn; ++i) {
			funca[i] = aa * powa[3][i] + bb * powa[2][i] + cc * powa[1][i] + dd * powa[0][i];
			funcb[i] = aa * powb[3][i] + bb * powb[2][i] + cc * powb[1][i] + dd * powb[0][i]; } }
	void init (unsigned long long n) {
		sn = std::max ((int) (ceil (sqrt (n)) + 1), 2);
		psize = 0; for (int i = 2; i <= sn; ++i) {
			if (!co[i]) prime[psize++] = i;
			for (int j = 0; 1LL * i * prime[j] <= sn; ++j) {
				co[i * prime[j]] = 1;
				if (i % prime[j] == 0) break; } }
		for (int d = 0; d <= D; ++d) {
			unsigned long long *pa = powa[d], *pb = powb[d];
			for (int i = 1; i <= sn; ++i) pa[i] = pre_pow (i, d) - 1; 
			for (int i = 1; i <= sn; ++i) pb[i] = pre_pow (n / i, d) - 1;
			for (int i = 0; i < psize; ++i) { int &pi = prime[i];
				for (int j = 1; j <= sn; ++j) if (n / j >= 1LL * pi * pi) {
					unsigned long long ch = n / j / pi;
					pb[j] -= ((ch <= sn ? pa[ch] : pb[j * pi]) - pa[pi - 1]) * pow (pi, d);
				} else break;
				for (int j = sn; j >= 1; --j) if (j >= 1LL * pi * pi)
					pa[j] -= (pa[j / pi] - pa[pi - 1]) * pow (pi, d);
				else break; } }
		assemble (); }
	void dfs (int x, int f, unsigned long long mul, unsigned long long val, unsigned long long n, unsigned long long &res) {
//		std::cout << x << " " << f << " " << mul << " " << val << " " << n << " " << res << "\n";
		for (; x < psize && mul * prime[x] * prime[x] <= n; ++x) {
			unsigned long long nmul = mul * prime[x], nval = val + pfunc (prime[x]);
			for (; nmul <= n; nmul *= prime[x], nval = cfunc (nval, prime[x]))
				dfs (x + 1, prime[x], nmul, nval, n, res); }
//		if (n / mul > f)
//			std::cout << "Kill " << val << " " << ((n / mul <= sn ? funca[n / mul] : funcb[mul]) - funca[f])<< "\n";
		if (n / mul > f)
			res += val * ((n / mul <= sn ? powa[0][n / mul] : powb[0][mul]) - powa[0][f]) + ((n / mul <= sn ? funca[n / mul] : funcb[mul]) - funca[f]);
//		std::cout << "Fuck " << f << " " << mul << " " << val << "\n";
		if (f > 1 && mul % (f * f) == 0) res += val; }
	unsigned long long solve (unsigned long long n) {
		if (n == 0) return 0;
		unsigned long long res = 0;
		init (n); dfs (0, 1, 1, 0, n, res);
		return res; } };

ees <> e;

int main () {
	std::ios::sync_with_stdio (0);
	std::cin >> N >> aa >> bb >> cc >> dd;
	std::cout << (e.solve (N) & (1ull << 32) - 1) << "\n";
	return 0;
}