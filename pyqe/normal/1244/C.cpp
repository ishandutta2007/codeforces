#include <bits/stdc++.h>

using namespace std;

long long n,d,k,l;

int main()
{
	long long i,ii,c1,c2;
	
	scanf("%lld%lld%lld%lld",&n,&d,&k,&l);
	if(d%__gcd(k,l)!=0)
	{
		printf("-1\n");
		return 0;
	}
	for(ii=0;ii<2;ii++)
	{
		for(i=0;i<=n;i++)
		{
			if((d-i*k)%l==0)
			{
				c1=i;
				c2=(d-i*k)/l;
				if(c1+c2<=n&&c2>=0)
				{
					if(ii)
					{
						swap(c1,c2);
					}
					printf("%lld %lld %lld\n",c1,c2,n-c1-c2);
					return 0;
				}
				break;
			}
		}
		swap(k,l);
	}
	printf("-1\n");
}