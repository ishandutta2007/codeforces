#include <bits/stdc++.h>


int main()
{
	int n, x, mn = 51, c = 0; scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &x);
		if (x < mn) mn = x, c = 0;
		if (x == mn) ++c;
	}
	puts(c > n / 2 ? "Bob" : "Alice");	
}