#include <bits/stdc++.h>
 
int n, m;
 
std::bitset<256> a[256];
std::bitset<256> r, c, ep;
 
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
 
inline bool solve()
{
	bool mixed = false;
	for (int i = 1; i <= n; ++i)
	{
		int c = a[i].count();
		if (c != 0 && c != m)
		{
			if (mixed == false) 
			{
				mixed = true;
				if (a[i][1] == 1) a[i].flip(), a[i] = a[i] & ep, r.flip(i);
				int j = 1;
				for (j = 1; j <= m; ++j) if (a[i][j]) break;
				for (; j <= m; ++j) if (!a[i][j]) return false;
			}
			else return false;
		}
		else if (mixed == (c != m)) a[i].flip(), r.flip(i), a[i] = a[i] & ep;
	}
	return true;
}
 
inline void output()
{
	puts("YES");
	for (int i = 1; i <= n; ++i) putchar(r[i] + 48);
	putchar('\n');
	for (int i = 1; i <= m; ++i) putchar(c[i] + 48);
}
 
int main()
{
	n = read(), m = read();
	for (int i = 1; i <= m; ++i) ep[i] = 1;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			a[i][j] = read();
		}
	}
	for (int i = 1; i <= m; ++i) if (a[1][i]) { c.flip(i); for (int j = 1; j <= n; ++j) a[j].flip(i); }
	if (solve()) return output(), 0;
	for (int i = 1; i <= m; ++i) if(!a[n][i]) { c.flip(i); for (int j = 1; j <= n; ++j) a[j].flip(i); }
	if (solve()) return output(), 0;
	puts("NO");
	return 0;
}