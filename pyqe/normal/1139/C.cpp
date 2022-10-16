#include <bits/stdc++.h>

using namespace std;

long long n,d,dsu[100069],cd[100069],pwk,dv=1e9+7;

long long pw(long long x,long long y)
{
	if(!y)
	{
		return 1;
	}
	pwk=pw(x,y/2);
	pwk=pwk*pwk%dv;
	if(y%2)
	{
		pwk=pwk*x%dv;
	}
	return pwk;
}

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
	long long i,k,l,w,z;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		dsu[i]=i;
		cd[i]=1;
	}
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		if(!w)
		{
			cd[fd(k)]+=cd[fd(l)];
			dsu[fd(l)]=fd(k);
		}
	}
	z=pw(n,d);
	for(i=1;i<=n;i++)
	{
		if(fd(i)==i)
		{
			z=(z+dv-pw(cd[i],d))%dv;
		}
	}
	printf("%lld\n",z);
}