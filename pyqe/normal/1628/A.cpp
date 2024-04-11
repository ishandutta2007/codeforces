#include <bits/stdc++.h>

using namespace std;

long long n,a[200069],sx[200069],sq[200069],zs;
bitset<200069> vtd;

int main()
{
	long long t,rr,i,j,l;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		for(i=0;i<=n;i++)
		{
			vtd[i]=0;
		}
		for(j=0,i=n;i;i--)
		{
			vtd[a[i]]=1;
			for(;vtd[j];j++);
			sx[i]=j;
		}
		for(i=0;i<=n;i++)
		{
			vtd[i]=0;
		}
		zs=0;
		for(l=1,j=0,i=1;i<=n;i++)
		{
			vtd[a[i]]=1;
			for(;vtd[j];j++);
			if(j==sx[l])
			{
				zs++;
				sq[zs]=j;
				for(j=l;j<=i;j++)
				{
					vtd[a[j]]=0;
				}
				l=i+1;
				j=0;
			}
		}
		printf("%lld\n",zs);
		for(i=1;i<=zs;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==zs]);
		}
	}
}