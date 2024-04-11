#include <bits/stdc++.h>

constexpr int N = 5e5 + 50;
int n, a[N];

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
	n = read();
	if (n & 1)
	{
		puts("YES");
		int cnt = 0;
		for (int i = 1; i <= n; ++i) 
			if (i & 1) a[i] = ++cnt, a[i + n] = ++cnt;
			else a[i + n] = ++cnt, a[i] = ++cnt;
		for (int i = 1; i <= 2 * n; ++i) printf("%d ", a[i]);
	}
	else puts("NO");
	return 0;	
}