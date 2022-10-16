#include <bits/stdc++.h>

using namespace std;

long long nn,n,p10[10];

int main()
{
	long long i,ii,u,k,z,mn=1e18;
	
	p10[0]=1;
	for(i=1;i<=9;i++)
	{
		p10[i]=p10[i-1]*10;
	}
	scanf("%lld",&nn);
	n=nn+1;
	if(n>-8&&n<=0)
	{
		n=1;
	}
	u=n/abs(n);
	n=abs(n);
	ii=(-u+1)/2;
	for(i=0;i<=9;i++)
	{
		k=n/p10[i]%10;
		if(k==8)
		{
			z=n;
		}
		else if(k!=8)
		{
			z=((n/p10[i]/10+(k*u>8*u)*u)*10+8)*p10[i]+(p10[i]-1)*ii;
		}
		mn=min(mn,z*u-nn);
	}
	printf("%lld\n",mn);
}