#include <bits/stdc++.h>

typedef long long ll;
constexpr int N = 2e5 + 50;

int a[N];

inline char nc()
{
	static char buf[1000000], *p1 = buf, *p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}

inline ll read()
{
	ll res = 0;
	char ch;
	do ch = nc(); while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = nc(); while (ch >= 48 && ch <= 57);
	return res;
}

int main()
{
	int T = read();
	while (T--)
	{
		int n = read(), k = read(), t = 0;
		for (int i = 1; i <= n; ++i) a[i] = read() & 1;
		int s = 0;
		std::vector<int> v;
		for (int i = 1; i <= n; ++i)
		{
			s += a[i];
			if (s % 2 == 1 and k > 1)
			{
				--k;
				s = 0;
				v.push_back(i);
			}
		}
		if (s % 2 == 1) { --k; v.push_back(n); }
		if (k != 0) puts("NO");
		else
		{
			puts("YES");
			for (int i : v) printf("%d ", i);
			printf("\n");
		}
	}
	return 0;
}