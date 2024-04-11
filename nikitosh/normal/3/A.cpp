#include<cstdio>
#include<algorithm>

using namespace std;

char c1, c2;
int a1, a2, l1, l2;

int main()
{
	scanf("%c%d\n%c%d", &c1, &a1, &c2, &a2);
	l1 = abs(c1 - c2);
	l2 = abs(a1 - a2);
	printf("%d\n", max(l1, l2));
	if (c2 > c1 && a2 >= a1)
	{
		if (l1 <= l2)
		{
			for (int i = 0; i < l1; i++)
				printf("RU\n");
			for (int i = 0; i < l2 - l1; i++)
				printf("U\n");
		}
		else
		{
			for (int i = 0; i < l2; i++)
				printf("RU\n");
			for (int i = 0; i < l1 - l2; i++)
				printf("R\n");
		}
	}	
	if (c2 <= c1 && a2 > a1)
	{
		if (l1 <= l2)
		{
			for (int i = 0; i < l1; i++)
				printf("LU\n");
			for (int i = 0; i < l2 - l1; i++)
				printf("U\n");
		}
		else
		{
			for (int i = 0; i < l2; i++)
				printf("LU\n");
			for (int i = 0; i < l1 - l2; i++)
				printf("L\n");
		}
	}	
	if (c2 < c1 && a2 <= a1)
	{
		if (l1 <= l2)
		{
			for (int i = 0; i < l1; i++)
				printf("LD\n");
			for (int i = 0; i < l2 - l1; i++)
				printf("D\n");
		}
		else
		{
			for (int i = 0; i < l2; i++)
				printf("LD\n");
			for (int i = 0; i < l1 - l2; i++)
				printf("L\n");
		}
	}	
	if (c2 >= c1 && a2 < a1)
	{
		if (l1 <= l2)
		{
			for (int i = 0; i < l1; i++)
				printf("RD\n");
			for (int i = 0; i < l2 - l1; i++)
				printf("D\n");
		}
		else
		{
			for (int i = 0; i < l2; i++)
				printf("RD\n");
			for (int i = 0; i < l1 - l2; i++)
				printf("R\n");
		}
	}	
	return 0;
}