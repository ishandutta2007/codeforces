//wtf???
#pragma GCC optimize(3)
#include <bits/stdc++.h>

constexpr int N = 105;

int n, m, a[N][N];
bool rused[N], cused[N];

inline char nc()
{
	static char buf[1000000], *p1 = buf, *p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}

inline int read()
{
	int res = 0, neg = 1;
	char ch;
	do 
	{
		ch = nc();
		if (ch == '-') neg = -1;
	} while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = nc(); while (ch >= 48 && ch <= 57);
	return res * neg;
}

inline int chkr()
{
	for (int i = 1; i <= n; ++i)
	{
		int s = 0;
		for (int j = 1; j <= m; ++j)
			s += a[i][j];
		if (s < 0) return i;	
	}
	return 0;
}

inline int chkc()
{
	for (int j = 1; j <= m; ++j)
	{
		int s = 0;
		for (int i = 1; i <= n; ++i)
			s += a[i][j];
		if (s < 0) return j;	
	}
	return 0;
}

int main()
{
	n = read(), m = read();
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			a[i][j] = read();
	while (true)
	{
		int r_t = chkr();
		if (r_t != 0)
		{
			for (int j = 1; j <= m; ++j)
				a[r_t][j] = -a[r_t][j];
			rused[r_t] ^= 1;
		}
		else
		{
			int c_t = chkc();
			if (c_t != 0)
			{
				for (int i = 1; i <= n; ++i)
					a[i][c_t] = -a[i][c_t];
				cused[c_t] ^= 1;
			}
			else break;
		}
	}
	int rcnt = 0, ccnt =0 ;
	for (int i = 1; i <= 100; ++i)
	{
		if (rused[i]) ++rcnt; if (cused[i]) ++ccnt;
	}
	printf("%d ", rcnt);
	for (int i = 1; i <= 100; ++i)
		if (rused[i]) printf("%d ", i);
	printf("\n%d ", ccnt);
	for (int i = 1; i <= 100; ++i)
		if (cused[i]) printf("%d ", i);
	return 0;
}