#include <bits/stdc++.h>

using namespace std;

long long n[2],t1,t2,d,a[2][200069];

int main()
{
	long long i,j,ii,mx=-1e18;
	
	scanf("%lld%lld%lld%lld%lld",n,n+1,&t1,&t2,&d);
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n[ii];i++)
		{
			scanf("%lld",&a[ii][i]);
			a[ii][i]+=t1*!ii+t2;
		}
		a[ii][n[ii]+1]=1e18;
	}
	for(j=1,i=1;i<=min(d,n[0])+1;i++)
	{
		for(;j<=n[1]&&a[1][j]<a[0][i];j++);
		mx=max(mx,a[1][min(j+d-i+1,n[1]+1)]);
	}
	if(mx==1000000000000000000)
	{
		mx=-1;
	}
	printf("%lld\n",mx);
}