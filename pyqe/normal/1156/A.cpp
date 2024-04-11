#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,k,l,l2,z=0;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		if(i)
		{
			if(k==1||l==1)
			{
				z+=max(k,l)+1;
				if(i>=1)
				{
					z-=k==2&&l2==3;
				}
			}
			else
			{
				printf("Infinite\n");
				return 0;
			}
		}
		l2=l;
		l=k;
	}
	printf("Finite\n%lld\n",z);
}