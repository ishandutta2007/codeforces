//BY QINGYU~~~~
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <vector>

int a[100005];

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

int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
int lcm(int x, int y) { return x / gcd(x, y) * y; }

int main()
{
	int n = read();
	for (int i = 1; i <= n; ++i) a[i] = read();
	std::sort(a + 1, a + n + 1);
	int x = 1, y = a[n];
	for (int i = 1; i <= n; ++i)
	{
		if (y % a[i] != 0 || a[i] == a[i - 1])
		{
			x = lcm(x, a[i]);
		}
	}
	printf("%d %d", x, y);
	return 0;
}