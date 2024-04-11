#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <cctype>
#include <string>

constexpr int N = 1e6 + 50;
int a[N];

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
	long long n = read(), m = read(), k = read();
	for (int i = 1; i <= n; ++i)
	{
		a[i] = read();
	}
	std::sort(a + 1, a + n + 1, std::greater<int>());
	long long ans = 0;
	ans += m / (k + 1) * (k * a[1] + a[2]);
	long long res = m - (k + 1) * (m / (k + 1));
	ans += res * a[1];
	printf("%lld", ans);
	return 0;
}