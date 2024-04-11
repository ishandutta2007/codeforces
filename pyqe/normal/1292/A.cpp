#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

int main()
{
	long long t,rr,ii,iii,k,l,c=0;
	
	scanf("%lld%lld",&n,&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		for(ii=0;ii<2;ii++)
		{
			for(iii=0;iii<2;iii++)
			{
				c-=a[l-1+ii]==1+iii&&a[l+ii]==1+!iii;
			}
		}
		c-=a[l]==3;
		a[l]^=1<<k-1;
		for(ii=0;ii<2;ii++)
		{
			for(iii=0;iii<2;iii++)
			{
				c+=a[l-1+ii]==1+iii&&a[l+ii]==1+!iii;
			}
		}
		c+=a[l]==3;
		if(c)
		{
			printf("No\n");
		}
		else
		{
			printf("Yes\n");
		}
	}
}