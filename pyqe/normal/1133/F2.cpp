#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m=0,d,nn=0,dsu[200069],zs=0;
pair<long long,long long> ed[200069],sq[200069];
bitset<200069> spc;

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

int main()
{
	long long i,k,l,sz,c=0;
	
	scanf("%lld%lld%lld",&n,&sz,&d);
	for(i=0;i<sz;i++)
	{
		scanf("%lld%lld",&k,&l);
		if(k>l)
		{
			swap(k,l);
		}
		if(k!=1)
		{
			m++;
			ed[m]={k,l};
		}
		else
		{
			nn++;
			spc[l]=1;
		}
	}
	if(nn<d)
	{
		printf("NO\n");
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		dsu[i]=i;
	}
	for(i=1;i<=m;i++)
	{
		k=ed[i].fr;
		l=ed[i].sc;
		if(fd(k)==fd(l))
		{
			continue;
		}
		if(!spc[fd(k)])
		{
			swap(k,l);
		}
		if(nn-c>d||!spc[fd(l)])
		{
			c+=spc[fd(l)];
			dsu[fd(l)]=fd(k);
			zs++;
			sq[zs]={k,l};
		}
	}
	if(nn-c>d)
	{
		printf("NO\n");
		return 0;
	}
	for(i=2;i<=n;i++)
	{
		if(fd(i)==i)
		{
			if(!spc[i])
			{
				printf("NO\n");
				return 0;
			}
			zs++;
			sq[zs]={1,i};
		}
	}
	printf("YES\n");
	for(i=1;i<=zs;i++)
	{
		k=sq[i].fr;
		l=sq[i].sc;
		printf("%lld %lld\n",k,l);
	}
}