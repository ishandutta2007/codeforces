#include <bits/stdc++.h>

using namespace std;

const long long dv=1e9+7;
long long n,a[100069],fq[3],fc[100069],ifc[100069],pwk;

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

long long cb(long long x,long long y)
{
	return fc[x]*ifc[y]%dv*ifc[x-y]%dv;
}

int main()
{
	long long i,sm=0,c,z;
	
	scanf("%lld",&n);
	fc[0]=1;
	ifc[0]=1;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		sm+=a[i];
		fc[i]=fc[i-1]*i%dv;
		ifc[i]=pw(fc[i],dv-2);
	}
	if(sm%n)
	{
		printf("0\n");
		return 0;
	}
	for(i=0;i<3;i++)
	{
		fq[i]=0;
	}
	for(i=1;i<=n;i++)
	{
		fq[(a[i]>sm/n)+2*(a[i]<sm/n)]++;
	}
	if(min(fq[1],fq[2])<=1)
	{
		z=fc[n];
	}
	else
	{
		z=fc[fq[1]]*fc[fq[2]]*2%dv*fc[fq[0]]%dv*cb(n,fq[0])%dv;
	}
	sort(a+1,a+n+1);
	c=0;
	for(i=1;i<=n;i++)
	{
		c++;
		if(i==n||a[i]!=a[i+1])
		{
			z=z*ifc[c]%dv;
			c=0;
		}
	}
	printf("%lld\n",z);
}