#include<cstdio>

int d, sum, min1[100], max1[100], sum1, sum2, ans, l;

int main()
{
	scanf("%d%d", &d, &sum);
	for (int i = 0; i < d; i++)
	{
		scanf("%d%d", &min1[i], &max1[i]);
		sum1 += min1[i];
		sum2 += max1[i];
	}
	if (sum1 <= sum && sum2 >= sum)
		printf("YES\n");
	else
	{
		printf("NO\n");
		return 0;
	}
	ans = sum1;
   	l = d;
   	for (int i = 0; i < d; i++)
   	{
   		if (ans + max1[i] - min1[i] < sum)
   		{
   			printf("%d ", max1[i]);
   			ans += max1[i] - min1[i];
   			continue;
   		}	
    	printf("%d ", sum - ans + min1[i]);
    	l = i + 1;
    	break;
    }
    for (int i = l; i < d; i++)
    	printf("%d ", min1[i]);
	return 0;
}