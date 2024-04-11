// By Qingyu
#include <bits/stdc++.h>

const int N = 1e5 + 50;
int n, m;

inline char nc()
{
	static char buf[1000000], *p1 = buf, *p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}

inline int read()
{
	int res = 0, neg = 1; char ch; 
	do 
	{
		ch = nc();
		if (ch == '-') neg = -1;
	} while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = nc(); while (ch >= 48 && ch <= 57);
	return res * neg;
}

char a[N], b[N], c[N];

inline void op(int n)
{
	for (int i = 1; i <= n; ++i) a[i] ^= 1;
	for (int i = 1; i <= n; ++i) c[i] = a[i];
	for (int i = 1; i <= n; ++i) a[i] = c[n - i + 1];
}

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d%s%s", &n, a + 1, b + 1);
		for (int i = 1; i <= n; ++i) a[i] -= 48, b[i] -= 48;
		std::vector<int> vec;
		for (int i = n; i >= 2; --i)
		{
			if (a[i] != b[i])
			{
				if (a[1] != a[i]) vec.emplace_back(1), op(1);
				vec.emplace_back(i); op(i);
			}
		}
		if (a[1] != b[1]) vec.emplace_back(1), op(1);
		printf("%d\n", vec.size());
		for (auto x : vec)
		{
			printf("%d\n", x);
		}
	}
	return 0;
}