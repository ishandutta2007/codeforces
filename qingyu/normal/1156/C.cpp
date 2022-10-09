// By Qingyu
#include <bits/stdc++.h>

const int N = 5e5 + 50;
int n, z, a[N];

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

inline bool check(int mid)
{
	for (int i = 1; i <= mid; ++i)
		if (a[n - mid + i] - a[i] < z) return false;
	return true;
}

int main()
{
	n = read(), z = read();
	for (int i = 1; i <= n; ++i) a[i] = read();
	std::sort(a + 1, a + n + 1);
	int l = 1, r = n / 2, ans = 0;
	while (l <= r)
	{
		const int mid = l + r >> 1;
		if (check(mid)) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	printf("%d", ans);
	return 0;
}