#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

namespace MOD {
	const int P = 998244353;
	inline int add(int x, int y) {return x + y >= P ? x + y - P : x + y;}
	inline int sub(int x, int y) {return x < y ? x - y + P : x - y;}
	inline int mul(int x, int y) {return (long long)x * y % P;}
	inline void inc(int &x, int y) {x = add(x, y);}
	inline void dec(int &x, int y) {x = sub(x, y);}
	inline void upd(int &x, int y) {x = mul(x, y);}
	inline int Pow(int x, int y) {int r = 1; for (; y; y >>= 1, x = mul(x, x)) if (y & 1) r = mul(r, x); return r;}
};
using namespace MOD;

const int N = 5010;

int n, a[N], pw[N], ipw[N], f[N], g[N], s[N];

int C(int x, int y) {
	if (y < 0 || x < y) return 0;
	return mul(pw[x], mul(ipw[y], ipw[x - y]));
}

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort (a + 1, a + n + 1);
	if (a[n] == a[n - 1]) return puts("0"), void();
	n--;
	if (n == 1) return puts("1"), void();
	for (int i = 0; i <= n; i++) f[i] = 0;
	f[0] = 1; int ans = 0;
	for (int i = 1, ml = 1; i <= n; ) {
		int c = 1; i++;
		while (i <= n && a[i - 1] == a[i]) i++, c++;
		ml = mul(ml, ipw[c]);
		s[i - 1] = mul(pw[i - 1], ml);
	}
	for (int i = n; i >= 1; i--) {
		int j = i;
		while (i - 1 >= 1 && a[i - 1] == a[j]) i--;
		int c = j - i + 1;
		for (int j = 0; j <= n; j++) g[j] = 0;
		for (int j = n; j >= c; j--) g[j - c] = mul(f[j], C(j, c));
		for (int j = n; j >= c - 1; j--) {
			if (j - (c - 1) + 2 == i - 1)
				inc(ans, mul(f[j], mul(C(j, c - 1), s[i - 1])));
			else inc(g[j - (c - 1) + 1], mul(f[j], C(j, c - 1)));
		}
		swap(f, g);
	}
	printf("%d\n", ans);
}

int T;

int main() {
	pw[0] = ipw[0] = 1;
	for (int i = 1; i <= 5000; i++)
		pw[i] = mul(pw[i - 1], i);
	ipw[5000] = Pow(pw[5000], P - 2);
	for (int i = 4999; i >= 1; i--)
		ipw[i] = mul(ipw[i + 1], i + 1);
	for (scanf("%d", &T); T; T--) solve();
	return 0;
}