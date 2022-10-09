//qy
#include <bits/stdc++.h>

const int N = 1e5 + 50;

int n, a[N], b[N];
int main()
{
	int t, n;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		int v = 0;
		for (int i = 1; i <= n; ++i) scanf("%d", a + i), v ^= a[i];
		if (v == 0) puts("DRAW");
		else
		{
			int d = 0; unsigned ele = 2147483647;
			for (int i = 0; i < 31; ++i) if ((1u << i) & v) d = i; 
			int g = 1 << d;
			int c0 = 0, c1 = 0;
			for (int i = 1; i <= n; ++i) if (a[i] & g) ++c1; else ++c0;
			if (c1 % 4 == 3 && c0 % 2 == 0) puts("LOSE");

			else puts("WIN");	
		}
	}
}