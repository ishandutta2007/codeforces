#include<cstdio>

int n, a[100000], sum = 0;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		sum += a[i];
	}
	if (sum % n != 0)       
		printf("%d\n", n - 1);
	else
		printf("%d\n", n);
	return 0;
}