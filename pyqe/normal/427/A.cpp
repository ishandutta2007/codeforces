#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n,i,k,z=0,c=0;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		if(k==-1)
		{
			if(z==0)
			{
				c++;
			}
			else
			{
				z--;
			}
		}
		else
		{
			z+=k;
		}
	}
	printf("%lld\n",c);
}