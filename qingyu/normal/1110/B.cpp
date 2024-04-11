//Qingyu
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <cctype>
#include <cstdlib>

std::priority_queue<int> Q;
int a[200005];

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
	long long ans = 0;
	int n = read(), m = read(), k = read();
	for (int i = 1; i <= k; ++i)
	{
		a[i] = read();
		if (i != 1) Q.push(-a[i] + a[i - 1]);
		++ans;
	}
	for (int i = k + 1; i <= n; ++i)
	{
		a[i] = read();
		Q.push(-a[i] + a[i - 1]);
		int y = -Q.top(); Q.pop();
		ans += y;
	}
	printf("%lld", ans);
}