#include <bits/stdc++.h>

using namespace std;

long long n,rt[2],dsu[300069],cc[300069],kd[300069],sq[4];

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
	long long i,ii,e,k,l;
	
	scanf("%lld%lld%lld",&n,rt,rt+1);
	for(i=1;i<=n;i++)
	{
		dsu[i]=i;
		cc[i]=1;
	}
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		for(e=2,ii=0;ii<2&&e==2;ii++)
		{
			swap(k,l);
			for(e=0;e<2&&k!=rt[e];e++);
		}
		if(e==2)
		{
			cc[fd(k)]+=cc[fd(l)];
			kd[fd(k)]|=kd[fd(l)];
			dsu[fd(l)]=fd(k);
		}
		else
		{
			kd[fd(l)]|=1ll<<e;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(fd(i)==i&&i!=rt[0]&&i!=rt[1])
		{
			sq[kd[i]]+=cc[i];
		}
	}
	printf("%lld\n",n*(n-1)-(sq[1]+1)*(sq[2]+1));
}