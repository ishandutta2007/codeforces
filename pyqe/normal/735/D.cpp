#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long k,i;
	bool bad;
	
	scanf("%lld",&k);
	bad=0;
	for(i=2;i*i<=k;i++)
	{
		if(k%i==0)
		{
			bad=1;
			break;
		}
	}
	if(!bad)
	{
		printf("1\n");
	}
	else
	{
		if(k%2==0)
		{
			printf("2\n");
		}
		else
		{
			k-=2;
			bad=0;
			for(i=2;i*i<=k;i++)
			{
				if(k%i==0)
				{
					bad=1;
					break;
				}
			}
			if(!bad)
			{
				printf("2\n");
			}
			else
			{
				printf("3\n");
			}
		}
	}
}