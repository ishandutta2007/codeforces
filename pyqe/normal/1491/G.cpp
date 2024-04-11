#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nn=0,a[200069],pst[200069],ex[200069],zs=0;
bitset<200069> vtd;
pair<long long,long long> sq[200069];

int main()
{
	long long i,ii,k,p;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		a[k]=i;
		pst[i]=k;
	}
	for(i=1;i<=n;i++)
	{
		if(!vtd[i])
		{
			nn++;
			ex[nn]=i;
			for(p=i;!vtd[p];p=a[p])
			{
				vtd[p]=1;
			}
		}
	}
	if(nn>1)
	{
		if(nn%2)
		{
			zs++;
			sq[zs]={a[ex[nn]],a[ex[1]]};
			for(p=pst[ex[nn]];p!=ex[nn];p=pst[p])
			{
				zs++;
				sq[zs]={a[p],a[ex[1]]};
			}
			zs++;
			sq[zs]={a[ex[nn]],a[ex[1]]};
		}
		for(i=1;i<nn;i+=2)
		{
			zs++;
			sq[zs]={a[ex[i]],a[ex[i+1]]};
			for(ii=0;ii<2;ii++)
			{
				for(p=pst[ex[i+ii]];p!=ex[i+ii];p=pst[p])
				{
					zs++;
					sq[zs]={a[p],a[ex[i+!ii]]};
				}
			}
			zs++;
			sq[zs]={a[ex[i]],a[ex[i+1]]};
		}
	}
	else
	{
		zs++;
		sq[zs]={a[1],1};
		zs++;
		sq[zs]={1,pst[1]};
		zs++;
		sq[zs]={pst[1],a[1]};
		for(p=pst[pst[pst[1]]];p!=1;p=pst[p])
		{
			zs++;
			sq[zs]={a[p],1};
		}
		zs++;
		sq[zs]={a[1],1};
	}
	printf("%lld\n",zs);
	for(i=1;i<=zs;i++)
	{
		printf("%lld %lld\n",sq[i].fr,sq[i].sc);
	}
}