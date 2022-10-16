#include <bits/stdc++.h>

using namespace std;

long long n,m,ma=100,a[12],fq[1ll<<12],wg[1ll<<12],sq[1ll<<12][169];

int main()
{
	long long t,rr,i,j,k,mk,mkk;
	char ch;
	
	scanf("%lld%lld%lld",&n,&m,&t);
	for(i=0;i<n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=0;i<m;i++)
	{
		mk=0;
		for(j=0;j<n;j++)
		{
			scanf(" %c",&ch);
			mk|=(long long)(ch=='0')<<j;
		}
		fq[mk]++;
	}
	for(mk=0;mk<1ll<<n;mk++)
	{
		for(i=0;i<n;i++)
		{
			wg[mk]+=a[i]*(mk>>i&1);
		}
	}
	for(mk=0;mk<1ll<<n;mk++)
	{
		for(mkk=0;mkk<1ll<<n;mkk++)
		{
			k=wg[mk^mkk];
			if(k<=ma)
			{
				sq[mk][k]+=fq[mkk];
			}
		}
		for(i=1;i<=ma;i++)
		{
			sq[mk][i]+=sq[mk][i-1];
		}
	}
	for(rr=0;rr<t;rr++)
	{
		mk=0;
		for(i=0;i<n;i++)
		{
			scanf(" %c",&ch);
			mk|=(long long)(ch-'0')<<i;
		}
		scanf("%lld",&k);
		printf("%lld\n",sq[mk][k]);
	}
}