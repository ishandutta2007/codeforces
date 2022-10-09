#include <bits/stdc++.h>

typedef long long ll;
constexpr int N = 3e5 + 50;

int n, m;
int a[N][9];

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


int ex[N * 10];
int ansi, ansj;

inline bool solve(int v)
{
	memset(ex, 0, sizeof ex);
	for (int i = 1; i <= n; ++i)
	{
		int data = 0;
		for (int j = 1; j <= m; ++j)
			if (a[i][j] >= v) data |= 1 << (j - 1);
		ex[data] = i;
	}
	for (int i = 0; i < (1 << (m)); ++i)
		for (int j = 0; j < (1 << (m)); ++j)
		{
			if ((i | j) == ((1 << (m)) - 1))
			{
				if (ex[i] && ex[j])
				{
					ansi = ex[i]; ansj = ex[j];
					return true;
				}
			}
		}
	return false;
}

int main()
{
	n = read(), m = read();
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			a[i][j] = read();
		}
	}
	int l = 0, r = 1e9, ans = 0;
	int Ai = 1, Aj = 1;
	while (l <= r)
	{
		int mid = l + r >> 1;
		if (solve(mid)) ans = mid, l = mid + 1, Ai = ansi, Aj = ansj;
		else r = mid - 1;
	}
	printf("%d %d", Ai, Aj);
	return 0;
}