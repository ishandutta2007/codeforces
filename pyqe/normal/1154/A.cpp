#include <bits/stdc++.h>

using namespace std;

long long a[4];

int main()
{
	long long i;
	
	for(i=0;i<4;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a,a+4);
	for(i=0;i<3;i++)
	{
		if(i>0)
		{
			printf(" ");
		}
		printf("%lld",a[3]-a[i]);
	}
	printf("\n");
}