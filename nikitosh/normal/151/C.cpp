#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

long long q, p, k, a[100];
int i, x, b = 0, z;

int main()
{
	scanf("%I64d", &q);  
	p = q;
	k = 10000000;                             
	for (i = 2; i <= (int) round(sqrt(q)) + 10; i++)
	{
		if (q % i == 0 && q != i)    
			b = 1;
	}                 
	if (b == 1)
	{
		while(q != 1)
		{                           
			z = 0;
			for (i = 2; i <= (int) round(sqrt(q)) + 10; i++)
				if (q % i == 0)
				{
					z = 1;                    
					a[x] = i;
					x++;
					q /= i;
					break;
				}
			if (z == 0)
			{
				a[x] = q;
				x++;
				break;
			}
	   	}
	}                                  
	if ((x >= 2 && a[0] * a[1] != p) || b == 0)
	{
		printf("%d\n", 1);
		if (a[0] != 0)
			printf("%I64d\n", a[0] * a[1]);
		else
			printf("%d\n", 0);
	}
	else
		printf("%d\n", 2);
	return 0;
}