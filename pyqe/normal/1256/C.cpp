#include <bits/stdc++.h>

using namespace std;

long long n,m,d,a[1069],sq[1069];

int main()
{
	long long i,j,z=0,k,rm,c=0,kk;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=1;i<=m;i++)
	{
		scanf("%lld",a+i);
		z+=a[i];
	}
	k=(n-z)/(m+1);
	rm=(n-z)%(m+1);
	if(k+!!rm>=d)
	{
		printf("NO\n");
		return 0;
	}
	for(i=0;i<=m;i++)
	{
		for(j=0;j<a[i];j++)
		{
			sq[c]=i;
			c++;
		}
		kk=k;
		if(i<rm)
		{
			kk++;
		}
		for(j=0;j<kk;j++)
		{
			sq[c]=0;
			c++;
		}
	}
	printf("YES\n");
	for(i=0;i<n;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==n-1]);
	}
}