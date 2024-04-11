#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n,m,k,i,d,z,c=0,r;
	
	scanf("%lld%lld%lld",&n,&m,&k);
	long long a[m];
	for(i=0;i<m;i++)
	{
		scanf("%lld",a+i);
	}
	scanf("%lld",&d);
	for(i=0;i<m;i++)
	{
		z=d^a[i];
		r=0;
		while(z>0)
		{
			if(z%2==1)
			{
				r++;
				if(r>k)
				{
					break;
				}
			}
			z/=2;
		}
		if(r<=k)
		{
			c++;
		}
	}
	printf("%lld\n",c);
}