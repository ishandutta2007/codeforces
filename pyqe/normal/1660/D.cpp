#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long inf=1e18;
long long n,a[200069];

int main()
{
	long long t,rr,i,j,l,sm,e,c[2],p[2];
	pair<long long,pair<long long,long long>> z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		z={0,{0,n}};
		l=0;
		for(i=1;i<=n+1;i++)
		{
			if(i<=n)
			{
				scanf("%lld",a+i);
			}
			if(i>n||!a[i])
			{
				sm=0;
				e=0;
				c[0]=0;
				c[1]=inf;
				p[0]=l;
				for(j=l+1;j<i;j++)
				{
					sm+=abs(a[j])==2;
					if(a[j]<0)
					{
						e^=1;
						if(c[1]==inf)
						{
							c[1]=sm;
							p[1]=j;
						}
					}
					z=max(z,{sm-c[e],{p[e],n-j}});
				}
				l=i;
			}
		}
		printf("%lld %lld\n",z.sc.fr,z.sc.sc);
	}
}