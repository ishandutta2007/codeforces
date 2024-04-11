#include <bits/stdc++.h>

const int N = 1e6 + 50;
const int M = 5e5 + 50;

typedef long long ll;

int n;
ll f[N], b[N], d[N], max[N];

inline char nc()
{
	static char buf[1000000], *p1 = buf, *p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}
 
inline int read()
{
	int res = 0;
	char ch;
	do ch = nc(); while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = nc(); while (ch >= 48 && ch <= 57);
	return res;
}

int main()
{
	ll ans = 0;
	n = read();
	for (int i = 1; i <= n; ++i) b[i] = read(), d[i] = b[i] - i;
	for (int i = 1; i <= n; ++i)
	{
		f[i] = max[d[i] + M] + b[i];
		ans = std::max(ans, f[i]);
		max[d[i] + M] = std::max(max[d[i] + M], f[i]);
	}
	printf("%lld", ans);
}