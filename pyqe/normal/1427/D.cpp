#include <bits/stdc++.h>

using namespace std;

long long n,a[69],pst[69],sq[69],zs;

int main()
{
	long long i,j,k;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	if(n%2)
	{
		for(i=1;i<n+1-i;i++)
		{
			swap(a[i],a[n+1-i]);
		}
	}
	for(i=1;i<=n;i++)
	{
		pst[a[i]]=i;
	}
	printf("%lld\n",n-(a[n]==1));
	for(i=1;i<=n;i++)
	{
		zs=0;
		for(j=1;j<i;j++)
		{
			zs++;
			sq[zs]=1;
		}
		zs++;
		sq[zs]=pst[i]-i+1;
		for(j=pst[i]+1;j<=n;j++)
		{
			zs++;
			sq[zs]=1;
		}
		if((n+1-i)%2)
		{
			for(j=1;j<zs+1-j;j++)
			{
				swap(sq[j],sq[zs+1-j]);
			}
		}
		if(zs-1)
		{
			printf("%lld ",zs);
			for(j=1;j<=zs;j++)
			{
				printf("%lld%c",sq[j]," \n"[j==zs]);
			}
		}
		k=pst[i];
		for(j=i;j<k-(j-i);j++)
		{
			swap(a[j],a[k-(j-i)]);
			swap(pst[a[j]],pst[a[k-(j-i)]]);
		}
	}
}