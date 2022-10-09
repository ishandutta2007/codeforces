// By Qingyu
#include <bits/stdc++.h>

int main()
{
	int k;
	scanf("%d", &k);
	++k;
	printf("%d\n", 3 * k + 1);
	printf("0 0\n");
	for (int i = 1; i <= k; ++i)
		printf("%d %d\n%d %d\n%d %d\n", i, i, i - 1, i, i, i - 1);
}