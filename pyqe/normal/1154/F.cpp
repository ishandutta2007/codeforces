#include <bits/stdc++.h>

using namespace std;

long long n,m,d,a[200069],of[2069],ps[2069],nr[2069];

int main()
{
	long long i,j,k,l;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		if(k<=d)
		{
			of[k]=max(of[k],l);
		}
	}
	for(i=1;i<=d;i++)
	{
		ps[i]=ps[i-1]+a[i];
	}
	for(i=0;i<=d;i++)
	{
		nr[i]=1e18;
	}
	nr[d]=0;
	for(i=d;i;i--)
	{
		for(j=1;j<=i;j++)
		{
			nr[i-j]=min(nr[i-j],nr[i]+ps[i]-ps[i-j+of[j]]);
		}
	}
	printf("%lld\n",nr[0]);
}