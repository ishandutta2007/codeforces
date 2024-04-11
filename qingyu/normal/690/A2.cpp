#include <bits/stdc++.h>

int main()
{ 
    int n; scanf("%d", &n);
	if (n % 2 == 1) printf("%d\n", n >> 1);
	else
	{
		int t = 1 << 30;
		while ((n & t) == 0) t >>= 1;
		printf("%d\n", (n - t) / 2);
	}
	return 0;
}