#include <bits/stdc++.h>

using namespace std;

long long n,m,dsu[500069],fq[500069];

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
	long long i,j,mm,k,l;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		dsu[i]=i;
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld",&mm);
		for(j=0;j<mm;j++)
		{
			scanf("%lld",&k);
			if(!j)
			{
				l=k;
			}
			else
			{
				dsu[fd(k)]=fd(l);
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		fq[fd(i)]++;
	}
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",fq[fd(i)]," \n"[i==n]);
	}
}