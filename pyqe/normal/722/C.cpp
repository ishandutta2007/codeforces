#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],pm[100069],dsu[100069],sm[100069],sq[100069];
bitset<100069> vtd;

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
	long long i,u,mx=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",pm+i);
	}
	for(i=n;i;i--)
	{
		sq[i]=mx;
		vtd[pm[i]]=1;
		dsu[pm[i]]=pm[i];
		sm[pm[i]]=a[pm[i]];
		for(u=-1;u<=1;u+=2)
		{
			if(vtd[pm[i]+u])
			{
				sm[fd(pm[i])]+=sm[fd(pm[i]+u)];
				dsu[fd(pm[i]+u)]=fd(pm[i]);
			}
		}
		mx=max(mx,sm[fd(pm[i])]);
	}
	for(i=1;i<=n;i++)
	{
		printf("%lld\n",sq[i]);
	}
}