#pragma GCC optimize("Ofast")
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <cassert>
#include <map>
#include <stack>

inline char nc()
{
	static char buf[1000000], *p1 = buf, *p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;	
}

inline int read()
{
	int res = 0;
	char ch;
	do ch = nc(); while (ch < 48 or ch > 57);
	do res = res * 10 + ch - 48, ch = nc(); while (ch >= 48 and ch <= 57);
	return res;
}

char s[1000005];

		int buc[27];
		
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%s", s);
		int len = strlen(s);
		int p = 0, last = -1;
		memset(buc, 0, sizeof buc);
		for (int i = 0; i < len; ++i)
		{
			++p;
			if (s[i] != s[i + 1])
			{
				if (p & 1) 
				{
					buc[s[i] - 'a'] = 1;
				}
				p = 0;
			}
		}
		for (int i = 0; i < 27; ++i)
			if (buc[i])
				putchar(i + 'a');
		putchar('\n');
	}
	return 0;	
}