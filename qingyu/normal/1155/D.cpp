// By Qingyu
#include <bits/stdc++.h>

typedef long long ll;

inline char nc()
{
	static char buf[1000000], *p1 = buf, *p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}

inline ll read()
{
	ll res = 0, neg = 1;
	char ch;
	do
	{
		ch = nc();
		if (ch == '-') neg = -1;
	} while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = nc(); while (ch >= 48 && ch <= 57);
	return res * neg;
}

int main()
{
	ll n = read(), z = read(), dp0 = 0, dp1 = 0, dp2 = 0, dp3 = 0;
	for (int i = 1; i <= n; ++i)
	{
		ll x = read();
		dp0 = std::max(0LL, dp0 + x);
		dp1 = std::max(dp0, dp1 + x * z);
		dp2 = std::max(dp1, dp2 + x);
		dp3 = std::max(dp2, dp3);	
	}
	printf("%lld", dp3);
	return 0;
}