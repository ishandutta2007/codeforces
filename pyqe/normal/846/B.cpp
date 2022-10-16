#include <bits/stdc++.h>

using namespace std;

long long n,m,d,a[1069];

int main()
{
	long long i,j,k,w,sm=0,z,mx=-1e18;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=1;i<=m;i++)
	{
		scanf("%lld",a+i);
		sm+=a[i];
	}
	sort(a+1,a+m+1);
	for(i=0;i<=n&&sm*i<=d;i++)
	{
		z=(m+1)*i;
		k=d-sm*i;
		for(j=1;j<=m;j++)
		{
			w=min(k/a[j],n-i);
			z+=w;
			k-=a[j]*w;
		}
		mx=max(mx,z);
	}
	printf("%lld\n",mx);
}