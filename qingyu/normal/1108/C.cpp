#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <vector>

char s[300005], t[300005], ans[300005];
char q[4] = "RGB";
char r[4] = "RBG";


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
	int n;
	scanf("%d%s", &n, s);
	int mindis = 0x3f3f3f3f;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < n; ++j) t[j] = q[(j + i) % 3];
		int dis = 0;
		for (int j = 0; j < n; ++j)
			if (s[j] != t[j]) ++dis;
		if (mindis > dis)
		{
			mindis = dis;
			memcpy(ans, t, sizeof t);
		}
	}
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < n; ++j) t[j] = r[(j + i) % 3];
		int dis = 0;
		for (int j = 0; j < n; ++j)
			if (s[j] != t[j]) ++dis;
		if (mindis > dis)
		{
			mindis = dis;
			memcpy(ans, t, sizeof t);
		}
	}
	printf("%d\n%s", mindis, ans);
}