// sto djq orz
#include <bits/stdc++.h>

int n, b[1005][1005];

std::pair<int, int> c[1005];

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
	do res = res * 10 + ch - 48, ch = nc(); while (ch >= 48 && ch <= 57);
	return res;
}

inline int trans(int k)
{
//	printf("trans(%d)=", k);
	if (k < 1) k += n + 1;
	if (k > n + 1) k -= n + 1;
//	printf("%d\n", k);
	return k;
}

int main()
{
	n = read();
	for (int i = 1; i <= n; ++i) c[i].first = read(), c[i].second = i;
	std::sort(c + 1, c + n + 1, std::greater<std::pair<int, int> >());
	for (int j = 1; j <= n; ++j)
	{
		//printf("filling %d\n", j);
		int x = n - j + 2;
		for (int k = x; k >= x - c[j].first + 1; --k)
		{
			b[j][trans(k)] = 1;
		}
	}
	printf("%d\n", n + 1);
	for (int i = 1; i <= n + 1; ++i)
	{
		static int x[1005];
		for (int j = 1; j <= n; ++j)
		{
			x[c[j].second] = b[j][i];
		}
		for (int j = 1; j <= n; ++j) printf("%d", x[j]);
		putchar('\n');
	}
	return 0;
}