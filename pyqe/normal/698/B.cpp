#include <bits/stdc++.h>

using namespace std;

long long n,pr[200069],dsu[200069],rt=0,an[200069];

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
	long long i,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		dsu[i]=i;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",pr+i);
		if(pr[i]==i)
		{
			rt=i;
		}
		if(fd(pr[i])!=fd(i))
		{
			an[fd(i)]=an[fd(pr[i])];
			dsu[fd(pr[i])]=fd(i);
		}
		else
		{
			an[fd(i)]=i;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(fd(i)==i&&an[i]!=rt)
		{
			if(!rt)
			{
				rt=an[i];
			}
			pr[an[i]]=rt;
			z++;
		}
	}
	printf("%lld\n",z);
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",pr[i]," \n"[i==n]);
	}
}