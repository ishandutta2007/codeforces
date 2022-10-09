// sto djq orz
#include <bits/stdc++.h>

const int N = 5005;

int f[N], dep[N], node[N];
int pre, maxd;

int main()
{
	int T, n, d;
	scanf("%d", &T);
	while (T--)
	{
		pre = maxd = 0; memset(node, 0, sizeof node);
		scanf("%d%d", &n, &d);
		for (int i = 2; i <= n; ++i)
		{
			f[i] = i >> 1, dep[i] = dep[f[i]] + 1;
			if (node[dep[i]] == 0) node[dep[i]] = i, ++maxd;
			d -= dep[i];
		}
		if (d < 0) puts("NO");
		else
		{
			for (int i = n; i >= 2; --i)
			{
				if (node[dep[i]] != i)
				{
					pre = maxd;
					while (dep[i] <= pre && d)
					{
						f[i] = node[dep[i]];
						dep[i] = dep[f[i]] + 1;
						if (dep[i] > maxd)
						{
							++maxd;
							node[maxd] = i;
						}
						--d;
					}
				}
			}
			if (d) puts("NO");
			else
			{
				puts("YES");
				for (int i = 2; i <= n; ++i) printf("%d ", f[i]);
				putchar('\n');
			}
		}
	}
	return 0;
}