#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,fq[200069],sq[200069],zs=0;

int main()
{
	long long i,j,k,sm=0,e;
	pair<long long,long long> mxe={-1e18,-1};
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		fq[k]++;
	}
	for(i=1;i<=200000;i++)
	{
		sm+=fq[i];
		if(!fq[i])
		{
			sm=0;
		}
		mxe=max(mxe,{sm,i});
		if(fq[i]==1)
		{
			sm=1;
		}
	}
	e=mxe.sc;
	for(i=e;1;i--)
	{
		zs++;
		sq[zs]=i;
		if(!fq[i-1]||(fq[i]==1&&i<e))
		{
			break;
		}
	}
	for(;i<=e;i++)
	{
		for(j=0;j<fq[i]-1;j++)
		{
			zs++;
			sq[zs]=i;
		}
	}
	printf("%lld\n",zs);
	for(i=1;i<=zs;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==zs]);
	}
}