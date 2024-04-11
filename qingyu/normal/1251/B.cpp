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

int n;
char s[10005];

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
		
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		int total0 = 0, total1 = 0, size0 = 0, size1 = 0;
		for (int i = 1; i <= n; ++i) 
		{
			scanf("%s", s + 1);
			int len = strlen(s + 1);
			if (len & 1) ++size1; else ++size0;
			for (int i = 1; i <= len; ++i) 
			{
				if (s[i] == '0') ++total0;
				else ++total1;
			}
		}
		int cnt0 = total0, cnt1 = total1;
		cnt0 &= 1, cnt1 &= 1;
		if (size1 == 0)
		{
			if ((cnt0 == 0) && (cnt1 == 0)) printf("%d\n", n);
			else printf("%d\n", n - 1);
			continue;
		}
		size1 &= 1; 
		if (size1 == 1)
		{
			if ((cnt0 == 1) ^ (cnt1 == 1)) printf("%d\n", n);
			else printf("%d\n", n - 1);
			continue;
		}
		else
		{
			if ((cnt0 == 0) && (cnt1 == 0)) printf("%d\n", n);
			else if ((cnt1 == 1) && (cnt0 == 1)) printf("%d\n", n);
			else printf("%d\n", n - 1);
		}
	}
	return 0;	
}