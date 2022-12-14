#include<cstdio>

int a, k, i;

int main()
{
	scanf("%d", &a);
	k = 1;
	for (i = 2; i <= a; i++)
		k = k + (i - 1) * 12;
	printf("%d", k);
	return 0;
}