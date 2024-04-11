#include <bits/stdc++.h>

using namespace std;

long long n,a[69][2],m[2],w[2],ys,xs,d;

int main()
{
	long long i,j,ii,mx=0;
	
	scanf("%lld%lld%lld%lld%lld%lld",&a[1][0],&a[1][1],m,m+1,w,w+1);
	scanf("%lld%lld%lld",&ys,&xs,&d);
	for(n=2;1;n++)
	{
		for(ii=0;ii<2;ii++)
		{
			a[n][ii]=a[n-1][ii]*m[ii]+w[ii];
		}
		if(max(a[n][0],a[n][1])>=10000000000000000)
		{
			break;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(abs(ys-a[i][0])+abs(xs-a[i][1])+abs(a[i][0]-a[j][0])+abs(a[i][1]-a[j][1])<=d)
			{
				mx=max(mx,abs(i-j)+1);
			}
		}
		
	}
	printf("%lld\n",mx);
}