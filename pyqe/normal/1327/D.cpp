#include <bits/stdc++.h>

using namespace std;

long long n,nn,pr[200069],a[200069],sq[200069],mo[200069];
bitset<200069> vtd;

int main()
{
	long long t,rr,i,j,r,rm,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",pr+i);
			vtd[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		z=1e18;
		for(i=1;i<=n;i++)
		{
			if(!vtd[i])
			{
				nn=1;
				sq[1]=i;
				for(;pr[sq[nn]]!=sq[1];)
				{
					nn++;
					sq[nn]=pr[sq[nn-1]];
				}
				for(j=1;j<=nn;j++)
				{
					vtd[sq[j]]=1;
					if(nn%j==0)
					{
						for(r=0;r<j;r++)
						{
							mo[r]=0;
						}
						for(r=1;r<=nn;r++)
						{
							rm=r%j;
							if(!mo[rm]||mo[rm]==a[sq[r]])
							{
								mo[rm]=a[sq[r]];
							}
							else
							{
								mo[rm]=-1;
							}
						}
						for(r=0;r<j;r++)
						{
							if(mo[r]!=-1)
							{
								z=min(z,j);
							}
						}
					}
				}
			}
		}
		printf("%lld\n",z);
	}
}