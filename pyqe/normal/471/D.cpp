#include <bits/stdc++.h>

using namespace std;

long long n,m,aa[200069],a[200069],faf[200069];

int main()
{
	long long i,j,k,l=0,c=0,z=0;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<=n-1;i++)
	{
		scanf("%lld",&k);
		aa[i]=k-l;
		l=k;
	}
	for(i=0;i<=m-1;i++)
	{
		scanf("%lld",&k);
		a[i]=k-l;
		l=k;
	}
	faf[0]=-1;
	for(i=1;i<=m-1;i++)
	{
		for(j=faf[i-1];j+1&&a[j+1]!=a[i];j=faf[j]);
		faf[i]=j+1;
	}
	for(i=0;i<=n-1;i++)
	{
		if(i)
		{
			for(;c+1&&a[c+1]!=aa[i];c=faf[c]);
			c++;
		}
		if(c==m-1)
		{
			z++;
			c=faf[c];
		}
	}
	printf("%lld\n",z);
}