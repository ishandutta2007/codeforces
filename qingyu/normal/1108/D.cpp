#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <vector>

char s[300005];
int f[300005][4], pre[300005][4];

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

inline char dec(int j) 
{ 
	if (j == 0) return 'R';
	if (j == 1) return 'G';
	return 'B';
}

void output(int i, int j)
{
	if (pre[i][j] != 0)
	{
		output(i - 1, pre[i][j] - 1);
		putchar(dec(j));
	}
}

int main()
{
	int n;
	scanf("%d%s", &n, s + 1);
	for (int i = 1; i <= n; ++i)
		if (s[i] == 'R') s[i] = 0;
		else if (s[i] == 'G') s[i] = 1;
		else s[i] = 2;
	memset(f, 0x3f, sizeof f);
	f[0][0] = f[0][1] = f[0][2] = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (f[i - 1][(j + 1) % 3] < f[i - 1][(j + 2) % 3])
			{
				f[i][j] = f[i - 1][(j + 1) % 3];
				pre[i][j] = (j + 1) % 3 + 1;
			}
			else
			{
				f[i][j] = f[i - 1][(j + 2) % 3];
				pre[i][j] = (j + 2) % 3 + 1;
			}
			if (s[i] != j) f[i][j]++;
		}
	}
	int g = -1;
	if (f[n][0] < f[n][1])
	{
		if (f[n][2] < f[n][0]) g = 2;
		else g = 0;
	}
	else
	{
		if (f[n][2] < f[n][1]) g = 2;
		else g = 1;
	}
	printf("%d\n", f[n][g]);
	output(n, g);
	return 0;
}