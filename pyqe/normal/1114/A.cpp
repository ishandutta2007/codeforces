#include <bits/stdc++.h>

using namespace std;

long long a[3],d[3],z=0;

int main()
{
	long long i;
	
	for(i=0;i<3;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=0;i<3;i++)
	{
		scanf("%lld",d+i);
	}
	for(i=0;i<3;i++)
	{
		z+=d[i];
		if(z<a[i])
		{
			printf("NO\n");
			return 0;
		}
		z-=a[i];
	}
	printf("YES\n");
}