#include <bits/stdc++.h>

const int N = 1e5 + 50;
typedef long long ll;

int n, a[N];

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
	int t = read();
	while (t--)
	{
		n = read();
		int sum = 0, max = 0;
		for (int i = 1; i <= n; ++i) 
		{
			a[i] = read();
			sum += a[i];
			max = std::max(max, a[i]);
		}
		if (max > sum - max)
		{
			puts("T");
		}
		else
		{
			puts((sum & 1) ? "T" : "HL");
		}
	}
}