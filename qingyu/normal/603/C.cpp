#include <bits/stdc++.h>

int n, k, sg_v;


inline int SG(int x)
{
	if (x == 0) return 0;
	if (x == 1) return 1;
	if (k & 1)
	{
		if (x == 2) return 0;
		if (x == 3) return 1;
		if (x == 4) return 2;
		if (x & 1) return 0;
		int t = SG(x >> 1);
		return t > 1 ? 1 : t + 1;
	}
	else
	{
		if (x == 2) return 2;
		return ((x ^ 1) & 1);
	}
}

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
	n = read(), k = read();
	while (n--) sg_v ^= SG(read());
	puts(sg_v ? "Kevin" : "Nicky");
	return 0;
}