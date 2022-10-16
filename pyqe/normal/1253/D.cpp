#include <bits/stdc++.h>

using namespace std;

long long n,m,pr[200069],fh[200069];
bitset<200069> vtd;

long long fd(long long x)
{
	if(pr[x]!=x)
	{
		pr[x]=fd(pr[x]);
	}
	return pr[x];
}

int main()
{
	long long i,k,l,mx=0,z=0;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		pr[i]=i;
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		pr[fd(l)]=fd(k);
	}
	for(i=1;i<=n;i++)
	{
		fh[fd(i)]=i;
	}
	for(i=1;i<=n;i++)
	{
		if(!vtd[fd(i)])
		{
			if(i<=mx)
			{
				z++;
			}
			vtd[fd(i)]=1;
			mx=max(mx,fh[fd(i)]);
		}
	}
	printf("%lld\n",z);
}