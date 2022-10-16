#include <bits/stdc++.h>

using namespace std;

long long n,a[5069],as[5069],sq[5069];
bitset<5069> vtd;

int main()
{
	long long i,j,c;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		for(j=2;j*j<=abs(a[i]);j++)
		{
			for(;a[i]%(j*j)==0;a[i]/=j*j);
		}
		as[i]=a[i];
	}
	sort(as+1,as+n+1);
	for(i=1;i<=n;i++)
	{
		a[i]=lower_bound(as+1,as+n+1,a[i])-as;
	}
	for(i=1;i<=n;i++)
	{
		vtd.reset();
		c=0;
		for(j=i;j;j--)
		{
			c+=!vtd[a[j]]&&as[a[j]];
			vtd[a[j]]=1;
			sq[max(c,1ll)]++;
		}
	}
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==n]);
	}
}