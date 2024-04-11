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

constexpr int N = 5e5 + 50;
int n, buc[25], oldbuc[25], q0[N], q1[N], ptr0, ptr1;
int tag[N];
char s[600005];

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
		scanf("%s", s + 1); n = strlen(s + 1);
		ptr0 = ptr1 = 0;
		for (int i = 1; i <= n; ++i) tag[i] = 0;
		for (int i = 1; i <= n; ++i) s[i] -= 48;
		for (int i = 1; i <= n; ++i)
		{
			if ((s[i] & 1) == 0) q0[++ptr0] = i;
			else q1[++ptr1] = i;
		}
		int l0 = 1, l1 = 1;
		for (int i = 1; i <= n; ++i)
		{
			if (tag[i] == false)
			{
				tag[i] = true;
				if (s[i] & 1)
				{
					while ((l0 <= ptr0) && (s[q0[l0]] <= s[i]))
					{
						if (tag[q0[l0]]) { ++l0; continue;}
						putchar(s[q0[l0]] + 48);
						tag[q0[l0]] = true;
						++l0;
					}
					putchar(s[i] + 48);
				}
				else
				{
					while ((l1 <= ptr1) && (s[q1[l1]] <= s[i]))
					{
						if (tag[q1[l1]]) { ++l1; continue; }
						putchar(s[q1[l1]] + 48);
						tag[q1[l1]] = true;
						++l1;
					}
					putchar(s[i] + 48);
				}
			}
		}
		putchar('\n');
	}
	return 0;	
}