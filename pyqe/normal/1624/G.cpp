#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long mm=30;
long long n,m,dsu[200069];
pair<pair<long long,long long>,long long> ed[200069];

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
	long long t,rr,i,j,k,l,w,mk,c,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=m;i++)
		{
			scanf("%lld%lld%lld",&k,&l,&w);
			ed[i]={{k,l},w};
		}
		z=0;
		for(i=mm-1;i>=0;i--)
		{
			mk=(z|(1ll<<i+1)-1)^1ll<<i;
			for(j=1;j<=n;j++)
			{
				dsu[j]=j;
			}
			c=n;
			for(j=1;j<=m;j++)
			{
				k=ed[j].fr.fr;
				l=ed[j].fr.sc;
				w=ed[j].sc;
				if((w&mk)==w)
				{
					c-=fd(k)!=fd(l);
					dsu[fd(l)]=fd(k);
				}
			}
			if(c>1)
			{
				z|=1ll<<i;
			}
		}
		printf("%lld\n",z);
	}
}