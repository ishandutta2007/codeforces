#include <bits/stdc++.h>

using namespace std;

long long n,m,d,a[100069],pc[1ll<<20],fq[1ll<<8][13],wg[1ll<<8][9];

int main()
{
	long long i,j,k,mk,mk2,mk3,sm,z;
	char ch;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf(" %c",&ch);
			k=ch-'0';
			a[j]|=k<<i;
		}
	}
	for(mk=0;mk<1ll<<n;mk++)
	{
		pc[mk]=__builtin_popcount(mk);
	}
	d=min(12ll,n);
	z=n*m;
	for(mk=0;mk<1ll<<d-1;mk++)
	{
		for(mk2=0;mk2<1ll<<n-d;mk2++)
		{
			for(i=0;i<=d;i++)
			{
				fq[mk2][i]=0;
			}
			for(i=0;i<=n-d;i++)
			{
				wg[mk2][i]=0;
			}
		}
		for(i=1;i<=m;i++)
		{
			fq[a[i]>>d][pc[(a[i]&(1ll<<d)-1)^mk]]++;
		}
		for(mk2=0;mk2<1ll<<n-d;mk2++)
		{
			for(i=0;i<=d;i++)
			{
				for(j=0;j<=n-d;j++)
				{
					wg[mk2][j]+=min(i+j,n-i-j)*fq[mk2][i];
				}
			}
		}
		for(mk2=0;mk2<1ll<<n-d;mk2++)
		{
			sm=0;
			for(mk3=0;mk3<1ll<<n-d;mk3++)
			{
				sm+=wg[mk3][pc[mk2^mk3]];
			}
			z=min(z,sm);
		}
	}
	printf("%lld\n",z);
}