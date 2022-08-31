#include <iostream>
#include <cstdio>
using namespace std;

int n, k;
int pocz, kon;
int stro;

int main()
{
	scanf("%d%d", &n, &k);
	pocz=2;
	kon=n;
	printf("1 ");
	k--;
	while(1)
	{
		if (k)
		{
			k--;
			stro=(stro+1)%2;
		}
		if (!stro)
		{
			printf("%d ", pocz);
			if (pocz==kon)
			break;
			pocz++;
		}
		else
		{
			printf("%d ", kon);
			if (pocz==kon)
			break;
			kon--;
		}
	}
	return 0;
}