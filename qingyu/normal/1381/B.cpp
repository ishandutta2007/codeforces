#include <bits/stdc++.h>

inline char nc()
{
	static char buf[1000000], *p1 = buf, *p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}

inline int read()
{
	int res = 0, neg = 1; char ch; 
	do 
	{
		ch = nc();
		if (ch == '-') neg = -1;
	} while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = nc(); while (ch >= 48 && ch <= 57);
	return res * neg;
}

int a[50000], w[50005], cnt, f[50005];
bool bs[5000];

int main()
{
	int T = read();
	while (T--)
	{
		int n = read();
		cnt = 0;
		for (int i = 1; i <= 2 * n; ++i) a[i] = read();
		int max = 0, len = 0;
		for (int i = 1; i <= n; ++i) bs[i] = false;
		bs[0] = true;
		for (int i = 1; i <= 2 * n; ++i)
		{
			if (a[i] > max)
			{
				max = a[i];
				w[++cnt] = len;
				len = 0;
			}
			++len;
		}
		w[++cnt] = len, len = 0;
		for (int i = 1; i <= cnt; ++i)
			for (int j = n; j >= w[i]; --j)
				bs[j] |= bs[j - w[i]];
		puts(bs[n] ? "YES" : "NO");
	}
	return 0;
}
// By Qingyu