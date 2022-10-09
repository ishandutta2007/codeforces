// By Qingyu
#include <bits/stdc++.h>

typedef long double ld;
const int N = 1e6 + 50;

ld fact[N], ans;
int n, m, k;

inline ld C(int x, int y) { return fact[x] - fact[y] - fact[x - y]; }

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; ++i) fact[i] = fact[i - 1] + logl(1.0L * i);
	for (int i = 0; i <= n && ans <= 1e99; ++i) for (int j = 0; j <= n && ans <= 1e99; ++j)
	{
		int t = (i + j) * n - i * j;
		if (t > k) break;
		ans += exp(C(n, i) + C(n, j) + C(k, t) - C(m, t));
	}
	if (ans >= 1e99) puts("1e99");
	else
	{
		double a = ans;
		printf("%.12f", a);
	}
}