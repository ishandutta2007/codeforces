#include <bits/stdc++.h>

using namespace std;

const long long dv=1e9+7;
long long n,pst[400069][2],dsu[400069];

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
	long long t,rr,i,ii,k,l,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(ii=0;ii<2;ii++)
		{
			for(i=1;i<=n;i++)
			{
				scanf("%lld",&k);
				pst[k][ii]=i;
			}
		}
		for(i=1;i<=n;i++)
		{
			dsu[i]=i;
		}
		for(i=1;i<=n;i++)
		{
			k=pst[i][0];
			l=pst[i][1];
			dsu[fd(l)]=fd(k);
		}
		z=1;
		for(i=1;i<=n;i++)
		{
			if(fd(i)==i)
			{
				z=z*2%dv;
			}
		}
		printf("%lld\n",z);
	}
}