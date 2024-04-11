#include <bits/stdc++.h>

const int N = 1005;

int a[N], b[N];
bool v[N];

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
	int t = read();
	while (t--)
	{
		int n = read(), m = read(), e = -1;
		for (int i = 1; i <= n; ++i) a[i] = read(), v[a[i]] = true;
		for (int i = 1; i <= m; ++i)
		{
			b[i] = read();
			if (v[b[i]]) e = b[i];
		}
		for (int i = 1; i <= n; ++i) v[a[i]] = false;
		if (e == -1) puts("NO");
		else
		{
			printf("YES\n1 %d\n", e);
		}
	}
	return 0;
}