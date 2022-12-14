#include<cstdio>

int n, sum[100005], sum2[100005], a[100005], l;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		if (i != 0)
			sum[i] = sum[i - 1];
		scanf("%d", &a[i]);
		sum[i] += a[i];
	}
	for (int i = n - 1; i >= 0; i--)
		sum2[i] = sum2[i + 1] + a[i]; 
   	for (int i = 1; i < n; i++)
   	{                 
   		if (sum[i - 1] <= sum2[i + 1])
   			l = i;
   	}
   	printf("%d %d\n", l + 1, n - l - 1);
	return 0;
}