#include <bits/stdc++.h>

const int N = 1e5 + 50;
typedef long long ll;

int n;
ll a[N];

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

int main()
{
	n = read();
	for (int i = 1; i <= n; ++i) a[i] = read();
	if (n == 1)
	{
		printf("1 1\n%d\n", -a[1]);
		printf("1 1\n0\n");
		printf("1 1\n0\n");
	}
	else
	{
		printf("1 %d\n", n - 1);
		for (int i = 1; i <= n - 1; ++i)
		{
			ll v = (a[i] % n) * (n - 1);
			a[i] += v;
			printf("%lld ", v);
		}
		putchar('\n');
		printf("%d %d\n", n, n);
		printf("%d\n", -a[n]); a[n] = 0;
		printf("1 %d\n", n);
		for (int i = 1; i <= n; ++i)
		{
			printf("%lld ", -a[i]);
		}
	}
}
// By Qingyu