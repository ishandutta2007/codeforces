#include <bits/stdc++.h>

using namespace std;

long long n,m,ma=1e7,a[1000069],fq[10000069],inf=1e18;

long long val(long long x)
{
	if(x<=0)
	{
		return -1;
	}
	else if(x>n)
	{
		return inf;
	}
	else
	{
		return a[x];
	}
}

int main()
{
	long long i,p,z;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		fq[a[i]]++;
	}
	sort(a+1,a+n+1);
	p=n-m+1;
	z=val(p);
	for(i=ma;i;i--)
	{
		p+=fq[i];
		fq[i/2]+=fq[i];
		fq[(i+1)/2]+=fq[i];
		z=max(z,min(val(p),i/2));
	}
	z-=!z;
	printf("%lld\n",z);
}