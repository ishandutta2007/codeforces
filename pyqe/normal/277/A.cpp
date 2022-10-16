#include <bits/stdc++.h>

using namespace std;

long long n,m,dsu[100069],ls[100069];

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
	long long i,j,k,sz,c=0;
	bool bad=1;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&sz);
		dsu[i]=i;
		for(j=0;j<sz;j++)
		{
			scanf("%lld",&k);
			if(ls[k])
			{
				dsu[fd(ls[k])]=i;
			}
			ls[k]=i;
		}
		bad&=!sz;
	}
	for(i=1;i<=n;i++)
	{
		c+=fd(i)==i;
	}
	printf("%lld\n",c-!bad);
}