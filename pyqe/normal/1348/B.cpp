#include <bits/stdc++.h>

using namespace std;

long long n,d,nn=0,a[169],ky[169],sq[10069],zs=0;
bitset<169> vtd;

int main()
{
	long long t,rr,i,j;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		nn=0;
		for(i=1;i<=n;i++)
		{
			vtd[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			if(!vtd[a[i]])
			{
				nn++;
				ky[nn]=a[i];
				vtd[a[i]]=1;
			}
		}
		if(nn>d)
		{
			printf("-1\n");
			continue;
		}
		for(;nn<d;)
		{
			nn++;
			ky[nn]=1;
		}
		zs=0;
		for(j=1,i=1;i<=n;i++)
		{
			for(;ky[j]!=a[i];j=j%nn+1)
			{
				zs++;
				sq[zs]=ky[j];
			}
			zs++;
			sq[zs]=ky[j];
			j=j%nn+1;
		}
		printf("%lld\n",zs);
		for(i=1;i<=zs;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==zs]);
		}
	}
}