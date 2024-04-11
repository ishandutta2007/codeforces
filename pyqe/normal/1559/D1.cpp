#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m[2],nn[2],dsu[2][100069],ex[2][100069],zs=0;
pair<long long,long long> sq[100069];

long long fd(long long xx,long long x)
{
	if(dsu[xx][x]!=x)
	{
		dsu[xx][x]=fd(xx,dsu[xx][x]);
	}
	return dsu[xx][x];
}

int main()
{
	long long i,ii,k,l;
	
	scanf("%lld%lld%lld",&n,m,m+1);
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n;i++)
		{
			dsu[ii][i]=i;
		}
		for(i=0;i<m[ii];i++)
		{
			scanf("%lld%lld",&k,&l);
			dsu[ii][fd(ii,l)]=fd(ii,k);
		}
	}
	for(i=1;i<=n;i++)
	{
		if(fd(0,i)!=fd(0,1)&&fd(1,i)!=fd(1,1))
		{
			zs++;
			sq[zs]={1,i};
			for(ii=0;ii<2;ii++)
			{
				dsu[ii][fd(ii,i)]=fd(ii,1);
			}
		}
	}
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n;i++)
		{
			if(fd(ii,i)==i&&fd(ii,i)!=fd(ii,1))
			{
				nn[ii]++;
				ex[ii][nn[ii]]=i;
			}
		}
	}
	for(i=1;i<=min(nn[0],nn[1]);i++)
	{
		zs++;
		sq[zs]={ex[0][i],ex[1][i]};
	}
	printf("%lld\n",zs);
	for(i=1;i<=zs;i++)
	{
		k=sq[i].fr;
		l=sq[i].sc;
		printf("%lld %lld\n",k,l);
	}
}