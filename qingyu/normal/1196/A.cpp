#include <bits/stdc++.h>

typedef long long ll;
constexpr int N = 2e5 + 50;

inline char nc()
{
	static char buf[1000000], *p1 = buf, *p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}

inline ll read()
{
	ll res = 0;
	char ch;
	do ch = nc(); while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = nc(); while (ch >= 48 && ch <= 57);
	return res;
}

int main()
{
	int T = read();
	while (T--)
	{
		ll a = read(), b = read(), c = read();
		printf("%lld\n", (a + b + c) >> 1);
	}
	return 0;
}