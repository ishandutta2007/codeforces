#include <bits/stdc++.h>

using namespace std;

long long n,m,nn=0,a[200069],sk[200069],dv=998244353;

int main()
{
	long long i,j,k,z=1;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		for(;nn&&a[i]<=a[sk[nn]];nn--);
		nn++;
		sk[nn]=i;
	}
	for(j=0,i=1;i<=m;i++)
	{
		scanf("%lld",&k);
		for(;j<nn&&a[sk[j+1]]<=k;j++);
		if(a[sk[j]]!=k||(i==1&&j!=1))
		{
			z=0;
		}
		if(i-1)
		{
			z=z*(sk[j]-sk[j-1])%dv;
		}
	}
	printf("%lld\n",z);
}