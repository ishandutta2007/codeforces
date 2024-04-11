//orzlt
#include <bits/stdc++.h>

const int N = 5e5 + 50;

int n, a[N], L[N], R[N], stack[N], top, p[N]; 

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
	n = read();
	for (int i = 1; i <= n; ++i) a[i] = read(), p[a[i]] = i;
	for (int i = 1; i <= n; ++i)
	{
		while (top && a[stack[top]] < a[i]) --top;
		L[i] = stack[top], stack[++top] = i;
	}
	top = 0;
	for (int i = n; i >= 1; --i)
	{
		while (top && a[stack[top]] < a[i]) --top;
		R[i] = stack[top], stack[++top] = i;
		if (!R[i]) R[i] = n + 1;
	}
	
	int ans = 0;
	
	for (int i = 1; i <= n; ++i)
	{
		if (i - L[i] < R[i] - i)
		{
			for (int j = L[i] + 1; j < i; ++j) // a[i] = max[L[i] + 1, R[i] - 1]
			{
				int t = p[a[i] - a[j]];
				if (i < t && t < R[i]) ++ans;
			}
		}
		else
		{
			for (int j = i + 1; j < R[i]; ++j)
			{
				int t = p[a[i] - a[j]];
				if (L[i] < t && t < i) ++ans;
			}
		}
	}
	printf("%d", ans);
	return 0; 
}