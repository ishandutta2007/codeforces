#include<cstdio>

int n, x, y, t, sum1 = 0, sum2 = 0, z1 = 0, z2 = 0;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d", &t, &x, &y);
		if (t == 1)
		{
			sum1++;
			z1 += x;
		}
		else
		{
			sum2++;
			z2 += x;
		}
 	}
 	if (z1 >= sum1 * 5)
 		printf("LIVE\n");
 	else
 		printf("DEAD\n");
 	if (z2 >= sum2 * 5)
 		printf("LIVE\n");
 	else
 		printf("DEAD\n");
	return 0;
}