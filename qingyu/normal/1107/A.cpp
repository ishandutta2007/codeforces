//qwq aa
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <map>
#include <cctype>
#include <iostream>

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

char s[10005];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		if (n > 2)
		{
			scanf("%s", s);
			puts("YES");
			puts("2");
			putchar(s[0]);
			putchar(' ');
			for (int i = 1; i < n; ++i) putchar(s[i]);
			putchar('\n');
		}
		else if (n == 2)
		{
			scanf("%s", s);
			if (s[1] > s[0])
			{
				puts("YES");
				puts("2");
				putchar(s[0]);
				putchar(' ');
				putchar(s[1]);
				putchar('\n');
			}
			else puts("NO");
		}
		else puts("NO");
	}
	return 0;
}