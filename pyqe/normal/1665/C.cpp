#include <bits/stdc++.h>

using namespace std;

long long n,dg[200069],fq[200069],ps[2][200069];

int main()
{
	long long t,rr,i,k,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=0;i<=n;i++)
		{
			dg[i]=0;
			fq[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			k=0;
			if(i>1)
			{
				scanf("%lld",&k);
			}
			dg[k]++;
		}
		sort(dg,dg+n+1,greater<long long>());
		for(i=0;i<=n;i++)
		{
			if(dg[i])
			{
				k=i+1;
			}
		}
		z=k;
		for(i=0;i<k;i++)
		{
			dg[i]=max(dg[i]-(k-i),0ll);
		}
		for(i=0;i<=n;i++)
		{
			fq[dg[i]]++;
		}
		ps[0][0]=fq[0];
		for(i=1;i<=n;i++)
		{
			ps[0][i]=ps[0][i-1]+fq[i];
			ps[1][i]=ps[1][i-1]+fq[i]*i;
		}
		for(i=0;ps[1][n]-ps[1][i]-(ps[0][n]-ps[0][i])*i>i;i++,z++);
		printf("%lld\n",z);
	}
}