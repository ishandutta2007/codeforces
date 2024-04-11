#include <bits/stdc++.h>

using namespace std;

long long n,m,d,fh[1000069],inf=1e18;

int main()
{
	long long i,k,p,c,z=inf;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=1;i<=n;i++)
	{
		fh[i]=i;
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld",&k);
		fh[k+1]=fh[k];
	}
	for(i=1;i<=d;i++)
	{
		scanf("%lld",&k);
		for(c=0,p=1;p<=n;p+=i,c++)
		{
			p=fh[p];
			if(!p||(p+i<=n&&fh[p+i]==p))
			{
				break;
			}
		}
		if(p>n)
		{
			z=min(z,c*k);
		}
	}
	if(z==inf)
	{
		z=-1;
	}
	printf("%lld\n",z);
}