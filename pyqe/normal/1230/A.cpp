#include <bits/stdc++.h>

using namespace std;

long long a[4];

int main()
{
	long long i,mk,z,zz=0;
	
	for(i=0;i<4;i++)
	{
		scanf("%lld",a+i);
		zz+=a[i];
	}
	for(mk=0;mk<1<<4;mk++)
	{
		z=0;
		for(i=0;i<4;i++)
		{
			if(mk&1<<i)
			{
				z+=a[i];
			}
		}
		if(z*2==zz)
		{
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
}