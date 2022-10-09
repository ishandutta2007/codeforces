#include <bits/stdc++.h>

typedef long long ll;
constexpr int N = 5e5 + 50;

ll m, n, a[N], b[N], sum1, sum2;

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
	n = read(); for (int i = 1; i <= n; ++i) a[i] = read(), sum1 += a[i];
	m = read(); for (int i = 1; i <= m; ++i) b[i] = read(), sum2 += b[i]; 
	if (sum1 != sum2) return printf("-1"), 0;
	ll ans = 0, p1 = 0, p2 = 0; sum1 = sum2 = 0;
	ll *A = a, *B = b;
	while (true)
	{
		//printf("sum1 = %lld, sum2 = %lld, p1 = %lld, p2 = %lld, n = %lld, m = %lld\n", sum1, sum2, p1, p2, n, m);
		if (sum1 > sum2)
		{
			std::swap(p1, p2);
			std::swap(sum1, sum2);
			std::swap(n, m);
			std::swap(A, B);
		}
		do
		{
			if (p1 >= n) return printf("-1"), 0;
			sum1 += A[++p1];
		} while (sum1 < sum2);
		if (sum1 == sum2)
		{
			++ans;
			sum1 = sum2 = 0;
			if (p1 == n && p2 == m) return printf("%lld", ans), 0;
		}
	}
	return 0;	
}