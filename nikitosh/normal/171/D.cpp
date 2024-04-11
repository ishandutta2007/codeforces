#include<cstdio>

int a;

int main()
{
	scanf("%d", &a);
	if (a == 5)
	{
		printf("%d", 1);
		return 0;
  }    
	if (a % 3 == 0)
		printf("%d", 1);
	else
		printf("%d", a % 3 + 1);
	return 0;
}