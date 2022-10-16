#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,m,mn[2069],mx[2069];
bitset<1069> a[1069];
multiset<long long> ms[2069];

long long tri(long long x)
{
	return x*(x-1)/2;
}

int main()
{
	long long t,rr,i,j,ii,k,l,p,y,x,z;
	
	scanf("%lld%lld%lld",&n,&m,&t);
	for(i=1;i<=n+m;i++)
	{
		mn[i]=inf;
		mx[i]=-inf;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			for(ii=0;ii<2;ii++)
			{
				p=m+i-j+ii;
				mn[p]=min(mn[p],i+j);
				mx[p]=max(mx[p],i+j);
			}
		}
	}
	z=n*m;
	for(i=1;i<=n+m;i++)
	{
		z+=tri(mx[i]-mn[i]+1);
		ms[i].insert(mn[i]-1);
		ms[i].insert(mx[i]+1);
	}
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&y,&x);
		if(!a[y][x])
		{
			a[y][x]=1;
			z--;
			for(ii=0;ii<2;ii++)
			{
				p=m+y-x+ii;
				k=*prev(ms[p].lower_bound(y+x));
				l=*ms[p].upper_bound(y+x);
				z+=tri(l-y-x-1)+tri(y+x-k-1)-tri(l-k-1);
				ms[p].insert(y+x);
			}
		}
		else
		{
			a[y][x]=0;
			z++;
			for(ii=0;ii<2;ii++)
			{
				p=m+y-x+ii;
				k=*prev(ms[p].lower_bound(y+x));
				l=*ms[p].upper_bound(y+x);
				z+=tri(l-k-1)-tri(l-y-x-1)-tri(y+x-k-1);
				ms[p].erase(y+x);
			}
		}
		printf("%lld\n",z);
	}
}