#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,m;

int main()
{
	long long t,rr,i,j,y,x,z;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld%lld",&n,&m,&y,&x);
		z=inf;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf(" %c",&ch);
				if(ch=='B')
				{
					z=min(z,2ll);
					if(i==y||j==x)
					{
						z=min(z,1ll);
					}
					if(i==y&&j==x)
					{
						z=min(z,0ll);
					}
				}
			}
		}
		if(z==inf)
		{
			z=-1;
		}
		printf("%lld\n",z);
	}
}