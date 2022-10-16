#include <bits/stdc++.h>

using namespace std;

long long n,ln,d[2],sq[3],zs=0;
map<long long,long long> vtd;

int main()
{
	long long i,ii,k,sm,df,fh=-1,nr[2]={-1,-1};
	bool bad[2]={1,1};
	
	scanf("%lld%lld%lld%lld",&n,&ln,d,d+1);
	sm=d[0]+d[1];
	df=d[1]-d[0];
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		for(ii=0;ii<2;ii++)
		{
			bad[ii]&=!vtd[k-d[ii]];
		}
		if(vtd[k-sm])
		{
			fh=k;
		}
		if(vtd[k-df])
		{
			if(nr[0]==-1)
			{
				nr[0]=k;
			}
			nr[1]=k;
		}
		vtd[k]=1;
	}
	if(!bad[0]&&!bad[1]);
	else if(!bad[0]||!bad[1])
	{
		zs++;
		sq[zs]=d[bad[1]];
	}
	else if(fh!=-1)
	{
		zs++;
		sq[zs]=fh-d[1];
	}
	else if(nr[0]!=-1&&nr[0]+d[0]<=ln)
	{
		zs++;
		sq[zs]=nr[0]+d[0];
	}
	else if(nr[1]!=-1&&nr[1]-d[1]>=0)
	{
		zs++;
		sq[zs]=nr[1]-d[1];
	}
	else
	{
		for(ii=0;ii<2;ii++)
		{
			zs++;
			sq[zs]=d[ii];
		}
	}
	printf("%lld\n",zs);
	for(i=1;i<=zs;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==zs]);
	}
}