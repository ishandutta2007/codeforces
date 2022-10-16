#include <bits/stdc++.h>

using namespace std;

long long n,m,nn=0,a[100069],aa[100069];

int main()
{
	long long i,j,k,l,w,mn=1e18;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	a[n+1]=1e9;
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		if(k==1)
		{
			nn++;
			aa[nn]=l;
		}
	}
	sort(aa+1,aa+nn+1);
	for(j=1,i=1;i<=n+1;i++)
	{
		for(;j<=nn&&aa[j]<a[i];j++);
		mn=min(mn,i+nn-j);
	}
	printf("%lld\n",mn);
}