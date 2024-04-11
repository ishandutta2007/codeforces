#include <bits/stdc++.h>

const int N = 1e6 + 50;

long long a[N];

inline char nc()
{
    static char buf[1000000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}

inline long long read()
{
    long long res = 0;
    char ch;
    do ch = nc(); while (ch < 48 || ch > 57);
    do res = res * 10 + ch - 48, ch = nc(); while (ch >= 48 && ch <= 57);
    return res;
}

int main()
{
	long long n = read(), k = read(), m = read();
	for (int i = 1; i <= n; ++i) a[i] = read();
	std::sort(a + 1, a + n + 1, std::greater<int>());
	long long S = 0;
	long double ans = -1;
	for (int i = 1; i <= n; ++i)
	{
		S += a[i];
		if (n - i <= m) 
		{
			ans = std::max(ans, (long double)(S + std::min(m - n + i, i * k)) / i);
			//printf("%.12Lf\n", ans);
		}
	}
	printf("%.12Lf", ans);
	return 0;	
}