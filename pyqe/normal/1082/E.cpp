#include <bits/stdc++.h>

using namespace std;

long long n,d,a[500069],ps[500069],mx[500069],fq[500069];

int main()
{
	long long i,sm=0,z=-1e18;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=n;i;i--)
	{
		ps[i]=ps[i+1]+(a[i]==d);
	}
	for(i=1;i<=n;i++)
	{
		mx[a[i]]=max(mx[a[i]],sm-fq[a[i]]);
		fq[a[i]]++;
		z=max(z,mx[a[i]]+fq[a[i]]+ps[i+1]);
		sm+=a[i]==d;
	}
	printf("%lld\n",z);
}