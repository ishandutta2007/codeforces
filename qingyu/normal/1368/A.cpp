// By Qingyu
#include <bits/stdc++.h>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int a, b, n, count = 0;
		scanf("%d%d%d", &a, &b, &n);
		if (a > b) std::swap(a, b);
		while (b <= n)
		{
			a += b;
			std::swap(a, b);
			++count;
		}
		printf("%d\n", count);
	}
}