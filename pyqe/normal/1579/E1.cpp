#include <bits/stdc++.h>

using namespace std;

long long n,a[200069],pst[200069],sq[200069],zs;
bitset<200069> vtd;

int main()
{
	long long t,rr,i;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			pst[a[i]]=i;
			vtd[i]=0;
		}
		zs=0;
		for(i=1;i<=n;i++)
		{
			if(!zs||pst[i]<pst[sq[zs]])
			{
				zs++;
				sq[zs]=i;
				vtd[pst[i]]=1;
			}
		}
		for(i=1;i<=n;i++)
		{
			if(!vtd[i])
			{
				zs++;
				sq[zs]=a[i];
			}
		}
		for(i=1;i<=zs;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==zs]);
		}
	}
}