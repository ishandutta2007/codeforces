// by qingyu
#include <bits/stdc++.h>

typedef long long ll;
const int N = 1e4 + 50;

int n, x[N], y[N], d[N];
bool ban[N];

inline ll cross(ll x1, ll y1, ll x2, ll y2)
{
	return x1 * y2 - y1 * x2;
}

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

inline int rop()
{
	char ch;
	do ch = nc(); while (ch != 'L' && ch != 'R');
	return ch == 'R';
}

int main()
{
	n = read();
	int p = 1;
	for (int i = 1; i <= n; ++i)
	{
		x[i] = read(), y[i] = read();
		if (x[p] > x[i] || (x[p] == x[i] && y[p] > y[i]))
		{
			p = i;
		}
	}
	for (int i = 1; i < n - 1; ++i) d[i] = rop();
	for (int i = 1; i <= n; ++i)
	{
		ban[p] = true; printf("%d ", p);
		int pl = -1, pr = -1;
		for (int j = 1; j <= n; ++j) if (!ban[j])
		{
			if (pl == -1)
			{
				pl = pr = j;
			}
			else
			{
				if (cross(x[pl] - x[p], y[pl] - y[p], x[j] - x[p], y[j] - y[p]) > 0) pl = j;
				if (cross(x[pr] - x[p], y[pr] - y[p], x[j] - x[p], y[j] - y[p]) < 0) pr = j;
			}
		}
		if (d[i] == 0) p = pr;
		else p = pl;
	}
	return 0;
}