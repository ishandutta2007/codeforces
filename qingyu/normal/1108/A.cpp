//By Qingyu qwq! hhh
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <vector>

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
	int T = read();
	while (T--)
	{
		int l1 = read(), r1 = read(), l2 = read(), r2 = read();
		if (l1 <= l2) printf("%d %d\n", l1, r2);
		else printf("%d %d\n", l1, l2);
	}
	return 0;
	return 0;
}